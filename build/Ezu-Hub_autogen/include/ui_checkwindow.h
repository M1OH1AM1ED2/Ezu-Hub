/********************************************************************************
** Form generated from reading UI file 'checkwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKWINDOW_H
#define UI_CHECKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qwut
{
public:
    QLabel *label;
    QProgressBar *progressBar;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;

    void setupUi(QWidget *Qwut)
    {
        if (Qwut->objectName().isEmpty())
            Qwut->setObjectName("Qwut");
        Qwut->resize(860, 534);
        Qwut->setStyleSheet(QString::fromUtf8("/*\n"
"Material Dark Style Sheet for QT Applications\n"
"Author: Jaime A. Quiroga P.\n"
"Inspired on https://github.com/jxfwinter/qt-material-stylesheet\n"
"Company: GTRONICK\n"
"Last updated: 04/12/2018, 15:00.\n"
"Available at: https://github.com/GTRONICK/QSS/blob/master/MaterialDark.qss\n"
"*/\n"
"QWidget{\n"
"    border-image: url(:/images/b.png ) 0 0 0 0 stretch stretch;\n"
"}\n"
"QDialog {\n"
"	background-color:#1e1d23;\n"
"}\n"
"QColorDialog {\n"
"	background-color:#1e1d23;\n"
"}\n"
"QTextEdit {\n"
"	background-color:#1e1d23;\n"
"	color: #a9b7c6;\n"
"}\n"
"QPlainTextEdit {\n"
"	selection-background-color:#007b50;\n"
"	background-color:#1e1d23;\n"
"	border-style: solid;\n"
"	border-top-color: transparent;\n"
"	border-right-color: transparent;\n"
"	border-left-color: transparent;\n"
"	border-bottom-color: transparent;\n"
"	border-width: 1px;\n"
"	color: #a9b7c6;\n"
"}\n"
"/*\n"
"Neon Style Sheet for QT Applications (QpushButton)\n"
"Author: Jaime A. Quiroga P.\n"
"Company: GTRONICK\n"
"Last updated: 24/10"
                        "/2020, 15:42.\n"
"Available at: https://github.com/GTRONICK/QSS/blob/master/NeonButtons.qss\n"
"*/\n"
"QPushButton{\n"
"	border-style: solid;\n"
"	border-color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"	color: #d3dae3;\n"
"	padding: 2px;\n"
"	background-color: #100E19;\n"
"}\n"
"QPushButton::default{\n"
"	border-style: solid;\n"
"	border-color: #ffffff;\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"	color: #FFFFFF;\n"
"	padding: 2px;\n"
"	background-color: #151a1e;\n"
"}\n"
"QPushButton:hover{\n"
"	border-style: solid;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:1, stop:0 #C0DB50, stop:0.4 #C0DB50, stop:0.5 #100E19, stop:1 #100E19);\n"
"    border-bottom-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:1, stop:0 #100E19, stop:0.5 #100E19, stop:0.6 #C0DB50, stop:1 #C0DB50);\n"
"    border-left-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #C0DB50, stop:0.3 #C0DB50, stop:0.7 #100E19, stop:1 #100E19);\n"
"    border-right-color: ql"
                        "ineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #C0DB50, stop:0.3 #C0DB50, stop:0.7 #100E19, stop:1 #100E19);\n"
"	border-width: 2px;\n"
"    border-radius: 1px;\n"
"	color: #d3dae3;\n"
"	padding: 2px;\n"
"}\n"
"QPushButton:pressed{\n"
"	border-style: solid;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:1, stop:0 #d33af1, stop:0.4 #d33af1, stop:0.5 #100E19, stop:1 #100E19);\n"
"    border-bottom-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:1, stop:0 #100E19, stop:0.5 #100E19, stop:0.6 #d33af1, stop:1 #d33af1);\n"
"    border-left-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #d33af1, stop:0.3 #d33af1, stop:0.7 #100E19, stop:1 #100E19);\n"
"    border-right-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #d33af1, stop:0.3 #d33af1, stop:0.7 #100E19, stop:1 #100E19);\n"
"	border-width: 2px;\n"
"    border-radius: 1px;\n"
"	color: #d3dae3;\n"
"	padding: 2px;\n"
"}\n"
"QLineEdit {\n"
"	border-width: 1px; border-radius: 4px;\n"
"	bor"
                        "der-color:rgb(255,255,255) ;\n"
"	border-style: inset;\n"
"	padding: 0 8px;\n"
"	color: #a9b7c6;\n"
"	background:#1e1d23;\n"
"	selection-background-color:#007b50;\n"
"	selection-color: #FFFFFF;\n"
"}\n"
"QLabel {\n"
"	color: #a9b7c6;\n"
"}\n"
"QLCDNumber {\n"
"	color: #37e6b4;\n"
"}\n"
"QProgressBar {\n"
"	text-align: center;\n"
"	color: rgb(240, 240, 240);\n"
"	border-width: 1px; \n"
"	border-radius: 10px;\n"
"	border-color: rgb(58, 58, 58);\n"
"	border-style: inset;\n"
"	background-color:#1e1d23;\n"
"}\n"
"QProgressBar::chunk {\n"
"	background-color: #038058;\n"
"	border-radius: 5px;\n"
"}\n"
"QMenuBar {\n"
"	background-color: #1e1d23;\n"
"}\n"
"QMenuBar::item {\n"
"	color: #a9b7c6;\n"
"  	spacing: 3px;\n"
"  	padding: 1px 4px;\n"
"  	background: #1e1d23;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"  	background:#1e1d23;\n"
"	color: #FFFFFF;\n"
"}\n"
"QMenu::item:selected {\n"
"	border-style: solid;\n"
"	border-top-color: transparent;\n"
"	border-right-color: transparent;\n"
"	border-left-color: #04b97f;\n"
""
                        "	border-bottom-color: transparent;\n"
"	border-left-width: 2px;\n"
"	color: #FFFFFF;\n"
"	padding-left:15px;\n"
"	padding-top:4px;\n"
"	padding-bottom:4px;\n"
"	padding-right:7px;\n"
"	background-color: #1e1d23;\n"
"}\n"
"QMenu::item {\n"
"	border-style: solid;\n"
"	border-top-color: transparent;\n"
"	border-right-color: transparent;\n"
"	border-left-color: transparent;\n"
"	border-bottom-color: transparent;\n"
"	border-bottom-width: 1px;\n"
"	border-style: solid;\n"
"	color: #a9b7c6;\n"
"	padding-left:17px;\n"
"	padding-top:4px;\n"
"	padding-bottom:4px;\n"
"	padding-right:7px;\n"
"	background-color: #1e1d23;\n"
"}\n"
"QMenu{\n"
"	background-color:#1e1d23;\n"
"}\n"
"QTabWidget {\n"
"	color:rgb(0,0,0);\n"
"	background-color:#1e1d23;\n"
"}\n"
"QTabWidget::pane {\n"
"		border-color: rgb(77,77,77);\n"
"		background-color:#1e1d23;\n"
"		border-style: solid;\n"
"		border-width: 1px;\n"
"    	border-radius: 6px;\n"
"}\n"
"QTabBar::tab {\n"
"	border-style: solid;\n"
"	border-top-color: transparent;\n"
"	border-right-c"
                        "olor: transparent;\n"
"	border-left-color: transparent;\n"
"	border-bottom-color: transparent;\n"
"	border-bottom-width: 1px;\n"
"	border-style: solid;\n"
"	color: #808086;\n"
"	padding: 3px;\n"
"	margin-left:3px;\n"
"	background-color: #1e1d23;\n"
"}\n"
"QTabBar::tab:selected, QTabBar::tab:last:selected, QTabBar::tab:hover {\n"
"  	border-style: solid;\n"
"	border-top-color: transparent;\n"
"	border-right-color: transparent;\n"
"	border-left-color: transparent;\n"
"	border-bottom-color: #04b97f;\n"
"	border-bottom-width: 2px;\n"
"	border-style: solid;\n"
"	color: #FFFFFF;\n"
"	padding-left: 3px;\n"
"	padding-bottom: 2px;\n"
"	margin-left:3px;\n"
"	background-color: #1e1d23;\n"
"}\n"
"\n"
"QCheckBox {\n"
"	color: #a9b7c6;\n"
"	padding: 2px;\n"
"}\n"
"QCheckBox:disabled {\n"
"	color: #808086;\n"
"	padding: 2px;\n"
"}\n"
"\n"
"QCheckBox:hover {\n"
"	border-radius:4px;\n"
"	border-style:solid;\n"
"	padding-left: 1px;\n"
"	padding-right: 1px;\n"
"	padding-bottom: 1px;\n"
"	padding-top: 1px;\n"
"	border-width:1px;\n"
""
                        "	border-color: rgb(87, 97, 106);\n"
"	background-color:#1e1d23;\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"\n"
"	height: 10px;\n"
"	width: 10px;\n"
"	border-style:solid;\n"
"	border-width: 1px;\n"
"	border-color: #04b97f;\n"
"	color: #a9b7c6;\n"
"	background-color: #04b97f;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"\n"
"	height: 10px;\n"
"	width: 10px;\n"
"	border-style:solid;\n"
"	border-width: 1px;\n"
"	border-color: #04b97f;\n"
"	color: #a9b7c6;\n"
"	background-color: transparent;\n"
"}\n"
"QRadioButton {\n"
"	color: #a9b7c6;\n"
"	background-color: #1e1d23;\n"
"	padding: 1px;\n"
"}\n"
"QRadioButton::indicator:checked {\n"
"	height: 10px;\n"
"	width: 10px;\n"
"	border-style:solid;\n"
"	border-radius:5px;\n"
"	border-width: 1px;\n"
"	border-color: #04b97f;\n"
"	color: #a9b7c6;\n"
"	background-color: #04b97f;\n"
"}\n"
"QRadioButton::indicator:!checked {\n"
"	height: 10px;\n"
"	width: 10px;\n"
"	border-style:solid;\n"
"	border-radius:5px;\n"
"	border-width: 1px;\n"
"	border-color: #04b97f;\n"
"	color: #a"
                        "9b7c6;\n"
"	background-color: transparent;\n"
"}\n"
"QStatusBar {\n"
"	color:#027f7f;\n"
"}\n"
"QSpinBox {\n"
"	color: #a9b7c6;	\n"
"	background-color: #1e1d23;\n"
"}\n"
"QDoubleSpinBox {\n"
"	color: #a9b7c6;	\n"
"	background-color: #1e1d23;\n"
"}\n"
"QTimeEdit {\n"
"	color: #a9b7c6;	\n"
"	background-color: #1e1d23;\n"
"}\n"
"QDateTimeEdit {\n"
"	color: #a9b7c6;	\n"
"	background-color: #1e1d23;\n"
"}\n"
"QDateEdit {\n"
"	color: #a9b7c6;	\n"
"	background-color: #1e1d23;\n"
"}\n"
"QComboBox {\n"
"	color: #a9b7c6;	\n"
"	background: #1e1d23;\n"
"}\n"
"QComboBox:editable {\n"
"	background: #1e1d23;\n"
"	color: #a9b7c6;\n"
"	selection-background-color: #1e1d23;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"	color: #a9b7c6;	\n"
"	background: #1e1d23;\n"
"	selection-color: #FFFFFF;\n"
"	selection-background-color: #1e1d23;\n"
"}\n"
"QComboBox:!editable:on, QComboBox::drop-down:editable:on {\n"
"	color: #a9b7c6;	\n"
"	background: #1e1d23;\n"
"}\n"
"QFontComboBox {\n"
"	color: #a9b7c6;	\n"
"	background-color: #1e1d23;\n"
""
                        "}\n"
"QToolBox {\n"
"	color: #a9b7c6;\n"
"	background-color: #1e1d23;\n"
"}\n"
"QToolBox::tab {\n"
"	color: #a9b7c6;\n"
"	background-color: #1e1d23;\n"
"}\n"
"QToolBox::tab:selected {\n"
"	color: #FFFFFF;\n"
"	background-color: #1e1d23;\n"
"}\n"
"QScrollArea {\n"
"	color: #FFFFFF;\n"
"	background-color: #1e1d23;\n"
"}\n"
"QSlider::groove:horizontal {\n"
"	height: 5px;\n"
"	background: #04b97f;\n"
"}\n"
"QSlider::groove:vertical {\n"
"	width: 5px;\n"
"	background: #04b97f;\n"
"}\n"
"QSlider::handle:horizontal {\n"
"	background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f);\n"
"	border: 1px solid #5c5c5c;\n"
"	width: 14px;\n"
"	margin: -5px 0;\n"
"	border-radius: 7px;\n"
"}\n"
"QSlider::handle:vertical {\n"
"	background: qlineargradient(x1:1, y1:1, x2:0, y2:0, stop:0 #b4b4b4, stop:1 #8f8f8f);\n"
"	border: 1px solid #5c5c5c;\n"
"	height: 14px;\n"
"	margin: 0 -5px;\n"
"	border-radius: 7px;\n"
"}\n"
"QSlider::add-page:horizontal {\n"
"    background: white;\n"
"}\n"
"QSlider::add-page:ver"
                        "tical {\n"
"    background: white;\n"
"}\n"
"QSlider::sub-page:horizontal {\n"
"    background: #04b97f;\n"
"}\n"
"QSlider::sub-page:vertical {\n"
"    background: #04b97f;\n"
"}"));
        label = new QLabel(Qwut);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 241, 61));
        label->setStyleSheet(QString::fromUtf8("QLabel#label {\n"
"    background-color: transparent;\n"
"    color: #FFE066;\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 27px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        progressBar = new QProgressBar(Qwut);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(60, 370, 691, 23));
        progressBar->setValue(0);
        label_2 = new QLabel(Qwut);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 100, 721, 41));
        label_2->setStyleSheet(QString::fromUtf8("QLabel#label_2 {\n"
"    background-color: transparent;\n"
"    color: #70CE07;\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 12px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        label_3 = new QLabel(Qwut);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 130, 781, 51));
        label_3->setStyleSheet(QString::fromUtf8("QLabel#label_3 {\n"
"    background-color: transparent;\n"
"    color: #70CE07;\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 12px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        label_4 = new QLabel(Qwut);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 180, 721, 41));
        label_4->setStyleSheet(QString::fromUtf8("QLabel#label_4 {\n"
"    background-color: transparent;\n"
"    color:  #70CE07;\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 12px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        label_5 = new QLabel(Qwut);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 220, 721, 41));
        label_5->setStyleSheet(QString::fromUtf8("QLabel#label_5 {\n"
"    background-color: transparent;\n"
"    color:  #70CE07;\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 12px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        label_6 = new QLabel(Qwut);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 260, 721, 41));
        label_6->setStyleSheet(QString::fromUtf8("QLabel#label_6 {\n"
"    background-color: transparent;\n"
"    color:  #70CE07;\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 12px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        label_7 = new QLabel(Qwut);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(40, 300, 721, 41));
        label_7->setStyleSheet(QString::fromUtf8("QLabel#label_7 {\n"
"    background-color: transparent;\n"
"    color:  #70CE07;\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 12px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        label_8 = new QLabel(Qwut);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(100, 400, 601, 41));
        label_8->setStyleSheet(QString::fromUtf8("QLabel#label_8{\n"
"    background-color: transparent;\n"
"    color: #FFE066;\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        label_9 = new QLabel(Qwut);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(210, 430, 311, 41));
        label_9->setStyleSheet(QString::fromUtf8("QLabel#label_9{\n"
"    background-color: transparent;\n"
"    color: #00E066;\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 11px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));

        retranslateUi(Qwut);

        QMetaObject::connectSlotsByName(Qwut);
    } // setupUi

    void retranslateUi(QWidget *Qwut)
    {
        Qwut->setWindowTitle(QCoreApplication::translate("Qwut", "Form", nullptr));
        label->setText(QCoreApplication::translate("Qwut", "Ezu-Hub", nullptr));
        label_2->setText(QCoreApplication::translate("Qwut", "Ezu-hub is servers we give to new programers and devolopers for be the best ", nullptr));
        label_3->setText(QCoreApplication::translate("Qwut", "start in this domain bcz we give that and evrething you need ", nullptr));
        label_4->setText(QCoreApplication::translate("Qwut", "to start your startup or ssas and your project also withe a big comuionty ", nullptr));
        label_5->setText(QCoreApplication::translate("Qwut", "and all this is free from us Ezu-Team to you mr.devoloper and programer ", nullptr));
        label_6->setText(QCoreApplication::translate("Qwut", "you need to join to us in our platform called Ezu-cpla ", nullptr));
        label_7->setText(QCoreApplication::translate("Qwut", "why you need to do that ? bcz we meck evrething Ezy", nullptr));
        label_8->setText(QCoreApplication::translate("Qwut", "Whait to check from evrething and tank to join to us", nullptr));
        label_9->setText(QCoreApplication::translate("Qwut", "Ezu-team.support.auth@gmail.com", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qwut: public Ui_Qwut {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKWINDOW_H
