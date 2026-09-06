#ifndef CREET_H
#define CREET_H

#include <QWidget>

namespace Ui {
class CREET;
}

class CREET : public QWidget
{
  Q_OBJECT

public:
  explicit CREET(QWidget *parent = nullptr);
  ~CREET();
protected:
  void paintEvent(QPaintEvent *event) override;
private slots:
  void on_submet_clicked();

  void on_CreetAccount_clicked();

private:
  Ui::CREET *ui;
};

#endif // CREET_H
