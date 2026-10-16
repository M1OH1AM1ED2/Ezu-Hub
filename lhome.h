#ifndef LHOME_H
#define LHOME_H

#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexercpp.h>

#include <QWidget>
#include <QFileSystemModel>
#include <QTreeView>
#include <QSplitter>

#include <QtNetwork/QNetworkAccessManager>
#include <QNetworkReply>

#include <QLineEdit>
#include <QToolButton>
#include <QShortcut>
#include <QKeySequence>
#include <QHBoxLayout>

#include <QTimer>
#include <QTime>

#include <QCloseEvent>
#include <QSoundEffect>

#include <vector>

#include "sqlite.h"
#include <sqlite3.h>


QT_BEGIN_NAMESPACE

namespace Ui {
class Lhome;
}

QT_END_NAMESPACE


class Lhome : public QWidget
{
    Q_OBJECT

public:

    explicit Lhome(QWidget *parent = nullptr);

    ~Lhome();


private slots:

    // =================================================
    // SEARCH
    // =================================================

    void createSearchBar();

    void findNext();

    void findPrevious();

    void closeSearchBar();


    // =================================================
    // EXISTING SLOTS
    // =================================================

    void checkForUpdates();

    void on_CheckForUpdates_clicked();

    void on_openFiles_clicked();

    void on_RunCode_clicked();

    void on_Exit_clicked();

    void on_new_2_clicked();

    void on_CCL_clicked();

    void on_clear_clicked();

    void onTreeFileClicked(const QModelIndex &index);

    void on_Give_clicked();

    void on_AllTask_clicked();

    void on_terminal_clicked();

    void on_Notificatoins();

    void on_Commit_clicked();

    void on_Rest_clicked();

    void on_ERROR_2_clicked();


private:

    // =================================================
    // SEARCH UI
    // =================================================

    QWidget *searchBar;

    QLineEdit *searchInput;

    QToolButton *nextButton;

    QToolButton *previousButton;

    QToolButton *closeButton;

    QString lastSearchText;

    // =================================================
    // MAIN UI
    // =================================================

    Ui::Lhome *ui;


    // =================================================
    // CODE EDITOR
    // =================================================

    QsciScintilla *Editor;

    QsciLexerCPP *lexer;


    // =================================================
    // FILE SYSTEM
    // =================================================

    QFileSystemModel *dirModel;

    QTreeView *treeView;


    // =================================================
    // NETWORK
    // =================================================

    QNetworkAccessManager *manager;


    // =================================================
    // TASKS
    // =================================================

    std::vector<QString> AllTask;


    // =================================================
    // TIMERS
    // =================================================

    QTimer *apiTime;

    QTimer *SaveTime;

    QTimer *RunTime;


    // =================================================
    // PATHS
    // =================================================

    QString folder;

    QString fileName;

    QString currentFolderPath = folder;

    QString currentFilePath = fileName;


    // =================================================
    // SOUND
    // =================================================

    QSoundEffect *effect = new QSoundEffect(this);


    // =================================================
    // EXISTING FUNCTIONS
    // =================================================

    void LongName();

    void applyCppTheme();

    void applyPythonTheme();

    void checkAPI();

    void save();

    void LoopAskingSever();

    void database();


    void saveSession(
        QString currentFolderPath,
        QString currentFilePath
    );


    void loadFolder(
        QString nowFolderPath
    );


    void loadFile(
        QString nowFilePath
    );


    void loadSession();

    void Code_C_Plus_Plus_Runer();

    void Select_Paramiter_Of_Runing_Longuge_File_On_RunButton();

    void RedyData();

    void SetParamiter(QString autoSave);

    void Out();

    void Code_python_Runer();


    // =================================================
    // DATABASE
    // =================================================

    SQLite ParamiterDataBase;
};

#endif