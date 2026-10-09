#include "lhome.h" 
#include "ui_lhome.h"
#include "toastwidget.h"
#include "error.h"
#include "checkwindow.h"
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
#include <thread>
#include <QDebug>
#include "sqlite.h"
#include <sqlite3.h>
#include <string>
#include <QSoundEffect>
using namespace std;
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
    
    database();
    
    RedyData();

    SQLite ParamiterDataBase ;
    
     if(!ParamiterDataBase.openDatabase("Paramiter.db"))
    {
        qDebug() << "------------------ dataBase not open 76 ";
        }
        
        int FontSize = 16;
        
        int TabSpace = 4;

        QString FontFamily = "Liberation Mono";
        
        qDebug() << "--------------------------| " << FontFamily;

        //SetParamiter(autoSave);
    // =================================================
    //                  CREATE EDITOR
    // =================================================

    Editor = new QsciScintilla(this);
    // CCONSTRUCTORs 
    manager = new QNetworkAccessManager(this);
    // =================================================
    //                       FONT
    // =================================================
    QFont font(FontFamily, FontSize);
    if (!QFontInfo(font).exactMatch())
    {
        font = QFont(FontFamily,FontSize);
    }
    // =================================================
    //                       LEXER
    // =================================================
    lexer = new DragonCppLexer(this);
    lexer->setDefaultFont(font);
    // =================================================
    //         AURORA COLOR PALETTE (NO MORE GREEN BG)
    // =================================================
  
    const int   bgAlpha       = 170; // ~67% opacity 
    const QColor editorBg(30, 30, 46, bgAlpha);      // #1E1E2E navy/purple
    const QColor currentLine("#1c468100");   // #01dcbb
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
        { QsciLexerCPP::Identifier,                 QColor("#00acfc") }, // variable names
        // Keywords
        { QsciLexerCPP::Keyword,                    QColor("#ff07c5") }, // if/for/return/class...
        { QsciLexerCPP::KeywordSet2,                QColor("#F9E2AF") }, // built-in types (int, bool...)
        { QsciLexerCPP::GlobalClass,                QColor("#FAB387") }, // class / struct names
        // Comments
        { QsciLexerCPP::Comment,                    QColor("#6C7086") }, // /* block */
        { QsciLexerCPP::CommentLine,                QColor("#1db937") }, // // line
        { QsciLexerCPP::CommentDoc,                 QColor("#9399B2") }, // /** doc block */
        { QsciLexerCPP::CommentLineDoc,              QColor("#A6ADC8") }, // /// doc line
        { QsciLexerCPP::CommentDocKeyword,           QColor("#F2CDCD") }, // @param, \brief...
        { QsciLexerCPP::CommentDocKeywordError,      QColor("#F38BA8") }, // malformed doc keyword
        // Strings
        { QsciLexerCPP::DoubleQuotedString,         QColor("#ed8200") }, // "text"
        { QsciLexerCPP::SingleQuotedString,         QColor("#94E2D5") }, // 'c'
        { QsciLexerCPP::UnclosedString,              QColor("#EBA0AC") }, // unterminated string
        { QsciLexerCPP::VerbatimString,              QColor("#F5E0DC") }, // C# @"..."
        { QsciLexerCPP::RawString,                   QColor("#F5C2E7") }, // C++11 R"(...)"
        { QsciLexerCPP::TripleQuotedVerbatimString,  QColor("#B4BEFE") }, // """..."""
        { QsciLexerCPP::HashQuotedString,            QColor("#89DCEB") }, // #"..."
        // Numbers
        { QsciLexerCPP::Number,                      QColor("#a1fa89") },
        // Preprocessor (this is what colors "#include")
        { QsciLexerCPP::PreProcessor,                QColor("#ff1515") }, // #include, #define -> violet
        { QsciLexerCPP::PreProcessorComment,         QColor("#9D7BD8") },
        { QsciLexerCPP::PreProcessorCommentLineDoc,  QColor("#E0D1FF") },
        // Operators / punctuation: ( ) , ; { } [ ] . : etc. — all
        // symbols in the code fall under this single style, so this
        // one warm amber color is what colors every comma/parenthesis.
        { QsciLexerCPP::Operator,                    QColor("#fff154") },
        // Misc / rare styles
        { QsciLexerCPP::UUID,                        QColor("#BAC2DE") },
        { QsciLexerCPP::Regex,                       QColor("#FF6AC8") },
        { QsciLexerCPP::UserLiteral,                 QColor("#A78BFA") },   
        { QsciLexerCPP::TaskMarker,                  QColor("#FF5D62") }, // TODO / FIXME
        { QsciLexerCPP::EscapeSequence,              QColor("#ff31b4") }, // \n, \t, \\...
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
    Editor->setTabWidth(TabSpace);
    Editor->setIndentationsUseTabs(false);
    Editor->setAutoIndent(true);
 // =================================================
//                  LINE NUMBERS
// =================================================
  Editor->setMarginLineNumbers(
        0,
        true
    );
    Editor->setMarginWidth(
        0,
        "0000000"
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
        "    font-family: 'Liberation Mono';"
        "    font-size: 14px;"
        "    padding: 4px;"
        "}"
        ""
        "QTreeView::item {"
        "    padding: 6px;"
        "    border-radius: 4px;"
        "}"
        ""
        "QTreeView::item:hover {"
        "    background-color:rgb(53, 132, 228);"
        "    color:rgb(255, 255, 255);"
        "    padding: 8px;           "
        "}"
        ""
        "QTreeView::item:selected {"
        "    background-color: rgb(224, 27, 36);"
        "    color: rgb(255, 255, 255);"
        "    font-size: 37px;         "
       "     padding: 10px; "
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

    loadSession();

   
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

//-------------------------------------------------------------------OPEN FILE-----------------

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
    
    QString currentFolderPath = folder ;
    
    QString currentFilePath = fileName ;
    
    saveSession(currentFolderPath,currentFilePath);
}

// =====================================================
//                       RUN CODE
// =====================================================
void Lhome::on_RunCode_clicked()
{
    Select_Paramiter_Of_Runing_Longuge_File_On_RunButton();
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
 
"//Code C++ Editor \n\n "

"#include <iostream> // include of liberary to can do input and output \n\n "

"using namespace std; // using name space of std instand of std:: \n\n "

"int main() // call Fonctions of Start program  \n\n"

"{ // open tag of Fonction and place to type screpet  \n\n"

"    int number = 2027 ; // creet vairabol content number \n\n " 

"   int *pointer = &number ; // creet ponter (adress memory) for vairabol number \n\n"

"    cout << number <<endl; // print value of vairabol number \n\n"

"    cout << &pointer <<endl; // print value of ponter number \n\n"

"    return 0;       // finish programe  \n\n "
 
"} // closing tag of fonction  \n\n"
    );
    ui->file->clear();
}
// =====================================================
//                         SAVE
// =====================================================
void Lhome::on_CCL_clicked()
{
    QString fileName = ui->file->text(); 
    
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
                "C++ Files (*.txt)"
            );
        if (fileName.isEmpty())
        {
            return;
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
//                         checkAPI
// =====================================================
void Lhome::checkAPI()

{
    QNetworkRequest request(
        QUrl("http://127.0.0.1:8000/AskForMisseions")
    );

    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished,
            this, [this, reply]()
    {
        if (reply->error() == QNetworkReply::NoError)
        {
            QByteArray response = reply->readAll();

            QJsonDocument doc =
                QJsonDocument::fromJson(response);

            if (!doc.isNull())
            {
                QJsonObject res = doc.object();

                QString code =
                    res["code"].toString();

                QString message =
                    res["task"].toString();

                qDebug() << code;
                qDebug() << message;
                if (code == "200")
                        {
                            ToastWidget::showToast(
                                this,
                                message,
                                2000
                            );
                            AllTask.push_back(
                                message
                            );
                        }   
            }
        }
        else
        {
            qDebug() << "Network Error:"
                    << reply->errorString();
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
// =====================================================
//                     GIVE TASK
// =====================================================
void Lhome::on_Give_clicked()
{
    QString From = "niga";
    QString To = "nono";
    QString Task = ui-> taskEdit-> text();
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
                qDebug() << "work";
                
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
        int time = 300;
        for (
            int t = 0;
            t < AllTask.size();
            ++t
        )
        {
            ToastWidget::showToast(
                this,
                AllTask.at(t),
                2000 - time,
                high
            );
            high -= 120;
            time = time - 300;
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
// ================================================
//                  trminal
// =================================================
void Lhome::on_terminal_clicked()
{
    qDebug()<<"terminal is runing :";
    QString command =
        QString(
            "cd /home/Desktop/C++/Ezu-Hub/"
        );
    QStringList Args;
    Args
        << "-T"
        << "Ezu-Hub C++ Program"
        << "-geometry"
        << "100x30+350+150"
        << "-fa"
        << "JetBrains Mono"
        << "-fs"
        << "12"
        << "-e"
        << "exec bash";
    bool started =
        QProcess::startDetached(
            "xterm",
            Args
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
//==========================================================================|
//                          paramiter                                       |
//==========================================================================|

void Lhome::SetParamiter(QString autoSave){
    
  
}
      
void Lhome::save(){
    
    QString compennet = Editor->text();
    
    if (compennet.trimmed().isEmpty()){
        
        qDebug() << " nothing to save him  " ;
        
        return;
    }
    // ==========================================
    // إذا لم يوجد ملف
    // ==========================================
    QString fileName ;
    
    QString ABSpath =  QDir::homePath() += "/Desktop/";
    
    if (ABSpath.isEmpty()){
        
     QString path = QDir::homePath() += "/Desktop/";
        
    fileName = path+="Defult.txt";
        
    }else{
        
        fileName = ui->file->text();
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

void Lhome::on_Notificatoins(){
    
    SQLite ParamiterDataBase ;
    
     if(!ParamiterDataBase.openDatabase("Paramiter.db"))
    {
        qDebug() << "------------------ dataBase not open +870 | lh.ccp ";
        }

    QString Notificatoins = QString::fromStdString(ParamiterDataBase.getSetting("notificatoins"));
    
    qDebug() << Notificatoins ;
    
    if (Notificatoins == "Enable"){
        qDebug () << "notificatoins runing " ;
        RunTime = new QTimer(this);
        connect(RunTime,&QTimer::timeout,this, &Lhome::checkAPI);
        RunTime->start(4000);
    }
    else {
        
        RunTime->stop();
    }
}
    
void Lhome::Select_Paramiter_Of_Runing_Longuge_File_On_RunButton(){// =----------- Methode To Select Runer -----------=
    
    SQLite ParamiterDataBase ;
    
     if(!ParamiterDataBase.openDatabase("Paramiter.db"))
    {
        qDebug() << "------------------ dataBase not open +890 | lh.ccp ";
        }

    QString devlong = QString::fromStdString(ParamiterDataBase.getSetting("devlong"));
    
    qDebug() << devlong ;
    
    if (devlong == "C++"){
        
        Code_C_Plus_Plus_Runer();
        
        }
}

    
void Lhome::Code_C_Plus_Plus_Runer(){ // =-------------- C++ Methode To run Code -----------------=
       
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
    QString fileName =
        ui->file->text();
    if (fileName.isEmpty())
    {
        fileName =
            QDir::homePath() +
            "/Desktop/untitled.cpp";
    }
    if (!fileName.endsWith(
            ".cpp",
            Qt::CaseInsensitive))
    {
        fileName += ".cpp";
    }
    // ------------Save File --------------
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

void Lhome::on_ERROR_2_clicked(){ // --------------------------------------------------- Error Button -------------
    
    qDebug() << "-----------------------[+] ERROR FOUND [+]----------->" ;

    ERROR *R = new ERROR();
                      
    R->show();
    
    return;

    }

  //==================================================
 //                  database Editor 
//====================================================
void Lhome::database(){
    
        sqlite3* db = nullptr;
    
        int result = sqlite3_open("Editor_Database.db",&db);

        if (result != SQLITE_OK){

            qDebug ()<< "databse of path not runing";

            sqlite3_close(db);
            return;
        }

        qDebug ()<< "databse runing";

        const char* sqlQuery = R"(CREATE TABLE IF NOT EXISTS editor_session (id INTEGER PRIMARY KEY ,folder_path TEXT NOT NULL,file_path TEXT );)";

        char* ErrorSql = nullptr;

        int creat = sqlite3_exec(db,sqlQuery,nullptr,nullptr,&ErrorSql );

        if (creat != SQLITE_OK){

            qDebug ()<< ErrorSql ;
        }

        else {

            qDebug ()<< "databse of path created ";
        }   
    }

void Lhome::saveSession(QString currentFolderPath, QString currentFilePath){
    
    sqlite3* db = nullptr;
    
    int man = sqlite3_open("Editor_Database.db",&db);

        if (man != SQLITE_OK){

            qDebug ()<< "databse of path not runing";

            sqlite3_close(db);
            return;
        }
    if (db == nullptr)
    {
        return;
    }
    const char* sql =
        "INSERT OR REPLACE INTO editor_session"
        "(id, folder_path, file_path) "
        "VALUES (?, ?, ?);";

    sqlite3_stmt* statement;

    int result =
        sqlite3_prepare_v2(
            db,
            sql,
            -1,
            &statement,
            nullptr
        );
    if (result != SQLITE_OK)
    {
        qDebug()
            << "Prepare Error:"
            << sqlite3_errmsg(db);

        sqlite3_close(db);
        return;
    }
    sqlite3_bind_int(
        statement,
        1,
        1
    );
    sqlite3_bind_text(
        statement,
        2,
        currentFolderPath.toUtf8().constData(),
        -1,
        SQLITE_TRANSIENT
    );

    sqlite3_bind_text(
        statement,
        3,
        currentFilePath.toUtf8().constData(),
        -1,
        SQLITE_TRANSIENT
    );
    result =
        sqlite3_step(statement);

    if (result != SQLITE_DONE)
    {
        qDebug()
            << "Save Error:"
            << sqlite3_errmsg(db);
    }
    else
    {
        qDebug()
            << "Session Saved to data base  --------------> database 200 OK";

        qDebug()
            << "Folder:"
            << currentFolderPath;

        qDebug()
            << "File:"
            << currentFilePath;
    }
    sqlite3_finalize(statement);
    sqlite3_close(db);
}

// ---------------------------------------------------------------------------
//                   loadSession
// ---------------------------------------------------------------------------

void Lhome::loadSession(){
   
    sqlite3* db = nullptr;
    
    int man = sqlite3_open("Editor_Database.db",&db);

        if (man != SQLITE_OK){

            qDebug ()<< "databse of path not runing";

            sqlite3_close(db);
            return;
        }
    if (db == nullptr)
    {
        return;
    }
    const char* sql =
        "SELECT folder_path , file_path FROM editor_session WHERE id =1; ";

    sqlite3_stmt* statement;

    int result =
        sqlite3_prepare_v2(
            db,
            sql,
            -1,
            &statement,
            nullptr
        );
    if (result != SQLITE_OK)
    {
        qDebug()
            << "Prepare Error:"
            << sqlite3_errmsg(db);

        sqlite3_close(db);
        return;
    }
    result = sqlite3_step(statement);
    
    if (result == SQLITE_ROW)
    {
        const unsigned char* folder =  sqlite3_column_text( statement , 0 );
        
        const unsigned char* file =  sqlite3_column_text( statement , 1 );
        
                if (folder != nullptr)
        {
            currentFolderPath =
                QString::fromUtf8(
                    reinterpret_cast<
                        const char*
                    >(folder)
                );
        }

        if (file != nullptr)
        {
            currentFilePath =
                QString::fromUtf8(
                    reinterpret_cast<
                        const char*
                    >(file)
                );
        }

        qDebug()
            << "Session Loaded";

        qDebug()
            << "Folder:"
            << currentFolderPath;

        qDebug()
            << "File:"
            << currentFilePath;
    }
    else
    {
        qDebug()
            << "No Previous Session";
    }

    sqlite3_finalize(statement);
    

    
    loadFolder(currentFolderPath);

    loadFile(currentFilePath);

     SQLite ParamiterDataBase ;
    
  
  if(!ParamiterDataBase.openDatabase("Paramiter.db"))
  
    {
        qDebug() << "x-1";
        }

 QString autoSave = QString::fromStdString(ParamiterDataBase.getSetting("autoSave"));

        qDebug() <<"--------------------------| " << autoSave;
     
    SaveTime = new QTimer(this);
        
    connect(SaveTime,&QTimer::timeout,this, &Lhome::save);

        if (autoSave == "Enable"){

    SaveTime->start(10000);
        
    ToastWidget::showToast(
        
        this,
        "Auto Save ON ",
        6000
           );
    }
    else if (autoSave == "Disable") {

       SaveTime->stop();
        ToastWidget::showToast(
        this,
        "Auto Save OFF ",
        6000  
        
        );

        qDebug() << "auto save Stoped" ;
    }

    else{
        qDebug() << "+++++++++++++++++++++++++++++++++| nothnig" ;
    }

}

void Lhome::loadFile(QString currentFilePath){
    
    QString fileName = currentFilePath ;
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

void Lhome::loadFolder(QString currentFolderPath){
    
    QDir folder(currentFolderPath);
    
    if(!folder.exists()){
        
       qDebug()
            << "no folder in path :" << currentFolderPath;
        return;
    }
    dirModel->setRootPath(currentFolderPath);
    treeView->setRootIndex(
        dirModel->index(currentFolderPath)
    );
    currentFolderPath = currentFolderPath;
 
    qDebug()
            << "folder restored:" ;
}

void Lhome::RedyData(){
    
     std::string  devlong = ui->LPB->currentText().toStdString();
    
     std::string autoSave = ui->autoSaveBox->currentText().toStdString();
    
     std::string  notificatoins = ui->noti->currentText().toStdString();
    
     std::string  Auto_update = ui->update->currentText().toStdString();
    
    std::string  FontFamily = ui->fontComboBox->currentText().toStdString();
    
     std::string  autologin = ui->AutoLogin->currentText().toStdString();
    
    
    //  std::string  FontSize = ui->FontSIze->currentText().toStdString();

   //   std::string  TabSpace = ui->TabSpace->currentText().toStdString();
  
    SQLite ParamiterDataBase ;
    
  
  if(!ParamiterDataBase.openDatabase("Paramiter.db"))
  
    {
        qDebug() << "x-1";
        }
  
  if(!ParamiterDataBase.createSettingsTable())
       {
        qDebug() << "x-3";
        }
      
    
    if(!ParamiterDataBase.insertSetting("devlong",devlong,"TEXT"))
        
         {
        qDebug() << "x-3";
        }
    
    if(! ParamiterDataBase.insertSetting("autoSave",autoSave,"TEXT"))
        
         {
        qDebug() << "x-3";
        }
    
    if(!ParamiterDataBase.insertSetting("notificatoins",notificatoins,"TEXT"))
        
         {
        qDebug() << "x-3";
        }
    
    if(!ParamiterDataBase.insertSetting("Auto_update",Auto_update,"TEXT"))
        
         {
        qDebug() << "x-3";
        }

    if(!ParamiterDataBase.insertSetting("FontFamily",FontFamily,"TEXT"))

        {
        qDebug() << "x-3";
        }
        
    if(!ParamiterDataBase.insertSetting("autologin",autologin,"TEXT"))

        {
        qDebug() << "x-3";
        }

    // if(!ParamiterDataBase.insertSetting("FontSize",FontSIze,"int"))
        
   //      return;
  //   if(!ParamiterDataBase.insertSetting("TabSpace",TabSpace,"int"))
        
 //       return;
    
        
   
    }

    void Lhome::on_Commit_clicked()
    {
        
        SQLite ParamiterDataBase ;

        if(!ParamiterDataBase.openDatabase("Paramiter.db"))
            {
                qDebug() << "------------------ dataBase not open 1499 ";
                }

                qDebug() << 
                "-------------------- commite run ---------------------------------------------" ;

        std::string  devlong = ui->LPB->currentText().toStdString();
    
        std::string autoSave = ui->autoSaveBox->currentText().toStdString();
    
        std::string  notificatoins = ui->noti->currentText().toStdString();
    
        std::string  Auto_update = ui->update->currentText().toStdString();
          
        std::string  FontFamily = ui->fontComboBox->currentText().toStdString();
                
        std::string  autologin = ui->AutoLogin->currentText().toStdString();
         
        // std::string  TabSpace = ui->TabSpace->currentText().toStdString();
    
       // std::string  FontSize = ui->FontSIze->currentText().toStdString();
        
      //  if(!ParamiterDataBase.updateSetting("FontSize",FontSIze))
        
     //    return;
        
    //    if(!ParamiterDataBase.updateSetting("TabSpace",TabSpace))
        
   //     return;
        
        if(!ParamiterDataBase.updateSetting("FontFamily",FontFamily))
         
         {
        qDebug() << "x-1";
        }
        
        if(!ParamiterDataBase.updateSetting("Auto_update",Auto_update))
        
         {
        qDebug() << "x-1";
        }
        
        if(!ParamiterDataBase.updateSetting("notificatoins",notificatoins))
        
         {
        qDebug() << "x-1";
        }
        
        if(!ParamiterDataBase.updateSetting("autoSave",autoSave))
        
        {
        qDebug() << "x-1";
        }
        
        if(!ParamiterDataBase.updateSetting("devlong",devlong))
             {
        qDebug() << "x-1";
        }
        
        if(!ParamiterDataBase.updateSetting("autologin",autologin))
        
         {
        qDebug() << "x-1";
        }
        
        Out();

    }
    
    void Lhome::on_Rest_clicked()
    {
        SQLite ParamiterDataBase ;

        if(!ParamiterDataBase.openDatabase("Paramiter.db"))
            {
                qDebug() << "------------------ dataBase not open 1574 ";
                }

        if(!ParamiterDataBase.updateSetting("FontSize","16"))

        return;

        if(!ParamiterDataBase.updateSetting("FontFamily","Liberation Mono"))

        return;

        if(!ParamiterDataBase.updateSetting("TabSpace","4"))

        return;

        if(!ParamiterDataBase.updateSetting("Auto_update","Disable"))

        return;

        if(!ParamiterDataBase.updateSetting("notificatoins","Enable"))

        return;

        if(!ParamiterDataBase.updateSetting("autoSave","Enable"))

        return;

        if(!ParamiterDataBase.updateSetting("devlong","C++"))

        return;
        
        if(!ParamiterDataBase.updateSetting("autologin","Enable"))
            
        return;
        
        Out();
                      

    }

void Lhome::Out(){
    
       this->close();
                      
         Lhome *h = new Lhome();
                      
        h->show();

        return;
    
    }



























//
