#ifndef FIRSWINDOW_H
#define FIRSWINDOW_H
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui {
class EzuHub;
}
QT_END_NAMESPACE
class FirsWindow : public QMainWindow
{
    Q_OBJECT
public:
    FirsWindow(QWidget *parent = nullptr);
    ~FirsWindow();
  private slots:
    void on_Login_clicked();
    void on_CreetAccount_clicked();
    

  private:
    Ui::EzuHub *ui;
};
#endif // FIRSWINDOW_H
