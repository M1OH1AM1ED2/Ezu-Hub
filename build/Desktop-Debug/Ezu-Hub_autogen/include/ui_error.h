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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ERROR
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QRadioButton *E0x635d976b;
    QLabel *label_6;
    QRadioButton *E0x3f5d9e6b;
    QLabel *label_7;
    QRadioButton *E0x001d9e6b;
    QLabel *label_8;
    QRadioButton *E0xff1d9e2f;
    QPushButton *Commit;
    QPushButton *Rest;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;

    void setupUi(QWidget *ERROR)
    {
        if (ERROR->objectName().isEmpty())
            ERROR->setObjectName("ERROR");
        ERROR->resize(958, 515);
        ERROR->setStyleSheet(QString::fromUtf8("/*\n"
"Material Dark Style Sheet for QT Applications\n"
"Author: Jaime A. Quiroga P.\n"
"Inspired on https://github.com/jxfwinter/qt-material-stylesheet\n"
"Company: GTRONICK\n"
"Last updated: 04/12/2018, 15:00.\n"
"Available at: https://github.com/GTRONICK/QSS/blob/master/MaterialDark.qss\n"
"*/\n"
"QMainWindow #ERROR{\n"
"	background-color:#1e1d23;\n"
"	border-image: url(:/images/s.jpg) 0 0 0 0 stretch stretch;\n"
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
"Com"
                        "pany: GTRONICK\n"
"Last updated: 24/10/2020, 15:42.\n"
"Available at: https://github.com/GTRONICK/QSS/blob/master/NeonButtons.qss\n"
"*/\n"
"QPushButton::icon{\n"
"	color:#FFFFFF;\n"
"}\n"
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
"    border-left-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #C0DB"
                        "50, stop:0.3 #C0DB50, stop:0.7 #100E19, stop:1 #100E19);\n"
"    border-right-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #C0DB50, stop:0.3 #C0DB50, stop:0.7 #100E19, stop:1 #100E19);\n"
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
"	p"
                        "adding: 2px;\n"
"}\n"
"QLineEdit {\n"
"	border-width: 1px; border-radius: 4px;\n"
"	border-color:rgb(255,255,255) ;\n"
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
"	background-color: #04b97f;\n"
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
"	border-top-color:"
                        " transparent;\n"
"	border-right-color: transparent;\n"
"	border-left-color: #04b97f;\n"
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
"QTabBar"
                        "::tab {\n"
"	border-style: solid;\n"
"	border-top-color: transparent;\n"
"	border-right-color: transparent;\n"
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
"	pad"
                        "ding-right: 1px;\n"
"	padding-bottom: 1px;\n"
"	padding-top: 1px;\n"
"	border-width:1px;\n"
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
"	border-style:soli"
                        "d;\n"
"	border-radius:5px;\n"
"	border-width: 1px;\n"
"	border-color: #04b97f;\n"
"	color: #a9b7c6;\n"
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
"	background:"
                        " #1e1d23;\n"
"}\n"
"QFontComboBox {\n"
"	color: #a9b7c6;	\n"
"	background-color: #1e1d23;\n"
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
"}"
                        "\n"
"QSlider::add-page:horizontal {\n"
"    background: white;\n"
"}\n"
"QSlider::add-page:vertical {\n"
"    background: white;\n"
"}\n"
"QSlider::sub-page:horizontal {\n"
"    background: #04b97f;\n"
"}\n"
"QSlider::sub-page:vertical {\n"
"    background: #04b97f;\n"
"}"));
        label = new QLabel(ERROR);
        label->setObjectName("label");
        label->setGeometry(QRect(-50, -10, 191, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Trajan Pro")});
        font.setBold(true);
        font.setItalic(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("/* \330\263\330\252\330\247\331\212\331\204 \331\204\331\204\331\200 QLabel \330\247\331\204\330\256\330\247\330\265 \330\250\330\271\331\206\331\210\330\247\331\206 \330\247\331\204\330\252\330\267\330\250\331\212\331\202 */\n"
"QLabel#label {\n"
"    background-color: transparent;\n"
"    color: #FFE066;\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 27px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        label_2 = new QLabel(ERROR);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 50, 311, 41));
        label_2->setStyleSheet(QString::fromUtf8("QLabel#label_2 {\n"
"    background-color: transparent;\n"
"    color:rgb(246, 211, 45);\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        label_3 = new QLabel(ERROR);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 80, 311, 41));
        label_3->setStyleSheet(QString::fromUtf8("QLabel#label_3 {\n"
"    background-color: transparent;\n"
"    color:rgb(246, 211, 45);\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        label_4 = new QLabel(ERROR);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(120, -10, 121, 61));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("/* \330\263\330\252\330\247\331\212\331\204 \331\204\331\204\331\200 QLabel \330\247\331\204\330\256\330\247\330\265 \330\250\330\271\331\206\331\210\330\247\331\206 \330\247\331\204\330\252\330\267\330\250\331\212\331\202 */\n"
"QLabel#label_4 {\n"
"    background-color: transparent;\n"
"    color: rgb(224, 27, 36);\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 27px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        label_5 = new QLabel(ERROR);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 260, 311, 41));
        label_5->setStyleSheet(QString::fromUtf8("QLabel#label_5 {\n"
"    background-color: transparent;\n"
"    color:rgb(237, 51, 59);\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        E0x635d976b = new QRadioButton(ERROR);
        E0x635d976b->setObjectName("E0x635d976b");
        E0x635d976b->setGeometry(QRect(350, 270, 16, 16));
        label_6 = new QLabel(ERROR);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 310, 361, 41));
        label_6->setStyleSheet(QString::fromUtf8("QLabel#label_6 {\n"
"    background-color: transparent;\n"
"    color:rgb(237, 51, 59);\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        E0x3f5d9e6b = new QRadioButton(ERROR);
        E0x3f5d9e6b->setObjectName("E0x3f5d9e6b");
        E0x3f5d9e6b->setGeometry(QRect(380, 320, 16, 16));
        label_7 = new QLabel(ERROR);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(530, 260, 361, 41));
        label_7->setStyleSheet(QString::fromUtf8("QLabel#label_7 {\n"
"    background-color: transparent;\n"
"    color:rgb(237, 51, 59);\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        E0x001d9e6b = new QRadioButton(ERROR);
        E0x001d9e6b->setObjectName("E0x001d9e6b");
        E0x001d9e6b->setGeometry(QRect(900, 270, 16, 16));
        label_8 = new QLabel(ERROR);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(530, 300, 351, 41));
        label_8->setStyleSheet(QString::fromUtf8("QLabel#label_8 {\n"
"    background-color: transparent;\n"
"    color:rgb(237, 51, 59);\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        E0xff1d9e2f = new QRadioButton(ERROR);
        E0xff1d9e2f->setObjectName("E0xff1d9e2f");
        E0xff1d9e2f->setGeometry(QRect(900, 310, 16, 16));
        Commit = new QPushButton(ERROR);
        Commit->setObjectName("Commit");
        Commit->setGeometry(QRect(280, 410, 171, 41));
        Commit->setStyleSheet(QString::fromUtf8("QPushButton#Commit{\n"
"	background-color:rgb(53, 132, 228);\n"
"font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 17px;\n"
"    font-weight: bold;\n"
"}"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("document-save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        Commit->setIcon(icon);
        Commit->setIconSize(QSize(20, 20));
        Rest = new QPushButton(ERROR);
        Rest->setObjectName("Rest");
        Rest->setGeometry(QRect(460, 410, 161, 41));
        Rest->setStyleSheet(QString::fromUtf8("QPushButton#Rest{\n"
"	background-color:rgb(255, 255, 255);\n"
"font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 17px;\n"
"    font-weight: bold;\n"
"color:rgb(237, 51, 59);\n"
"}"));
        label_9 = new QLabel(ERROR);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 460, 891, 41));
        label_9->setStyleSheet(QString::fromUtf8("QLabel#label_9 {\n"
"    background-color: transparent;\n"
"    color:rgb(246, 211, 45);\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        label_10 = new QLabel(ERROR);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(210, -10, 171, 61));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("/* \330\263\330\252\330\247\331\212\331\204 \331\204\331\204\331\200 QLabel \330\247\331\204\330\256\330\247\330\265 \330\250\330\271\331\206\331\210\330\247\331\206 \330\247\331\204\330\252\330\267\330\250\331\212\331\202 */\n"
"QLabel#label_10 {\n"
"    background-color: transparent;\n"
"    color: rgb(53, 132, 228);\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 27px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        label_11 = new QLabel(ERROR);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(0, 110, 271, 41));
        label_11->setStyleSheet(QString::fromUtf8("QLabel#label_11 {\n"
"    background-color: transparent;\n"
"    color:rgb(246, 211, 45);\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        label_12 = new QLabel(ERROR);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(50, 140, 151, 51));
        label_12->setStyleSheet(QString::fromUtf8("QLabel#label_12 {\n"
"    background-color: transparent;\n"
"    color:rgb(241, 10, 225);\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));

        retranslateUi(ERROR);

        QMetaObject::connectSlotsByName(ERROR);
    } // setupUi

    void retranslateUi(QWidget *ERROR)
    {
        ERROR->setWindowTitle(QCoreApplication::translate("ERROR", "Form", nullptr));
        label->setText(QCoreApplication::translate("ERROR", "    Ezu-Hub", nullptr));
        label_2->setText(QCoreApplication::translate("ERROR", "Ezu-hub servers helper With ", nullptr));
        label_3->setText(QCoreApplication::translate("ERROR", "Errors pless check error ", nullptr));
        label_4->setText(QCoreApplication::translate("ERROR", ".Error", nullptr));
        label_5->setText(QCoreApplication::translate("ERROR", "Error with GUI (0x635d976b)", nullptr));
        E0x635d976b->setText(QString());
        label_6->setText(QCoreApplication::translate("ERROR", "Error with network (0x3f5d9e6b)", nullptr));
        E0x3f5d9e6b->setText(QString());
        label_7->setText(QCoreApplication::translate("ERROR", "Error with updates (0x001d9e6b)", nullptr));
        E0x001d9e6b->setText(QString());
        label_8->setText(QCoreApplication::translate("ERROR", "Error with version (0xff1d9e2f)", nullptr));
        E0xff1d9e2f->setText(QString());
        Commit->setText(QCoreApplication::translate("ERROR", " Commit", nullptr));
#if QT_CONFIG(shortcut)
        Commit->setShortcut(QCoreApplication::translate("ERROR", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        Rest->setText(QCoreApplication::translate("ERROR", "Concel", nullptr));
        label_9->setText(QCoreApplication::translate("ERROR", "if you can't found your problem hir pless contact with us by Team-Ezu-Hub.support", nullptr));
        label_10->setText(QCoreApplication::translate("ERROR", ".Support", nullptr));
        label_11->setText(QCoreApplication::translate("ERROR", "Ezu-Hub servers Well fix", nullptr));
        label_12->setText(QCoreApplication::translate("ERROR", "The problem", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ERROR: public Ui_ERROR {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERROR_H
