#include "checkwindow.h"
#include "lhome.h"
#include "firswindow.h"
#include <QApplication>
#include <QDebug>
   #include <QApplication>
#include <QIcon>
int main(int argc, char *argv[])
{


    QApplication app(argc, argv);
    
    app.setWindowIcon(QIcon(":/images/ezu-hub.png"));

    CheckWindow w;
    
    w.show();



            
return app.exec();
}

