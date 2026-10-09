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
#include <sqlite3.h>
#include <QDebug>
FirsWindow::FirsWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EzuHub)
{
    ui->setupUi(this);
    this->setFixedSize(860,534);
    this->setWindowTitle("Ezu-Hub");
}
FirsWindow::~FirsWindow()
{
    delete ui;
}
void FirsWindow::on_Login_clicked()
{
  QString username = ui-> Email-> text();
    
  QString Git_Token = ui-> Password-> text();
    
  QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    
  QNetworkRequest request(
    
      QUrl("http://10.42.0.103:8000/Login")
      );
  request.setHeader(
    
      QNetworkRequest::ContentTypeHeader,
    
      "application/json"
      );
      
  QJsonObject json;

  json["username"] = username;

  json["password"] = Git_Token;

  QByteArray data =

      QJsonDocument(json).toJson();

  QNetworkReply *reply =

      manager->post(request, data);

  connect(reply, &QNetworkReply::finished,this, [reply,this]()

          {
            QByteArray response = reply->readAll();

            QJsonDocument doc = QJsonDocument::fromJson(response);

            QJsonObject res = doc.object();
            QString username = res["username"].toString();

            QString code = res["status_code"].toString();

            QString Git_Token = res["GitHub_Token"].toString();

            qDebug() << username ;

            qDebug() << code ;

	    reply->deleteLater();

	    if (code == "200")

	    {
           LoginUser(username,Git_Token) ;
            
            this->close();
            
            Lhome *c = new Lhome();
            
            c->show();
        }
        else {
            return;
            
        }
	  }
      
      );
      
LoginUser(username,Git_Token);
          
}

void FirsWindow::on_CreetAccount_clicked()
{
  this->close();
  CREET *c = new CREET();
  c->show();

}

void FirsWindow::LoginUser(QString username,QString Git_Token){
    
    sqlite3* db = nullptr;
 
    int man = sqlite3_open("login_Database.db",&db);

        if (man != SQLITE_OK){

            qDebug ()<< "databse of login not runing";

            sqlite3_close(db);
        }
    if (db == nullptr)
    {
        return;
    }
    const char* sql =
        "INSERT OR REPLACE INTO login "
        "(id, name, token) "
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
        
        qDebug()
        
            << "bad 151:";
            this->close();
            return ;
    }
    sqlite3_bind_int(
        statement,
        1,
        1
    );
    sqlite3_bind_text(
        statement,
        2,
        username.toUtf8().constData(),
        -1,
        SQLITE_TRANSIENT
    );

    sqlite3_bind_text( statement, 3, Git_Token.toUtf8().constData(), -1, SQLITE_TRANSIENT
    );
    result =
        sqlite3_step(statement);

    if (result != SQLITE_DONE)
    {
        qDebug()
            << "Save Error:"
            << sqlite3_errmsg(db);
            return;
    }
    else
    {
        qDebug()
            << "login Saved to data base  --------------> database 200 OK";

        qDebug()
            << "user:"
            << username;

        qDebug()
            << "Token:"
            << "*******************************************";
        
        this->close();
            
        Lhome *c = new Lhome();
            
        c->show();
    }
    sqlite3_finalize(statement);

}






































