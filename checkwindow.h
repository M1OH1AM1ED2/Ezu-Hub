#ifndef CHECKWINDOW_H
#define CHECKWINDOW_H
#include <QWidget>
#include <QPaintEvent>
#include <QTimer>
namespace Ui {
class Qwut;
}
class CheckWindow : public QWidget
{
  Q_OBJECT
public:
    
  explicit CheckWindow(QWidget *parent = nullptr);

  ~CheckWindow();

protected:
    
  void paintEvent(QPaintEvent *event) override;

private:
    
  Ui::Qwut *ui; 

  QTimer *checkTime;

    void AutoLogin();

    void CheckAccounte();

    void creatDtabaBaseForUsers();

    void ManulLogin();

   
   
};
#endif // CHECKWINDOW_H
