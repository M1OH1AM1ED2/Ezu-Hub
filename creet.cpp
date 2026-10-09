#include "creet.h"
#include "ui_creet.h"
#include "firswindow.h"
#include <QDebug>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QUrl>
#include <QStyleOption>
#include <QPainter>
#include <QMessageBox>
CREET::CREET(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CREET)
{
  ui->setupUi(this);
  this->setFixedSize(860,534);
  this->setWindowTitle("Ezu-Hub");
}
CREET::~CREET()
{
  delete ui;
}
void CREET::paintEvent(QPaintEvent *event)
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
void CREET::on_submet_clicked()
{
  QString email = ui-> Email-> text();
  QString password = ui-> Password-> text();
  QString token = ui-> Token-> text();
  QNetworkAccessManager *manager = new QNetworkAccessManager(this);
  QNetworkRequest request(
      QUrl("http://127.0.0.1:8000/SingIn")
      );
  request.setHeader(
      QNetworkRequest::ContentTypeHeader,
      "application/json"
      );
  QJsonObject json;
  json["username"] = email;
  json["password"] = password;
  json["GitHubToken"] = token;
  QByteArray data =
      QJsonDocument(json).toJson();
  QNetworkReply *reply =
      manager->post(request, data);
  connect(reply, &QNetworkReply::finished,this,[reply,this]()
          {
            QByteArray response = reply->readAll();
            QJsonDocument doc = QJsonDocument::fromJson(response);
            QJsonObject res = doc.object();
            QString uname = res["username"].toString();
            QString code = res["status_code"].toString();
            qDebug() << uname ;
            qDebug() <<"status_code :"<< code ;
            reply->deleteLater();
            if (code == "200"){
              QMessageBox::information(this,"info","  Your account creeted ");
              this->close();
              FirsWindow *h = new FirsWindow();
              h->show();
            }
          });
}
void CREET::on_CreetAccount_clicked()
{
  this->close();
  FirsWindow *h = new FirsWindow();
  h->show();
}





































