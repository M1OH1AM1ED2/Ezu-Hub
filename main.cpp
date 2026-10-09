#include "checkwindow.h"
#include "lhome.h"
#include "firswindow.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
            CheckWindow w;
            w.show();
            
return a.exec();
}

