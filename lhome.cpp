#include "lhome.h"
#include "ui_lhome.h"
#include "toastwidget.h"
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QFileDialog>
#include <QFontInfo>
#include <QFileInfo>
#include <QDir>
#include <QMessageBox>
#include <QSplitter>
#include <QTreeView>
#include <QFileSystemModel>
#include <QSizePolicy>
#include <QDebug>
#include <QTimer>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QUrl>
#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexercpp.h>
#include <vector>
#include <functional>
#include <utility>
using namespace std;
// =====================================================
//     CUSTOM LEXER: ADDS "TYPE" KEYWORDS (SET 2)
// =====================================================
// QsciLexer has no public setKeywords() — the only way to feed
// KeywordSet2 (used here for built-in types like int/bool/char)
// is to subclass and override the virtual keywords() method.
namespace
{
    class DragonCppLexer : public QsciLexerCPP
    {
    public:
        using QsciLexerCPP::QsciLexerCPP;
        const char *keywords(int set) const override
        {
            if (set == 2)
            {
                return
                    "bool char char8_t char16_t char32_t double float int long "
                    "short signed unsigned void wchar_t auto const constexpr "
                    "inline mutable static thread_local volatile size_t "
                    "int8_t int16_t int32_t int64_t uint8_t uint16_t uint32_t uint64_t";
            }
            return QsciLexerCPP::keywords(set);
        }
    };
}
// =====================================================
//                       CONSTRUCTOR
// =====================================================
Lhome::Lhome(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::Lhome)
{
    ui->setupUi(this);
    this->setWindowTitle("Ezu-Hub");
    // =================================================
    //                  CREATE EDITOR
    // =================================================
    // NOTE: the editor's background below uses a color with an
    // alpha channel, which Qt blends against whatever is already
    // painted behind it inside the window (a normal child-widget
    // effect, no special flags needed). We deliberately do NOT
    // mark the top-level window itself translucent — doing that
    // makes the WHOLE window (toolbar, buttons, title area, etc.)
    // dependent on the desktop compositor, and any part of the UI
    // without an explicit background turns invisible, letting the
    // desktop wallpaper show through everywhere instead of just
    // the editor.
    Editor = new QsciScintilla(this);
    // =================================================
    //                       FONT
    // =================================================
    QFont font("JetBrains Mono", 13);
    if (!QFontInfo(font).exactMatch())
    {
        font = QFont("DejaVu Sans Mono", 13);
    }
    // =================================================
    //                       LEXER
    // =================================================
    lexer = new DragonCppLexer(this);
    lexer->setDefaultFont(font);
    // =================================================
    //         AURORA COLOR PALETTE (NO MORE GREEN BG)
    // =================================================
    // Deep navy/purple background (Catppuccin-Mocha inspired)
    // instead of the old green tone. Editor background keeps a
    // light semi-transparent alpha. Every lexer category below,
    // INCLUDING punctuation/operators (parentheses, commas,
    // semicolons, brackets, etc. — Scintilla groups all of these
    // under one "Operator" style, there is no finer split), gets
    // its own clearly distinct color.
    const int   bgAlpha       = 170; // ~67% opacity -> "شبه شفاف"
    const QColor editorBg(30, 30, 46, bgAlpha);      // #1E1E2E navy/purple
    const QColor currentLine(49, 50, 68, bgAlpha);   // #313244
    const QColor lineNumberBg("#181825");            // margins stay solid for readability
    const QColor selectionBg("#45475A");
    const QColor white("#CDD6F4");
    // =================================================
    //                  DEFAULT STYLE
    // =================================================
    lexer->setDefaultColor(QColor("#CDD6F4"));
    lexer->setDefaultPaper(editorBg);
    lexer->setDefaultFont(font);
    // =================================================
    //     PER-CATEGORY COLOR TABLE (ALL UNIQUE COLORS)
    // =================================================
    const std::vector<std::pair<int, QColor>> styleColors = {
        // General text / variables
        { QsciLexerCPP::Default,                    QColor("#CDD6F4") }, // plain text
        { QsciLexerCPP::Identifier,                 QColor("#74C7EC") }, // variable names
        // Keywords
        { QsciLexerCPP::Keyword,                    QColor("#CBA6F7") }, // if/for/return/class...
        { QsciLexerCPP::KeywordSet2,                QColor("#F9E2AF") }, // built-in types (int, bool...)
        { QsciLexerCPP::GlobalClass,                QColor("#FAB387") }, // class / struct names
        // Comments
        { QsciLexerCPP::Comment,                    QColor("#6C7086") }, // /* block */
        { QsciLexerCPP::CommentLine,                QColor("#7F849C") }, // // line
        { QsciLexerCPP::CommentDoc,                 QColor("#9399B2") }, // /** doc block */
        { QsciLexerCPP::CommentLineDoc,              QColor("#A6ADC8") }, // /// doc line
        { QsciLexerCPP::CommentDocKeyword,           QColor("#F2CDCD") }, // @param, \brief...
        { QsciLexerCPP::CommentDocKeywordError,      QColor("#F38BA8") }, // malformed doc keyword
        // Strings
        { QsciLexerCPP::DoubleQuotedString,         QColor("#A6E3A1") }, // "text"
        { QsciLexerCPP::SingleQuotedString,         QColor("#94E2D5") }, // 'c'
        { QsciLexerCPP::UnclosedString,              QColor("#EBA0AC") }, // unterminated string
        { QsciLexerCPP::VerbatimString,              QColor("#F5E0DC") }, // C# @"..."
        { QsciLexerCPP::RawString,                   QColor("#F5C2E7") }, // C++11 R"(...)"
        { QsciLexerCPP::TripleQuotedVerbatimString,  QColor("#B4BEFE") }, // """..."""
        { QsciLexerCPP::HashQuotedString,            QColor("#89DCEB") }, // #"..."
        // Numbers
        { QsciLexerCPP::Number,                      QColor("#89B4FA") },
        // Preprocessor (this is what colors "#include")
        { QsciLexerCPP::PreProcessor,                QColor("#C4A7FF") }, // #include, #define -> violet
        { QsciLexerCPP::PreProcessorComment,         QColor("#9D7BD8") },
        { QsciLexerCPP::PreProcessorCommentLineDoc,  QColor("#E0D1FF") },
        // Operators / punctuation: ( ) , ; { } [ ] . : etc. — all
        // symbols in the code fall under this single style, so this
        // one warm amber color is what colors every comma/parenthesis.
        { QsciLexerCPP::Operator,                    QColor("#FFB454") },
        // Misc / rare styles
        { QsciLexerCPP::UUID,                        QColor("#BAC2DE") },
        { QsciLexerCPP::Regex,                       QColor("#FF6AC8") },
        { QsciLexerCPP::UserLiteral,                 QColor("#A78BFA") },
        { QsciLexerCPP::TaskMarker,                  QColor("#FF5D62") }, // TODO / FIXME
        { QsciLexerCPP::EscapeSequence,              QColor("#FFE066") }, // \n, \t, \\...
    };
    for (const auto &entry : styleColors)
    {
        lexer->setColor(entry.second, entry.first);
        lexer->setFont(font, entry.first);
    }
    // NOTE: KeywordSet2 (int/bool/char/void/etc., colored orange)
    // is now populated via the DragonCppLexer::keywords() override
    // defined above, since QsciLexer has no public setKeywords().
    // =================================================
    //                   APPLY LEXER
    // =================================================
    Editor->setFont(font);
    Editor->setLexer(lexer);
    Editor->setUtf8(true);
    // =================================================
    //                       TABS
    // =================================================
    Editor->setTabWidth(4);
    Editor->setIndentationsUseTabs(false);
    Editor->setAutoIndent(true);
    // =================================================
    //                    LINE NUMBERS
    // =================================================
    Editor->setMarginLineNumbers(
        0,
        true
    );
    Editor->setMarginWidth(
        0,
        "00000"
    );
    Editor->setMarginsBackgroundColor(
        lineNumberBg
    );
    Editor->setMarginsForegroundColor(
        QColor("#6C7086")
    );
    // =================================================
    //                    CURRENT LINE
    // =================================================
    Editor->setCaretLineVisible(true);
    Editor->setCaretLineBackgroundColor(
        currentLine
    );
    Editor->setCaretForegroundColor(
        QColor("#F5E0DC")
    );
    // =================================================
    //                     SELECTION
    // =================================================
    Editor->setSelectionBackgroundColor(
        selectionBg
    );
    Editor->setSelectionForegroundColor(
        white
    );
    // =================================================
    //                  BRACKET MATCHING
    // =================================================
    Editor->setBraceMatching(
        QsciScintilla::SloppyBraceMatch
    );
    Editor->setMatchedBraceBackgroundColor(
        QColor("#585B70")
    );
    Editor->setMatchedBraceForegroundColor(
        QColor("#F9E2AF")
    );
    // =================================================
    //                       FOLDING
    // =================================================
    Editor->setFolding(
        QsciScintilla::BoxedTreeFoldStyle
    );
    Editor->setFoldMarginColors(
        QColor("#181825"),
        QColor("#181825")
    );
    // =================================================
    //                    EDGE / GUIDE
    // =================================================
    Editor->setEdgeMode(
        QsciScintilla::EdgeLine
    );
    Editor->setEdgeColumn(100);
    Editor->setEdgeColor(
        QColor("#45475A")
    );
    // =================================================
    //                       CARET
    // =================================================
    Editor->setCaretWidth(2);
    // =================================================
    //                    EDITOR STYLE
    // =================================================
    Editor->setStyleSheet(
        "QsciScintilla {"
        "    background-color: rgba(30, 30, 46, 170);"
        "    color: #CDD6F4;"
        "    border: none;"
        "    outline: none;"
        "    selection-background-color: #45475A;"
        "    selection-color: #CDD6F4;"
        "}"
    );
    Editor->setPaper(editorBg);
    // =================================================
    //                 FILE SYSTEM MODEL
    // =================================================
    dirModel = new QFileSystemModel(this);
    dirModel->setFilter(
        QDir::AllDirs |
        QDir::Files |
        QDir::NoDotAndDotDot
    );
    // =================================================
    //                    TREE VIEW
    // =================================================
    treeView = new QTreeView(this);
    treeView->setModel(dirModel);
    treeView->setHeaderHidden(true);
    treeView->setColumnWidth(
        0,
        250
    );
    treeView->setAnimated(true);
    treeView->setIndentation(18);
    // =================================================
    //                 FILE TREE STYLE
    // =================================================
    treeView->setStyleSheet(
        "QTreeView {"
        "    background-color: #181825;"
        "    color: #BAC2DE;"
        "    border: none;"
        "    outline: 0;"
        "    font-family: 'JetBrains Mono';"
        "    font-size: 12px;"
        "}"
        ""
        "QTreeView::item {"
        "    padding: 5px;"
        "    border-radius: 4px;"
        "}"
        ""
        "QTreeView::item:hover {"
        "    background-color: #313244;"
        "    color: #F9E2AF;"
        "}"
        ""
        "QTreeView::item:selected {"
        "    background-color: #45475A;"
        "    color: #CBA6F7;"
        "}"
        ""
        "QTreeView::branch {"
        "    background-color: #181825;"
        "}"
    );
    // =================================================
    //                      SPLITTER
    // =================================================
    QSplitter *splitter =
        new QSplitter(
            Qt::Horizontal,
            this
        );
    splitter->addWidget(treeView);
    splitter->addWidget(Editor);
    splitter->setSizes(
        QList<int>() << 250 << 900
    );
    splitter->setStretchFactor(
        0,
        0
    );
    splitter->setStretchFactor(
        1,
        1
    );
    // =================================================
    //                 SPLITTER STYLE
    // =================================================
    splitter->setStyleSheet(
        "QSplitter::handle {"
        "    background-color: #45475A;"
        "    width: 2px;"
        "}"
        ""
        "QSplitter::handle:hover {"
        "    background-color: #CBA6F7;"
        "}"
    );
    // =================================================
    //                 ADD TO LAYOUT
    // =================================================
    ui->edo->addWidget(splitter);
    // =================================================
    //                 OPEN FILE FROM TREE
    // =================================================
    connect(
        treeView,
        &QTreeView::doubleClicked,
        this,
        &Lhome::onTreeFileClicked
    );
}
// =====================================================
//                    TREE FILE CLICKED
// =====================================================
void Lhome::onTreeFileClicked(
    const QModelIndex &index
)
{
    QString path =
        dirModel->filePath(index);
    QFileInfo info(path);
    if (info.isDir())
    {
        return;
    }
    QFile file(path);
    if (!file.open(
            QIODevice::ReadOnly |
            QIODevice::Text))
    {
        QMessageBox::warning(
            this,
            "Open Error",
            "Cannot open this file."
        );
        return;
    }
    QTextStream in(&file);
    QString code =
        in.readAll();
    file.close();
    Editor->setText(code);
    ui->file->setText(path);
}
// =====================================================
//                    CLOSE WINDOW
// =====================================================
void Lhome::on_pushButton_clicked()
{
    this->close();
}
// =====================================================
//                      OPEN FILE
// =====================================================
void Lhome::on_openFiles_clicked()
{
    QString folder =
        QFileDialog::getExistingDirectory(
            this,
            "Select Project Folder",
            QDir::homePath()
        );
    if (folder.isEmpty())
    {
        return;
    }
    // ==========================================
    // تحديث File Explorer
    // ==========================================
    dirModel->setRootPath(folder);
    treeView->setRootIndex(
        dirModel->index(folder)
    );
    // ==========================================
    // اختيار ملف
    // ==========================================
    QString fileName =
        QFileDialog::getOpenFileName(
            this,
            "Open C++ File",
            folder,
            "C++ Files (*.cpp *.c *.h *.hpp);;"
            "Text Files (*.txt);;"
            "All Files (*)"
        );
    if (fileName.isEmpty())
    {
        return;
    }
    // ==========================================
    // فتح الملف
    // ==========================================
    QFile file(fileName);
    if (!file.open(
            QIODevice::ReadOnly |
            QIODevice::Text))
    {
        QMessageBox::critical(
            this,
            "Open Error",
            "Cannot open the selected file."
        );
        return;
    }
    QTextStream in(&file);
    QString code =
        in.readAll();
    file.close();
    // ==========================================
    // وضع الكود
    // ==========================================
    Editor->setText(code);
    // ==========================================
    // وضع المسار
    // ==========================================
    ui->file->setText(fileName);
    // ==========================================
    // تحديد الملف في Explorer
    // ==========================================
    QModelIndex index =
        dirModel->index(fileName);
    if (index.isValid())
    {
        treeView->setCurrentIndex(index);
        treeView->scrollTo(index);
    }
}
// =====================================================
//                       RUN CODE
// =====================================================
void Lhome::on_RunCode_clicked()
{
    QString code =
        Editor->text();
    if (code.trimmed().isEmpty())
    {
        QMessageBox::warning(
            this,
            "Run Code",
            "The editor is empty."
        );
        return;
    }
    // ==========================================
    // اسم الملف
    // ==========================================
    QString fileName =
        ui->file->text();
    if (fileName.isEmpty())
    {
        fileName =
            QDir::homePath() +
            "/untitled.cpp";
    }
    if (!fileName.endsWith(
            ".cpp",
            Qt::CaseInsensitive))
    {
        fileName += ".cpp";
    }
    // ==========================================
    // حفظ الكود
    // ==========================================
    QFile file(fileName);
    if (!file.open(
            QIODevice::WriteOnly |
            QIODevice::Text))
    {
        QMessageBox::critical(
            this,
            "Save Error",
            "Cannot save the C++ file."
        );
        return;
    }
    QTextStream out(&file);
    out << code;
    file.close();
    // ==========================================
    // معلومات الملف
    // ==========================================
    QFileInfo info(fileName);
    // ==========================================
    // اسم البرنامج
    // ==========================================
    QString outputFile =
        info.absolutePath() +
        "/program";
    // ==========================================
    // COMPILER
    // ==========================================
    QProcess compiler;
    QStringList compileArgs;
    compileArgs
        << fileName
        << "-std=c++17"
        << "-o"
        << outputFile;
    // ==========================================
    // تشغيل clang++
    // ==========================================
    compiler.start(
        "clang++",
        compileArgs
    );
    if (!compiler.waitForStarted(3000))
    {
        QMessageBox::critical(
            this,
            "Compiler Error",
            "clang++ was not found.\n\n"
            "Install it using:\n"
            "sudo apt install clang"
        );
        return;
    }
    // ==========================================
    // انتظار انتهاء Compilation
    // ==========================================
    compiler.waitForFinished(-1);
    // ==========================================
    // قراءة Error
    // ==========================================
    QString error =
        QString::fromLocal8Bit(
            compiler.readAllStandardError()
        );
    // ==========================================
    // Compilation Failed
    // ==========================================
    if (compiler.exitCode() != 0)
    {
        QMessageBox::critical(
            this,
            "Compilation Error",
            error
        );
        return;
    }
    // ==========================================
    // إعطاء صلاحيات التنفيذ
    // ==========================================
    QFile::setPermissions(
        outputFile,
        QFileDevice::ReadOwner |
        QFileDevice::WriteOwner |
        QFileDevice::ExeOwner |
        QFileDevice::ReadGroup |
        QFileDevice::ExeGroup |
        QFileDevice::ReadOther |
        QFileDevice::ExeOther
    );
    // ==========================================
    // تشغيل XTERM
    // ==========================================
    QString workingDirectory =
        info.absolutePath();
    QString command =
        QString(
            "cd \"%1\" && ./program"
        )
        .arg(workingDirectory);
    // ==========================================
    // Terminal Arguments
    // ==========================================
    QStringList terminalArgs;
    terminalArgs
        << "-T"
        << "Ezu-Hub C++ Program"
        << "-geometry"
        << "100x30+350+150"
        << "-fa"
        << "JetBrains Mono"
        << "-fs"
        << "12"
        << "-e"
        << "bash"
        << "-c"
        << command +
           "; echo '';"
           "echo '================================';"
           "echo 'Program finished.';"
           "echo '================================';"
           "exec bash";
    // ==========================================
    // فتح Terminal
    // ==========================================
    bool started =
        QProcess::startDetached(
            "xterm",
            terminalArgs
        );
    if (!started)
    {
        QMessageBox::critical(
            this,
            "Terminal Error",
            "Could not open XTerm.\n\n"
            "Install it using:\n"
            "sudo apt install xterm"
        );
    }
}
// =====================================================
//                         EXIT
// =====================================================
void Lhome::on_Exit_clicked()
{
    this->close();
}
// =====================================================
//                     NEW FILE
// =====================================================
void Lhome::on_new_2_clicked()
{
    Editor->setText(
        "// Ezu-Hub C++ Editor\n\n"
        "#include <iostream>\n\n"
        "using namespace std;\n\n"
        "int main()\n"
        "{\n"
        "    \n"
        "    return 0;\n"
        "}\n"
    );
    ui->file->clear();
}
// =====================================================
//                         SAVE
// =====================================================
void Lhome::on_CCL_clicked()
{
    QString fileName =
        ui->file->text();
    // ==========================================
    // إذا لم يوجد ملف
    // ==========================================
    if (fileName.isEmpty())
    {
        fileName =
            QFileDialog::getSaveFileName(
                this,
                "Save C++ File",
                QDir::homePath(),
                "C++ Files (*.cpp)"
            );
        if (fileName.isEmpty())
        {
            return;
        }
        if (!fileName.endsWith(
                ".cpp",
                Qt::CaseInsensitive))
        {
            fileName += ".cpp";
        }
        ui->file->setText(fileName);
    }
    // ==========================================
    // حفظ
    // ==========================================
    QFile file(fileName);
    if (!file.open(
            QIODevice::WriteOnly |
            QIODevice::Text))
    {
        QMessageBox::critical(
            this,
            "Save Error",
            "Cannot save the file."
        );
        return;
    }
    QTextStream out(&file);
    out << Editor->text();
    file.close();
}
// =====================================================
//                     CLEAR EDITOR
// =====================================================
void Lhome::on_clear_clicked()
{
    Editor->clear();
}
// =====================================================
//                         TECK
// =====================================================
void Lhome::teck()
{
}
// =====================================================
//                  ASK SERVER
// =====================================================
void Lhome::LoopAskingSever()
{
    ui->pushButton_Ask->setEnabled(false);
    ui->pushButton_Ask->setText(
        "Loading..."
    );
    manager =
        new QNetworkAccessManager(this);
    QNetworkRequest request(
        QUrl(
            "http://127.0.0.1:8000/AskForMisseions"
        )
    );
    request.setHeader(
        QNetworkRequest::ContentTypeHeader,
        "application/json"
    );
    QNetworkReply *reply =
        manager->get(request);
    connect(
        reply,
        &QNetworkReply::finished,
        this,
        [reply, this]()
        {
            ui->pushButton_Ask->setEnabled(
                true
            );
            ui->pushButton_Ask->setText(
                "Ask Again"
            );
            if (
                reply->error()
                ==
                QNetworkReply::NoError
            )
            {
                QByteArray response =
                    reply->readAll();
                QJsonDocument doc =
                    QJsonDocument::fromJson(
                        response
                    );
                if (!doc.isNull())
                {
                    QJsonObject res =
                        doc.object();
                    QString Code =
                        res["code"].toString();
                    QString LenOfMess =
                        res["num"].toString();
                    QString Messi =
                        res["task"].toString();
                    if (Code == "200")
                    {
                        ToastWidget::showToast(
                            this,
                            Messi,
                            2000
                        );
                        AllTask.push_back(
                            Messi
                        );
                    }
                }
            }
            else
            {
                qDebug()
                    << "Network Error:"
                    << reply->errorString();
                QMessageBox::warning(
                    this,
                    "Error",
                    "Server not responding"
                );
            }
            reply->deleteLater();
        }
    );
}
// =====================================================
//                       DESTRUCTOR
// =====================================================
Lhome::~Lhome()
{
    delete ui;
}
// =====================================================
//                    ASK BUTTON
// =====================================================
void Lhome::on_pushButton_Ask_clicked()
{
    LoopAskingSever();
}
// =====================================================
//                     GIVE TASK
// =====================================================
void Lhome::on_Give_clicked()
{
    QString From = "niga";
    QString To = "nono";
    QString Task =
        ui->taskEdit->text();
    QNetworkAccessManager *manager =
        new QNetworkAccessManager(this);
    QNetworkRequest request(
        QUrl(
            "http://127.0.0.1:8000/GiveMisseions"
        )
    );
    request.setHeader(
        QNetworkRequest::ContentTypeHeader,
        "application/json"
    );
    QJsonObject json;
    json["FROM"] = From;
    json["TO"] = To;
    json["TASK"] = Task;
    QByteArray data =
        QJsonDocument(json).toJson();
    QNetworkReply *reply =
        manager->post(
            request,
            data
        );
    connect(
        reply,
        &QNetworkReply::finished,
        this,
        [reply, this]()
        {
            QByteArray response =
                reply->readAll();
            QJsonDocument doc =
                QJsonDocument::fromJson(
                    response
                );
            QJsonObject res =
                doc.object();
            QString code =
                res["code"].toString();
            qDebug()
                << code;
            reply->deleteLater();
            if (code == "200")
            {
                QMessageBox::information(
                    this,
                    "Info",
                    "You give task to"
                );
            }
            else
            {
                QMessageBox::warning(
                    this,
                    "Warning",
                    "Problem in give task"
                );
            }
        }
    );
}
// =====================================================
//                       ALL TASK
// =====================================================
void Lhome::on_AllTask_clicked()
{
    qDebug()
        << AllTask.size();
    QMessageBox::information(
        this,
        "Info",
        "Run"
    );
    if (!AllTask.empty())
    {
        int high = 70;
        for (
            int t = 0;
            t < AllTask.size();
            ++t
        )
        {
            ToastWidget::showToast(
                this,
                AllTask.at(t),
                2000,
                high
            );
            high -= 70;
            qDebug()
                << AllTask.at(t);
        }
    }
    else
    {
        QMessageBox::information(
            this,
            "Info",
            "No task"
        );
    }
}