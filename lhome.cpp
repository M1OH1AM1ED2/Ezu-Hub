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

#include <vector>

#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexercpp.h>

#include <QMessageBox>
#include <QDebug>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QUrl>


#include <QTimer>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <functional> 

using namespace std ;
    

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
    lexer = new QsciLexerCPP(this);
    lexer->setDefaultFont(font);
    // =================================================
    //                   EDITOR COLORS
    // =================================================
    const QColor editorBg("#1E2227");
    const QColor currentLine("#252A31");
    const QColor lineNumberBg("#181B20");

    const QColor normalText("#61AFEF");
    const QColor identifier("#E6E6E6");

    const QColor keyword("#C678DD");
    const QColor keyword2("#56B6C2");

    const QColor comment("#5C6370");

    const QColor stringColor("#98C379");

    const QColor number("#D19A66");

    const QColor preprocessor("#E06C75");

    const QColor operatorColor("#56B6C2");

    const QColor classColor("#61AFEF");

    const QColor selectionBg("#354052");

    const QColor white("#FFFFFF");
    // =================================================
    //                  DEFAULT STYLE
    // =================================================
    lexer->setDefaultColor(normalText);
    lexer->setDefaultPaper(editorBg);
    lexer->setDefaultFont(font);
    // =================================================
    //                    NORMAL TEXT
    // =================================================
    lexer->setColor(
        normalText,
        QsciLexerCPP::Default
    );
    lexer->setFont(
        font,
        QsciLexerCPP::Default
    );
    // =================================================
    //                     VARIABLES
    // =================================================
    lexer->setColor(
        identifier,
        QsciLexerCPP::Identifier
    );
    lexer->setFont(
        font,
        QsciLexerCPP::Identifier
    );
    // =================================================
    //                      KEYWORDS
    // =================================================
    lexer->setColor(
        keyword,
        QsciLexerCPP::Keyword
    );
    lexer->setFont(
        font,
        QsciLexerCPP::Keyword
    );
    // =================================================
    //                 SECONDARY KEYWORDS
    // =================================================
    lexer->setColor(
        keyword2,
        QsciLexerCPP::KeywordSet2
    );
    lexer->setFont(
        font,
        QsciLexerCPP::KeywordSet2
    );
    // =================================================
    //                       CLASSES
    // =================================================
    lexer->setColor(
        classColor,
        QsciLexerCPP::GlobalClass
    );
    lexer->setFont(
        font,
        QsciLexerCPP::GlobalClass
    );
    // =================================================
    //                      COMMENTS
    // =================================================
    lexer->setColor(
        comment,
        QsciLexerCPP::Comment
    );
    lexer->setColor(
        comment,
        QsciLexerCPP::CommentLine
    );
    lexer->setFont(
        font,
        QsciLexerCPP::Comment
    );
    lexer->setFont(
        font,
        QsciLexerCPP::CommentLine
    );
    // =================================================
    //                       STRINGS
    // =================================================
    lexer->setColor(
        stringColor,
        QsciLexerCPP::DoubleQuotedString
    );
    lexer->setColor(
        stringColor,
        QsciLexerCPP::SingleQuotedString
    );
    lexer->setFont(
        font,
        QsciLexerCPP::DoubleQuotedString
    );
    lexer->setFont(
        font,
        QsciLexerCPP::SingleQuotedString
    );
    // =================================================
    //                       NUMBERS
    // =================================================
    lexer->setColor(
        number,
        QsciLexerCPP::Number
    );
    lexer->setFont(
        font,
        QsciLexerCPP::Number
    );
    // =================================================
    //                     PREPROCESSOR
    // =================================================
    lexer->setColor(
        preprocessor,
        QsciLexerCPP::PreProcessor
    );
    lexer->setFont(
        font,
        QsciLexerCPP::PreProcessor
    );
    // =================================================
    //                      OPERATORS
    // =================================================
    lexer->setColor(
        operatorColor,
        QsciLexerCPP::Operator
    );
    lexer->setFont(
        font,
        QsciLexerCPP::Operator
    );
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
        QColor("#636D83")
    );
    // =================================================
    //                    CURRENT LINE
    // =================================================
    Editor->setCaretLineVisible(true);
    Editor->setCaretLineBackgroundColor(
        currentLine
    );
    Editor->setCaretForegroundColor(
        white
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
        QColor("#303642")
    );
    Editor->setMatchedBraceForegroundColor(
        normalText
    );
    // =================================================
    //                       FOLDING
    // =================================================
    Editor->setFolding(
        QsciScintilla::BoxedTreeFoldStyle
    );
    Editor->setFoldMarginColors(
        QColor("#181B20"),
        QColor("#181B20")
    );
    // =================================================
    //                    EDGE / GUIDE
    // =================================================
    Editor->setEdgeMode(
        QsciScintilla::EdgeLine
    );
    Editor->setEdgeColumn(100);
    Editor->setEdgeColor(
        QColor("#2B3038")
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
        "    background-color: #1E2227;"
        "    color: #61AFEF;"
        "    border: none;"
        "    outline: none;"
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
    // ===================================
==============
    treeView = new QTreeView(this);
    treeView->setModel(dirModel);
    treeView->setHeaderHidden(true);
    treeView->setColumnWidth(
        0,
        220
    );
    treeView->setAnimated(true);
    treeView->setIndentation(18);
    treeView->setStyleSheet(
        "QTreeView {"
        "    background-color: #1E2227;"
        "    color: #E6E6E6;"
        "    border: none;"
        "    outline: 0;"
        "}"
        ""
        "QTreeView::item {"
        "    padding: 4px;"
        "}"
        ""
        "QTreeView::item:hover {"
        "    background-color: #0d53b4;"
        "}"
        ""
        "QTreeView::item:selected {"
        "    background-color: #303642;"
        "    color: #FFFFFF;"
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
    splitter->setStyleSheet(
        "QSplitter::handle {"
        "    background-color: #181B20;"
        "    width: 2px;"
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
    // إذا كان مجلدًا
    if (info.isDir())
    {
        return;
    }
    // ==========================================
    // فتح الملف
    // ==========================================
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
    // ==========================================
    // وضع الكود في Editor
    // ==========================================
    Editor->setText(code);
    // ==========================================
    // حفظ المسار
    // ==========================================
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
    // ==========================================
    // اختيار مجلد المشروع
    // ==========================================
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
    // ==========================================
    // أخذ الكود
    // ==========================================
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
    // ==========================================
    // clang++ غير موجود
    // ==========================================
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
        // حجم النافذة ومكانها
        << "-geometry"
        << "100x30+350+150"
        // الخط
        << "-fa"
        << "JetBrains Mono"
        << "-fs"
        << "12"
        // Bash حتى يعمل cin بشكل طبيعي
        << "-e"
        << "bash"
        << "-c"
        // تشغيل البرنامج ثم إبقاء Terminal مفتوحًا
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
    // ==========================================
    // Terminal Error
    // ==========================================
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
    // إذا لم يوجد ملف، اطلب مكان الحفظ
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
    // =========================================
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
//   CLEAR EDITOR
void Lhome::on_clear_clicked()
{
    Editor->clear();
}
void Lhome::teck(){
    
}
void Lhome::LoopAskingSever()
{
    ui->pushButton_Ask->setEnabled(false); 
    ui->pushButton_Ask->setText("Loading...");
    manager = new QNetworkAccessManager(this);
    QNetworkRequest request(QUrl("http://127.0.0.1:8000/AskForMisseions"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    
    QNetworkReply *reply = manager->get(request);
    
    connect(reply, &QNetworkReply::finished, this, [reply, this]() { 
        ui->pushButton_Ask->setEnabled(true); // رجع الزر
        ui->pushButton_Ask->setText("Ask Again");

        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response = reply->readAll();
            QJsonDocument doc = QJsonDocument::fromJson(response);
            if (!doc.isNull()) {
                QJsonObject res = doc.object();
                QString Code = res["code"].toString();
                QString LenOfMess = res["num"].toString();
                QString Messi = res["task"].toString();
                
                if (Code == "200"){
                   
                    ToastWidget::showToast(
                        this,
                        Messi,
                        2000
                        
                    );
                    AllTask.push_back(Messi);
                }
            }
        } else {
            qDebug() << "Network Error:" << reply->errorString();
            QMessageBox::warning(this, "Error", "Server not responding");
        }
        reply->deleteLater();
    });
}

// =====================================================
//                       DESTRUCTOR
// =====================================================

Lhome::~Lhome()
{
    delete ui;
}
void Lhome::on_pushButton_Ask_clicked()
{
    LoopAskingSever();
}

void Lhome::on_Give_clicked()
{
  QString From= "niga";
  QString To = "nono";
  QString Task = ui-> taskEdit -> text();
  QNetworkAccessManager *manager = new QNetworkAccessManager(this);
  QNetworkRequest request(
      QUrl("http://127.0.0.1:8000/GiveMisseions")
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
      manager->post(request, data);
  connect(reply, &QNetworkReply::finished,this, [reply,this]()
          {
            QByteArray response = reply->readAll();
            QJsonDocument doc = QJsonDocument::fromJson(response);
            QJsonObject res = doc.object();
            QString code = res["code"].toString();
            qDebug() << code ;
	    reply->deleteLater();
	    if (code == "200")
	    {
	      QMessageBox::information(this," info "," you give task to ");
	    }
	    else
	    {
	      QMessageBox::warning(this," warning "," problem in give task ");
	    }
	  });
}
void Lhome::on_AllTask_clicked()
{
    qDebug() << AllTask.size();

    QMessageBox::information(this, "Info", "Run");

    if (!AllTask.empty()) {
        int high = 70;

        for (int t = 0; t < AllTask.size(); ++t) {
            ToastWidget::showToast(
                this,
                AllTask.at(t),
                2000,
                high
            );
            high -= 70;
            qDebug() << AllTask.at(t);
        }
    } else {
        QMessageBox::information(this, "Info", "No task");
    }
}


