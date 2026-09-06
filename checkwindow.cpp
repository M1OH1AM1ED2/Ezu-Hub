#include "checkwindow.h"
#include "ui_checkwindow.h"
#include <QMessageBox>
#include <QTimer>
#include <QStyleOption>
#include <QPainter>
#include "firswindow.h"
CheckWindow::CheckWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Qwut)
{
  ui->setupUi(this);
  this->setFixedSize(860,534);
  this->setHidden(true);
  int v = 0;
  QTimer *timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, [this, timer, v]() mutable {
    ui->progressBar->setValue(v);
    if (v == 100)
    {
      timer->stop();
      this->close();
      FirsWindow *h = new FirsWindow();
      h->show();
      return;
    }
    v = v + 4;
  });
  timer->start(30);
}
CheckWindow::~CheckWindow()
{
  delete ui;
}
void CheckWindow::paintEvent(QPaintEvent *event)
{
  Q_UNUSED(event);
  QPainter painter(this);
  QPixmap pixmap(":/images/s.jpg");
  if (!pixmap.isNull())
  {
    QPixmap scaled = pixmap.scaled(
        size(),
        Qt::KeepAspectRatioByExpanding,
        Qt::SmoothTransformation
        );
    int x = (width() - scaled.width()) / 2;
    int y = (height() - scaled.height()) / 2;
    painter.drawPixmap(x, y, scaled);
  }
}

































