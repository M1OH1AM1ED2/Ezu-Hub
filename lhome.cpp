#include "lhome.h" 
#include "CppLexer.h"
#include "PythonLexer.h"
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
#include <Qsci/qscilexerpython.h>
#include <vector>
#include <functional>
#include <utility>
#include <thread>
#include <QDebug>
#include "sqlite.h"
#include <sqlite3.h>
#include <string>
#include <QSoundEffect>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QDesktopServices>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "downloadwaitingscreen.h"
#include "DartLexer.h"
#include <QStandardPaths>
#include <QFileInfo>
#include <QStringConverter>  
#include <QStandardPaths>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>
#include <QSettings>
#include <QProcess>
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QMessageBox>
#include <QProcess>
#include <QRegularExpression>
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

        
        int FontSize = 16;
        
        int TabSpace = 4;

        QString FontFamily = "Liberation Mono";
        
        
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
     
     Editor->setFont(font);
    Editor->setLexer(lexer);
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
        QColor("#181825")
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
    createSearchBar();
    loadSession();
    LongName();
   
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

//======================================================================================================================
void Lhome::applyDartTheme()
{
    // إنشاء Lexer خاص بلغة Dart
    auto *dartLexer = new DartLexer(Editor);

    // أخذ نفس خط المحرر
    QFont editorFont = Editor->font();

    // الخط الافتراضي
    dartLexer->setDefaultFont(editorFont);

    // ربط الـ Lexer بالمحرر
    Editor->setLexer(dartLexer);

    // =====================================================
    // LINE NUMBERS
    // =====================================================

    const QColor lineNumberBg("#181825");

    Editor->setMarginsForegroundColor(
        QColor("#6C7086")
    );

    Editor->setMarginsBackgroundColor(
        lineNumberBg
    );
}
//=======================================================================================================================
#include "PythonLexer.h"

void Lhome::applyPythonTheme()
{
    auto *lexer = new PythonLexer(Editor);

    const QFont editorFont = Editor->font();
    lexer->setDefaultFont(editorFont);

    for (int style = 0; style < 128; ++style) {
        if (lexer->description(style).isEmpty())
            continue;
        QFont f = lexer->font(style);
        f.setFamily(editorFont.family());
        f.setPointSize(editorFont.pointSize());
        lexer->setFont(f, style);
    }

    Editor->setLexer(lexer);

    // LINE NUMBERS
    Editor->setMarginsForegroundColor(QColor("#858585"));
    Editor->setMarginsBackgroundColor(QColor("#181825"));
}
// =======================================================================================================================

#include "CppLexer.h"

void Lhome::applyCppTheme()
{
    // إنشاء Lexer خاص بلغة C++
    auto *lexer = new CppLexer(Editor);

    // أخذ نفس خط المحرر مع الحفاظ على المائل والعريض في الأنماط
    const QFont editorFont = Editor->font();
    lexer->setDefaultFont(editorFont);

    for (int style = 0; style < 128; ++style) {
        if (lexer->description(style).isEmpty())
            continue;
        QFont f = lexer->font(style);
        f.setFamily(editorFont.family());
        f.setPointSize(editorFont.pointSize());
        lexer->setFont(f, style);
    }

    // ربط الـ Lexer بالمحرر
    Editor->setLexer(lexer);

    // =====================================================
    // LINE NUMBERS
    // =====================================================
    Editor->setMarginsForegroundColor(QColor("#858585"));
    Editor->setMarginsBackgroundColor(QColor("#1E1E1E"));
}

//--------------------------------------
// ===============================================================================================


void Lhome::LongName()
{
    SQLite ParamiterDataBase;

    if (!ParamiterDataBase.openDatabase("Paramiter.db"))
    {
        qDebug() << "Database not open";
        return;
    }

    QString language =
        QString::fromStdString(
            ParamiterDataBase.getSetting("devlong")
        ).trimmed().toLower();

    if (language == "c++" || language == "cpp")
    {
        applyCppTheme();
        qDebug() << "C++ theme applied";
        
        ToastWidget::showToast(
                this,
                "C++ theme applied",
                2000,
                400
            );
    }
    else if (language == "python" || language == "py")
    {
        applyPythonTheme();
        qDebug() << "Python theme applied";
        
        ToastWidget::showToast(
                this,
                "Python theme applied",
                2000,
                400
            );
    }
    else if (language == "dart" || language == "flutter")
    {
     
        qDebug() << "dart theme applied";
        applyDartTheme();
        ToastWidget::showToast(
                this,
                "dart theme applied",
                2000,
                400
            );
    }
    else
    {
        qDebug() << "Unknown language:" << language;
    }
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
    fileName = QFileDialog::getSaveFileName(
        this,
        "Save C++ File",
        QDir::homePath(),
        "Text Files (*.txt);;C++ Files (*.cpp *.h);;All Files (*)"
    );

    if (fileName.isEmpty())
        return;

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
     
void Lhome::save(){
    
   QString compennet = Editor->text();

if (compennet.trimmed().isEmpty())
{
    qDebug() << "Nothing to save";
    return;
}

// ==========================================
// تحديد اسم الملف
// ==========================================

QString fileName = ui->file->text().trimmed();

if (fileName.isEmpty())
{
    fileName =
        QDir::homePath() +
        "/Desktop/Defult.txt";
}

// ==========================================
// حفظ الملف
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
out << compennet;

file.close();

qDebug() << "File saved:" << fileName;
}
void Lhome::Select_Paramiter_Of_Runing_Longuge_File_On_RunButton() // --------------------Runer ------------------
{
    SQLite ParamiterDataBase;

    if (!ParamiterDataBase.openDatabase("Paramiter.db"))
    {
        qDebug() << "Database not open: Paramiter.db";
        QMessageBox::critical(
            this,
            "Database Error",
            "Cannot open Paramiter.db"
        );
        return;
    }

    QString devlong = QString::fromStdString(
        ParamiterDataBase.getSetting("devlong")
    ).trimmed();

    qDebug() << "Selected language:" << devlong;

    if (devlong == "C++")
    {
        Code_C_Plus_Plus_Runer();
    }
    else if (devlong == "python")
    {
        Code_python_Runer();
    }
    else
    {
        QMessageBox::warning(
            this,
            "Run Code",
            "Unsupported language: " + devlong
        );
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

void Lhome::Code_python_Runer(){ // --------------------------------------- python Metode run ------------------+
    
        QString code = Editor->text();

        if (code.trimmed().isEmpty())
        {
            QMessageBox::warning(
                this,
                "Run Python",
                "The editor is empty."
            );
            return;
        }

        // ==========================================
        // اسم الملف
        // ==========================================

        QString fileName = ui->file->text();

        if (fileName.isEmpty())
        {
            fileName =
                QDir::homePath() +
                "/Desktop/untitled.py";
        }

        if (!fileName.endsWith(
                ".py",
                Qt::CaseInsensitive))
        {
            fileName += ".py";
        }

        // ==========================================
        // حفظ Python File
        // ==========================================

        QFile file(fileName);

        if (!file.open(
                QIODevice::WriteOnly |
                QIODevice::Text))
        {
            QMessageBox::critical(
                this,
                "Save Error",
                "Cannot save the Python file."
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

        QString workingDirectory =
            info.absolutePath();

        // ==========================================
        // Python Command
        // ==========================================

        QString command =
            QString(
                "cd \"%1\" && python3 \"%2\"; "
                "echo ''; "
                "echo 'Press Enter to close...'; "
                "read"
            )
            .arg(
                workingDirectory,
                info.fileName()
            );

        // ==========================================
        // XTERM Arguments
        // ==========================================

        QStringList terminalArgs;

        terminalArgs
            << "-T"
            << "Ezu-Hub Python Program"

            << "-geometry"
            << "100x30+350+150"

            << "-fa"
            << "JetBrains Mono"

            << "-fs"
            << "12"

            << "-e"
            << "bash"
            << "-c"
            << command;

        // ==========================================
        // فتح XTERM
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
    
    QMediaPlayer *player = new QMediaPlayer(this);
    QAudioOutput *audioOutput = new QAudioOutput(this);

    audioOutput->setVolume(0.5);
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl("qrc:/sounds/ERROR.mp3"));

    player->play();

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

    SaveTime->start(2000);
        
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
// =====================================================
//                  CHECK FOR UPDATES
// =====================================================

void Lhome::checkForUpdates()
{
    const QString currentVersion = "v1.1.3";

    const QUrl url(
        "https://api.github.com/repos/M1OH1AM1ED2/Ezu-Hub/releases/latest"
    );

    QNetworkRequest request(url);

    request.setHeader(
        QNetworkRequest::UserAgentHeader,
        "Ezu-Hub"
    );

    request.setRawHeader(
        "Accept",
        "application/vnd.github+json"
    );

    QNetworkReply *reply = manager->get(request);

    connect(
        reply,
        &QNetworkReply::finished,
        this,
        [this, reply, currentVersion]()
        {
            if (reply->error() != QNetworkReply::NoError)
            {
                QMessageBox::warning(
                    this,
                    "Update Check",
                    "Could not check for updates.\n"
                    "Please check your internet connection."
                );

                reply->deleteLater();
                return;
            }

            const QByteArray response = reply->readAll();

            const QJsonDocument document =
                QJsonDocument::fromJson(response);

            if (!document.isObject())
            {
                QMessageBox::warning(
                    this,
                    "Update Check",
                    "Invalid response from GitHub."
                );

                reply->deleteLater();
                return;
            }

            const QJsonObject release = document.object();

            const QString latestVersion =
                release.value("tag_name").toString();

            if (latestVersion.isEmpty())
            {
                QMessageBox::warning(
                    this,
                    "Update Check",
                    "Could not find the latest release."
                );

                reply->deleteLater();
                return;
            }

            if (latestVersion == currentVersion)
            {
                QMessageBox::information(
                    this,
                    "Ezu-Hub Updates",
                    "You are using the latest version: "
                    + currentVersion
                );
            }
            else
            {
                QMessageBox messageBox(
                    QMessageBox::Information,
                    "Update Available",
                    "A new version of Ezu-Hub is available.\n\n"
                    "Current version: " + currentVersion +
                    "\nLatest version: " + latestVersion +
                    "\n\nOpen the official release page?",
                    QMessageBox::Yes | QMessageBox::No,
                    this
                );

                if (messageBox.exec() == QMessageBox::Yes)
                {
                    QDesktopServices::openUrl(
                        QUrl(
                            "https://github.com/M1OH1AM1ED2/Ezu-Hub/releases"
                        )
                    );
                }
            }

            reply->deleteLater();
        }
    );
}


void Lhome::on_CheckForUpdates_clicked()
{
    checkForUpdates();
}


// =====================================================
//                  CREATE SEARCH BAR
// =====================================================

void Lhome::createSearchBar()
{
    searchBar = new QWidget(this);
    searchBar->setObjectName("searchBar");
    searchBar->setFixedSize(350, 42);

    QHBoxLayout *layout = new QHBoxLayout(searchBar);
    layout->setContentsMargins(6, 3, 6, 3);
    layout->setSpacing(4);

    searchInput = new QLineEdit(searchBar);
    searchInput->setPlaceholderText("Find in file...");
    searchInput->setClearButtonEnabled(true);
    searchInput->setFixedSize(220, 30);

    previousButton = new QToolButton(searchBar);
    nextButton = new QToolButton(searchBar);
    closeButton = new QToolButton(searchBar);

    previousButton->setText("↑");
    nextButton->setText("↓");
    closeButton->setText("×");

    previousButton->setFixedSize(30, 30);
    nextButton->setFixedSize(30, 30);
    closeButton->setFixedSize(30, 30);

    layout->addWidget(searchInput);
    layout->addWidget(previousButton);
    layout->addWidget(nextButton);
    layout->addWidget(closeButton);

    searchBar->setStyleSheet(
        "QWidget#searchBar { background-color: #181825; }"
        "QLineEdit { background-color: #1E1E2E; color: #CDD6F4;"
        "border: 1px solid #45475A; border-radius: 5px; padding: 4px; }"
        "QToolButton { background-color: #313244; color: #CDD6F4;"
        "border: none; border-radius: 4px; }"
        "QToolButton:hover { background-color: #45475A; }"
    );

    searchBar->hide();
    ui->edo->insertWidget(0, searchBar, 0, Qt::AlignLeft);

    connect(nextButton, &QToolButton::clicked,
            this, &Lhome::findNext);

    connect(previousButton, &QToolButton::clicked,
            this, &Lhome::findPrevious);

    connect(closeButton, &QToolButton::clicked,
            this, &Lhome::closeSearchBar);

    connect(searchInput, &QLineEdit::returnPressed,
            this, &Lhome::findNext);

    QShortcut *findShortcut = new QShortcut(QKeySequence::Find, this);
    findShortcut->setContext(Qt::WidgetWithChildrenShortcut);

    connect(findShortcut, &QShortcut::activated, this, [this]()
    {
        searchBar->show();
        searchInput->setFocus();
        searchInput->selectAll();
    });

    QShortcut *previousShortcut = new QShortcut(
        QKeySequence(Qt::SHIFT | Qt::Key_Return), searchInput);

    connect(previousShortcut, &QShortcut::activated,
            this, &Lhome::findPrevious);

    QShortcut *escapeShortcut = new QShortcut(
        QKeySequence(Qt::Key_Escape), searchInput);

    connect(escapeShortcut, &QShortcut::activated,
            this, &Lhome::closeSearchBar);
}


// =====================================================
//                       FIND NEXT
// =====================================================

void Lhome::findNext()
{
    const QString text = searchInput->text();

    if (text.isEmpty())
        return;

    if (text != lastSearchText)
    {
        lastSearchText = text;
        Editor->findFirst(text, false, false, false, true, true);
    }
    else
    {
        Editor->findNext();
    }
}


// =====================================================
//                     FIND PREVIOUS
// =====================================================

void Lhome::findPrevious()
{
    const QString text = searchInput->text();

    if (text.isEmpty())
        return;

    lastSearchText = text;

    int line = 0;
    int index = 0;

    Editor->getCursorPosition(&line, &index);

    Editor->findFirst(
        text, false, false, false, true, false, line, index
    );
}


// =====================================================
//                      CLOSE SEARCH
// =====================================================

void Lhome::closeSearchBar()
{
    searchBar->hide();
    Editor->setFocus();
}

 void Lhome::on_ins_clicked(){
     
     Fuller_Dart_install();
 }


int Lhome::Fuller_Dart_install()
{

    const std::vector<std::string> commands = {
        "git clone https://github.com/flutter/flutter.git "
        
        "-b stable \"$HOME/flutter\"",

       "grep -qxF 'export PATH=\"$HOME/flutter/bin:$PATH\"' "
       
        "\"$HOME/.bashrc\" || "
        
        "echo 'export PATH=\"$HOME/flutter/bin:$PATH\"' "
        
        ">> \"$HOME/.bashrc\"",
        
        "sudo apt install -y ninja-build libgtk-3-dev",
        "ezu-hub",
        
        "flutter --version",

        "dart --version",
        
        "ninja --version",
        
        "pkg-config --modversion gtk+-3.0"
        
        
    };

    for (const auto& command : commands)
    {
        std::cout << "\nExecuting: " << command << '\n';

        const int result = std::system(command.c_str());

        if (result != 0)
        {
            std::cerr << "Command failed. Stopping installation.\n";
            return 1;
        }
    }

    std::cout << "\nFlutter and Dart setup completed.\n";
    
    std::cout << "Restart the terminal or run: source ~/.bashrc\n";

    return 0;
}

void Lhome::runFlutter()
{
    const QString projectDir = ui->PATH_WORKFLOW->text().trimmed();

    if (projectDir.isEmpty() || !QDir(projectDir).exists())
    {
        QMessageBox::warning(
            this,
            "Flutter",
            "Invalid project directory."
        );
        return;
    }

    QProcess::startDetached(
        "xterm",
        QStringList{
            "-hold",
            "-e",
            "bash",
            "-ic",
            "flutter run -d linux"
        },
        projectDir
    );
}
void Lhome::on_FremWork_clicked()
{
    runFlutter();
}

void Lhome::on_CREET_PROJE_clicked()
{
    const QString nameProje = ui->NAME_PROJE->text().trimmed();
    
    const QString parentDir = ui->PATH_WORKFLOW->text().trimmed();
    
    const  QString width = ui->WIDTH_COMBOBOX->currentText().trimmed();
    
    const  QString center = ui->CONTER_COMBOBOX->currentText().trimmed();
    
    qDebug() << parentDir ;
    
    if (nameProje.isEmpty() || parentDir.isEmpty()) { 
    
        QMessageBox::warning(this, "Flutter", "أدخل اسم المشروع ومساره.");
        return;
    }

    const QStringList dartFile = {
        QString("import 'package:flutter/material.dart';"),
        QString("import 'package:window_manager/window_manager.dart';"),
        QString(""),
        QString("Future<void> main() async {"),
        QString("  WidgetsFlutterBinding.ensureInitialized();"),
        QString("  await windowManager.ensureInitialized();"),
        QString("  const options = WindowOptions("),
        QString("    size: Size(%1),").arg(width),
        QString("    center: '") + center + QString("',"),
        QString("    title: '") + nameProje + QString("',"),
        QString("  );"),
        QString("  windowManager.waitUntilReadyToShow(options, () async {"),
        QString("    await windowManager.show();"),
        QString("    await windowManager.focus();"),
        QString("  });"),
        QString("  runApp(const MyApp());"),
        QString("}"),
        QString(""),
        QString("class MyApp extends StatelessWidget {"),
        QString("  const MyApp({super.key});"),
        QString("  @override"),
        QString("  Widget build(BuildContext context) {"),
        QString("    return MaterialApp("),
        QString("      debugShowCheckedModeBanner: false,"),
        QString("      home: Scaffold("),
        QString("        appBar: AppBar("),
        QString("          title: const Text('Demo App'),"),
        QString("        ),"),
        QString("        body: const Center("),
        QString("          child: Text('Hello from Ezu-Hub'),"),
        QString("        ),"),
        QString("      ),"),
        QString("    );"),
        QString("  }"),
        QString("}")
    };

    const QString filePath = parentDir+"/lib/main.dart";
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this,"Can't open file ",file.errorString());
        return;
    }

    QTextStream out(&file);
    for (const QString &line : dartFile)
        out << line << '\n';
    file.close();

    QMessageBox::information(this, "Flutter", "تم إنشاء المشروع:\n" + filePath);
}


void Lhome::on_path_Work_2_clicked()
{
    QString folder =
        QFileDialog::getExistingDirectory(
            this,
            "Select Project Folder",
            QDir::homePath()
        );
        
    ui->PATH_WORKFLOW->setText(folder);
     
}































//
