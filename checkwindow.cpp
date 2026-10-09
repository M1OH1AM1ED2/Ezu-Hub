#include "checkwindow.h"
#include "ui_checkwindow.h"
#include "lhome.h"
#include <QMessageBox>
#include <sqlite3.h>
#include <QTimer>
#include <QStyleOption>
#include <QPainter>
#include "firswindow.h"
#include "lhome.h"
#include "ui_lhome.h"
#include "sqlite.h"
#include <sqlite3.h>
#include <string>
#include <QDebug>
CheckWindow::CheckWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Qwut)
{
  ui->setupUi(this);
  this->setWindowTitle("Ezu-Hub");
  this->setFixedSize(860,534);
  this->setHidden(true);
    creatDtabaBaseForUsers();
    
    SQLite ParamiterDataBase ;
    
     if(!ParamiterDataBase.openDatabase("Paramiter.db"))
    {
        qDebug() << "------------------ dataBase not open 30 | ch.ccp ";
        }

    QString autologin = QString::fromStdString(ParamiterDataBase.getSetting("autologin"));
    
    if (autologin == "Enable"){
        
        CheckAccounte();
    }
    
    else{
        
        ManulLogin();
    }
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

void CheckWindow::AutoLogin(){
    
    int v = 0;
    
   QTimer *timer = new QTimer(this);
    
    connect(timer, &QTimer::timeout, this, [this, timer, v]() mutable {
        
     ui->progressBar->setValue(v);
        
      if (v == 100)
          
     {
        timer->stop();
                      
         this->close();
        
            Lhome *lhome = new Lhome();
    
            lhome->show();
                      
            return;
                    
         }
                   
         v = v + 2;
                  
         });
                  
         timer->start(30);
}

void CheckWindow::ManulLogin(){
    
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
                   
         v = v + 2;
                  
         });
                  
         timer->start(30);
}
       
void CheckWindow::creatDtabaBaseForUsers(){
    
        sqlite3* db = nullptr;
    
        int result = sqlite3_open("login_Database.db",&db);

        if (result != SQLITE_OK){

            qDebug ()<< "databse of path not runing";

            sqlite3_close(db);
        }

        qDebug ()<< "databse runing";

        const char* sqlQuery = R"(CREATE TABLE IF NOT EXISTS login (id INTEGER PRIMARY KEY ,name TEXT ,token TEXT );)";

        char* ErrorSql = nullptr;

        int creat = sqlite3_exec(db,sqlQuery,nullptr,nullptr,&ErrorSql );

        if (creat != SQLITE_OK){

            qDebug ()<< ErrorSql ;
        }

        else {

            qDebug ()<< "databse of login created ";
        }   
    }

void CheckWindow::CheckAccounte(){
    
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
        "SELECT * FROM login WHERE id =1; ";

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

        return;
    }
    result = sqlite3_step(statement);
    
    if (result == SQLITE_ROW)
    {
        const unsigned char* username =  sqlite3_column_text( statement , 0 );
        
        const unsigned char* gitToken =  sqlite3_column_text( statement , 1 );
        
           qDebug()
            << "login True";

        qDebug()
            << "username:"
            << username;

        qDebug()
            << "GitHub-Token:"
        
            << gitToken;
        
        if (username){
          
             qDebug()
            << "---------------------> auto login run  : ";
            
            AutoLogin();
            
        }else{
             qDebug() <<"-------------------------------";
             qDebug() << "No username And GitHub Token"  ;
            qDebug() <<"--------------------------------";
            }
    }
    else
    {
        qDebug()
            << "No Previous Session";
        qDebug()
            << "------------------------> need a Manul Login  :";
        ManulLogin();
    }

    sqlite3_finalize(statement);
    
}


















































