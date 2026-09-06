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
  void on_pushButton_clicked();
  void on_openFiles_clicked(); // o صغير

  void on_RunCode_clicked();
  void on_Exit_clicked();
  void on_new_2_clicked();
  void on_CCL_clicked();
  void on_clear_clicked();
  void onTreeFileClicked(const QModelIndex &index);

  void on_pushButton_Ask_clicked();

  void on_Give_clicked();

  void on_AllTask_clicked();

  private:
  Ui::Lhome *ui;
  QsciScintilla *Editor;
  QsciLexerCPP *lexer;
  QFileSystemModel *dirModel;
  QTreeView *treeView;
  void LoopAskingSever();
  QNetworkAccessManager *manager ;
  void teck();
  std::vector<QString>AllTask;
  
};
#endif
