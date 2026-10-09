#ifndef LHOME_H
#define LHOME_H
#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexercpp.h>
#include <QWidget>
#include <QFileSystemModel>
#include <QTreeView>
#include <QSplitter>
#include <QtNetwork/QNetworkAccessManager>
#include <vector>
#include <QTime>
#include "sqlite.h"
#include <sqlite3.h>
#include <QCloseEvent>
#include <QSoundEffect>
QT_BEGIN_NAMESPACE
namespace Ui { class Lhome; }
QT_END_NAMESPACE

class Lhome : public QWidget
{
  Q_OBJECT
    
public:
    
  explicit Lhome(QWidget *parent = nullptr);

  ~Lhome();

private slots:
    
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
      
  Ui::Lhome *ui; 
  
  QsciScintilla *Editor;
  
  QsciLexerCPP *lexer;
  
  QFileSystemModel *dirModel;
  
  QTreeView *treeView;
  
  QNetworkAccessManager *manager ;
  
  std::vector<QString>AllTask;
  
  QTimer *apiTime;

  QTimer *SaveTime;
  
  QTimer *RunTime;
  
  QString folder ;
  
  QString fileName ;
  
  QString currentFolderPath = folder ;
      
  QString currentFilePath = fileName ;
  
  QSoundEffect *effect = new QSoundEffect(this);
  
  void checkAPI();
  
  void save();
  
  void LoopAskingSever();
  
  void database();
  
  void saveSession(QString currentFolderPath, QString currentFilePath);
  
  void loadFolder(QString nowFolderPath);
  
  void loadFile(QString nowFilePath);
  
  void loadSession();
  
  void Code_C_Plus_Plus_Runer();
  
  void Select_Paramiter_Of_Runing_Longuge_File_On_RunButton();
  
  void RedyData();
  
  void SetParamiter(QString autoSave);
  
  void Out();

  SQLite ParamiterDataBase ;
  
  
  
  
  
  
  
  
  
  
  
  
  
};











#endif



