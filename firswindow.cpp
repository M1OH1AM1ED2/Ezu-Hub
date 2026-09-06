#include "firswindow.h"
#include "./ui_firswindow.h"
#include "lhome.h"
#include "creet.h"
#include <QMessageBox>
#include <QDebug>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QUrl>
FirsWindow::FirsWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EzuHub)
{
    ui->setupUi(this);
    this->setFixedSize(860,534);
}
FirsWindow::~FirsWindow()
{
    delete ui;
}
void FirsWindow::on_Login_clicked()
{
  QString email = ui-> Email-> text();
  QString password = ui-> Password-> text();
  QNetworkAccessManager *manager = new QNetworkAccessManager(this);
  QNetworkRequest request(
      QUrl("http://127.0.0.1:8000/Login")
      );
  request.setHeader(
      QNetworkRequest::ContentTypeHeader,
      "application/json"
      );
  QJsonObject json;
  json["username"] = email;
  json["password"] = password;
  QByteArray data =
      QJsonDocument(json).toJson();
  QNetworkReply *reply =
      manager->post(request, data);
  connect(reply, &QNetworkReply::finished,this, [reply,this]()
          {
            QByteArray response = reply->readAll();
            QJsonDocument doc = QJsonDocument::fromJson(response);
            QJsonObject res = doc.object();
            QString uname = res["username"].toString();
            QString code = res["status_code"].toString();
            qDebug() << uname ;
            qDebug() << code ;
	    reply->deleteLater();
	    if (code == "200")
	    {
	      this->close();
	      Lhome *v = new Lhome();
	      v->show();
	    }
	    else
	    {
	      QMessageBox::warning(this," warning "," password or email error Try agin ");
	    }
	  });
}
void FirsWindow::on_CreetAccount_clicked()
{
  this->close();
  CREET *c = new CREET();
  c->show();

}

