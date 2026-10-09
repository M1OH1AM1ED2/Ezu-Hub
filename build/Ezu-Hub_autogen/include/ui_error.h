/********************************************************************************
** Form generated from reading UI file 'error.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERROR_H
#define UI_ERROR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ERROR
{
public:

    void setupUi(QWidget *ERROR)
    {
        if (ERROR->objectName().isEmpty())
            ERROR->setObjectName("ERROR");
        ERROR->resize(400, 300);

        retranslateUi(ERROR);

        QMetaObject::connectSlotsByName(ERROR);
    } // setupUi

    void retranslateUi(QWidget *ERROR)
    {
        ERROR->setWindowTitle(QCoreApplication::translate("ERROR", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ERROR: public Ui_ERROR {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERROR_H
