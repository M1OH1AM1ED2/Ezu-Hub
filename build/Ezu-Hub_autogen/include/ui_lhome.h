/********************************************************************************
** Form generated from reading UI file 'lhome.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LHOME_H
#define UI_LHOME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lhome
{
public:
    QTabWidget *ERROR;
    QWidget *home;
    QFrame *PicPor;
    QWidget *Meet;
    QPushButton *pushButton_8;
    QLineEdit *taskEdit;
    QPushButton *Give;
    QWidget *code;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *edo;
    QLineEdit *file;
    QPushButton *terminal;
    QPushButton *CCL;
    QPushButton *AllTask;
    QPushButton *RunCode;
    QPushButton *Exit;
    QPushButton *clear;
    QPushButton *openFiles;
    QPushButton *new_2;
    QPushButton *ERROR_2;
    QWidget *Profile;
    QPushButton *PIC;
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *pushButton_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_4;
    QLabel *label_6;
    QPushButton *pushButton_6;
    QLabel *label_7;
    QPushButton *pushButton_7;
    QFrame *PicPor_2;
    QWidget *Setting_2;
    QTabWidget *paramiter;
    QWidget *Editor;
    QLabel *label_8;
    QLabel *label_10;
    QComboBox *LPB;
    QPushButton *Rest;
    QPushButton *Commit;
    QComboBox *autoSaveBox;
    QLabel *label_12;
    QSpinBox *TabSpace;
    QLabel *label_13;
    QLabel *label_14;
    QFontComboBox *fontComboBox;
    QSpinBox *FontSIze;
    QWidget *Appearnce;
    QLabel *label_11;
    QComboBox *update;
    QLabel *label_15;
    QComboBox *AutoLogin;
    QWidget *notifications;
    QLabel *label_9;
    QCheckBox *NotificatoinsBox_2;
    QComboBox *noti;

    void setupUi(QWidget *Lhome)
    {
        if (Lhome->objectName().isEmpty())
            Lhome->setObjectName("Lhome");
        Lhome->setEnabled(true);
        Lhome->resize(1920, 1080);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Lhome->sizePolicy().hasHeightForWidth());
        Lhome->setSizePolicy(sizePolicy);
        Lhome->setSizeIncrement(QSize(1920, 1080));
        Lhome->setStyleSheet(QString::fromUtf8("/*\n"
"Material Dark Style Sheet for QT Applications\n"
"Author: Jaime A. Quiroga P.\n"
"Inspired on https://github.com/jxfwinter/qt-material-stylesheet\n"
"Company: GTRONICK\n"
"Last updated: 04/12/2018, 15:00.\n"
"Available at: https://github.com/GTRONICK/QSS/blob/master/MaterialDark.qss\n"
"*/\n"
"QWidget#Lhome {\n"
"    background-color:#030A08\n"
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
"Last updated: 24/10/2020, 15:42.\n"
"Available "
                        "at: https://github.com/GTRONICK/QSS/blob/master/NeonButtons.qss\n"
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
"    border-right-color: qlineargradient(spread:pad, x1"
                        ":0, y1:1, x2:0, y2:0, stop:0 #C0DB50, stop:0.3 #C0DB50, stop:0.7 #100E19, stop:1 #100E19);\n"
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
"	border-color:rgb(255,255,255) ;"
                        "\n"
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
"	border-top-color: transparent;\n"
"	border-right-color: transparent;\n"
"	border-left-color: #04b97f;\n"
"	border-bottom-color: tran"
                        "sparent;\n"
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
"	border-right-color: transparent;\n"
"	bo"
                        "rder-left-color: transparent;\n"
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
"	border-color: rgb(87,"
                        " 97, 106);\n"
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
"	color: #a9b7c6;\n"
"	background"
                        "-color: transparent;\n"
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
"}\n"
"QToolBox {\n"
""
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
"QSlider::add-page:vertical {\n"
"    backg"
                        "round: white;\n"
"}\n"
"QSlider::sub-page:horizontal {\n"
"    background: #04b97f;\n"
"}\n"
"QSlider::sub-page:vertical {\n"
"    background: #04b97f;\n"
"}"));
        ERROR = new QTabWidget(Lhome);
        ERROR->setObjectName("ERROR");
        ERROR->setGeometry(QRect(0, 0, 1951, 1101));
        ERROR->setCursor(QCursor(Qt::ArrowCursor));
        ERROR->setStyleSheet(QString::fromUtf8("QWidget#TAB {\n"
"    background-color:#1e1d23;\n"
"	\n"
" \n"
"}"));
        ERROR->setTabPosition(QTabWidget::North);
        ERROR->setIconSize(QSize(28, 22));
        ERROR->setElideMode(Qt::ElideMiddle);
        ERROR->setUsesScrollButtons(true);
        ERROR->setDocumentMode(false);
        ERROR->setTabsClosable(false);
        ERROR->setMovable(false);
        ERROR->setTabBarAutoHide(true);
        home = new QWidget();
        home->setObjectName("home");
        home->setStyleSheet(QString::fromUtf8("QWidget#home {\n"
"    background-color:#1e1d23;\n"
"	border-image: url(:/images/s.jpg) 0 0 0 0 stretch stretch;\n"
"\n"
"}"));
        PicPor = new QFrame(home);
        PicPor->setObjectName("PicPor");
        PicPor->setGeometry(QRect(10, 20, 201, 201));
        PicPor->setStyleSheet(QString::fromUtf8("border-image: url(:/images/s.jpg) 0 0 0 0 stretch stretch;\n"
"border-radius: 75px;\n"
"\n"
""));
        PicPor->setFrameShape(QFrame::StyledPanel);
        PicPor->setFrameShadow(QFrame::Raised);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("user-home");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        ERROR->addTab(home, icon, QString());
        Meet = new QWidget();
        Meet->setObjectName("Meet");
        Meet->setStyleSheet(QString::fromUtf8("QWidget#Meet {\n"
"   background-color:#1e1d23;\n"
"	border-image: url(:/images/s.jpg) 0 0 0 0 stretch stretch;\n"
"\n"
"}"));
        pushButton_8 = new QPushButton(Meet);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(1520, 40, 191, 61));
        taskEdit = new QLineEdit(Meet);
        taskEdit->setObjectName("taskEdit");
        taskEdit->setGeometry(QRect(560, 40, 941, 61));
        Give = new QPushButton(Meet);
        Give->setObjectName("Give");
        Give->setGeometry(QRect(350, 40, 201, 61));
        QIcon icon1;
        iconThemeName = QString::fromUtf8("mail-mark-unread");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        ERROR->addTab(Meet, icon1, QString());
        code = new QWidget();
        code->setObjectName("code");
        code->setStyleSheet(QString::fromUtf8("QWidget#code {\n"
"\n"
"	 background-color:#1e1d23;\n"
"\n"
"}"));
        verticalLayoutWidget = new QWidget(code);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 60, 1911, 931));
        edo = new QVBoxLayout(verticalLayoutWidget);
        edo->setObjectName("edo");
        edo->setContentsMargins(0, 0, 0, 0);
        file = new QLineEdit(code);
        file->setObjectName("file");
        file->setGeometry(QRect(1400, 10, 461, 41));
        terminal = new QPushButton(code);
        terminal->setObjectName("terminal");
        terminal->setGeometry(QRect(860, 10, 171, 41));
        terminal->setStyleSheet(QString::fromUtf8("\n"
"QPushButton#terminal{\n"
"	background-color:rgb(237, 51, 59);\n"
"font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 17px;\n"
"    font-weight: bold;\n"
"color:rbg(0,0,0);\n"
"}"));
        QIcon icon2;
        iconThemeName = QString::fromUtf8("utilities-terminal");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        terminal->setIcon(icon2);
        terminal->setIconSize(QSize(20, 20));
        CCL = new QPushButton(code);
        CCL->setObjectName("CCL");
        CCL->setGeometry(QRect(1040, 10, 171, 41));
        CCL->setStyleSheet(QString::fromUtf8("QPushButton#CCL{\n"
"	background-color:rgb(53, 132, 228);\n"
"font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 17px;\n"
"    font-weight: bold;\n"
"}"));
        QIcon icon3;
        iconThemeName = QString::fromUtf8("document-save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        CCL->setIcon(icon3);
        CCL->setIconSize(QSize(20, 20));
        AllTask = new QPushButton(code);
        AllTask->setObjectName("AllTask");
        AllTask->setGeometry(QRect(10, 10, 151, 41));
        QIcon icon4;
        iconThemeName = QString::fromUtf8("user-away");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        AllTask->setIcon(icon4);
        RunCode = new QPushButton(code);
        RunCode->setObjectName("RunCode");
        RunCode->setGeometry(QRect(1220, 10, 171, 41));
        RunCode->setStyleSheet(QString::fromUtf8("QPushButton#RunCode{\n"
"	background-color:rgb(51, 209, 122);\n"
"font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 17px;\n"
"    font-weight: bold;\n"
"}"));
        QIcon icon5;
        iconThemeName = QString::fromUtf8("media-playback-start");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon5 = QIcon::fromTheme(iconThemeName);
        } else {
            icon5.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        RunCode->setIcon(icon5);
        RunCode->setIconSize(QSize(20, 21));
        Exit = new QPushButton(code);
        Exit->setObjectName("Exit");
        Exit->setGeometry(QRect(700, 10, 151, 41));
        Exit->setStyleSheet(QString::fromUtf8("\n"
"QPushButton#Exit{\n"
"	background-color:rgb(255, 255, 255);\n"
"font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 17px;\n"
"    font-weight: bold;\n"
"color:rgb(224, 27, 36);\n"
"}"));
        QIcon icon6;
        iconThemeName = QString::fromUtf8("go-previous");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon6 = QIcon::fromTheme(iconThemeName);
        } else {
            icon6.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        Exit->setIcon(icon6);
        Exit->setIconSize(QSize(20, 20));
        clear = new QPushButton(code);
        clear->setObjectName("clear");
        clear->setGeometry(QRect(350, 10, 171, 41));
        QIcon icon7;
        iconThemeName = QString::fromUtf8("document-revert");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon7 = QIcon::fromTheme(iconThemeName);
        } else {
            icon7.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        clear->setIcon(icon7);
        openFiles = new QPushButton(code);
        openFiles->setObjectName("openFiles");
        openFiles->setGeometry(QRect(170, 10, 171, 41));
        openFiles->setStyleSheet(QString::fromUtf8(""));
        QIcon icon8;
        iconThemeName = QString::fromUtf8("document-open");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon8 = QIcon::fromTheme(iconThemeName);
        } else {
            icon8.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        openFiles->setIcon(icon8);
        openFiles->setIconSize(QSize(20, 20));
#if QT_CONFIG(shortcut)
        openFiles->setShortcut(QString::fromUtf8(""));
#endif // QT_CONFIG(shortcut)
        openFiles->setCheckable(false);
        new_2 = new QPushButton(code);
        new_2->setObjectName("new_2");
        new_2->setGeometry(QRect(530, 10, 161, 41));
        QIcon icon9;
        iconThemeName = QString::fromUtf8("document-new");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon9 = QIcon::fromTheme(iconThemeName);
        } else {
            icon9.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        new_2->setIcon(icon9);
        new_2->setIconSize(QSize(20, 20));
        ERROR_2 = new QPushButton(code);
        ERROR_2->setObjectName("ERROR_2");
        ERROR_2->setGeometry(QRect(1870, 10, 41, 41));
        ERROR_2->setStyleSheet(QString::fromUtf8("QPushButton#ERROR_2{\n"
"	background-color:rgb(255, 255, 255);\n"
"font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 10px;\n"
"    font-weight: bold;\n"
"color:rgb(224, 27, 36);\n"
"}"));
        QIcon icon10;
        iconThemeName = QString::fromUtf8("computer");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon10 = QIcon::fromTheme(iconThemeName);
        } else {
            icon10.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        ERROR->addTab(code, icon10, QString());
        Profile = new QWidget();
        Profile->setObjectName("Profile");
        Profile->setStyleSheet(QString::fromUtf8("QWidget#Profile {\n"
"    background-color:#1e1d23;\n"
"	border-image: url(:/images/s.jpg) 0 0 0 0 stretch stretch;\n"
"\n"
"}"));
        PIC = new QPushButton(Profile);
        PIC->setObjectName("PIC");
        PIC->setGeometry(QRect(20, 10, 161, 151));
        PIC->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 75px;\n"
"}"));
        PIC->setAutoExclusive(false);
        PIC->setAutoDefault(false);
        PIC->setFlat(false);
        pushButton_2 = new QPushButton(Profile);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(560, 20, 181, 71));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-color:transparent;\n"
"	background-color: transparent;\n"
"    color: rgb(220, 138, 221);\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"\n"
"}"));
        label = new QLabel(Profile);
        label->setObjectName("label");
        label->setGeometry(QRect(400, 30, 141, 61));
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
        pushButton_3 = new QPushButton(Profile);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(560, 90, 171, 61));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-color:transparent;\n"
"	background-color: transparent;\n"
"    color: rgb(220, 138, 221);\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"\n"
"}"));
        label_2 = new QLabel(Profile);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(400, 90, 181, 61));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("/* \330\263\330\252\330\247\331\212\331\204 \331\204\331\204\331\200 QLabel \330\247\331\204\330\256\330\247\330\265 \330\250\330\271\331\206\331\210\330\247\331\206 \330\247\331\204\330\252\330\267\330\250\331\212\331\202 */\n"
"QLabel#label_2{\n"
"    background-color: transparent;\n"
"    color: #FFE066;\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 27px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        label_3 = new QLabel(Profile);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(420, 150, 141, 61));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("/* \330\263\330\252\330\247\331\212\331\204 \331\204\331\204\331\200 QLabel \330\247\331\204\330\256\330\247\330\265 \330\250\330\271\331\206\331\210\330\247\331\206 \330\247\331\204\330\252\330\267\330\250\331\212\331\202 */\n"
"QLabel#label_3{\n"
"    background-color: transparent;\n"
"    color: #FFE066;\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 27px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        label_4 = new QLabel(Profile);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(590, 150, 571, 61));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("/* \330\263\330\252\330\247\331\212\331\204 \331\204\331\204\331\200 QLabel \330\247\331\204\330\256\330\247\330\265 \330\250\330\271\331\206\331\210\330\247\331\206 \330\247\331\204\330\252\330\267\330\250\331\212\331\202 */\n"
"QLabel#label_4{\n"
"    background-color: transparent;\n"
"    color: rgb(220, 138, 221);\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        label_5 = new QLabel(Profile);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(450, 220, 111, 61));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("/* \330\263\330\252\330\247\331\212\331\204 \331\204\331\204\331\200 QLabel \330\247\331\204\330\256\330\247\330\265 \330\250\330\271\331\206\331\210\330\247\331\206 \330\247\331\204\330\252\330\267\330\250\331\212\331\202 */\n"
"QLabel#label_5{\n"
"    background-color: transparent;\n"
"    color: #FFE066;\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 27px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        pushButton_4 = new QPushButton(Profile);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(590, 210, 161, 61));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-color:transparent;\n"
"	background-color: transparent;\n"
"    color: rgb(220, 138, 221);\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"\n"
"}"));
        label_6 = new QLabel(Profile);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(460, 300, 111, 61));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("/* \330\263\330\252\330\247\331\212\331\204 \331\204\331\204\331\200 QLabel \330\247\331\204\330\256\330\247\330\265 \330\250\330\271\331\206\331\210\330\247\331\206 \330\247\331\204\330\252\330\267\330\250\331\212\331\202 */\n"
"QLabel#label_6{\n"
"    background-color: transparent;\n"
"    color: #FFE066;\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 27px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        pushButton_6 = new QPushButton(Profile);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(610, 300, 231, 61));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-color:transparent;\n"
"	background-color: transparent;\n"
"    color: rgb(220, 138, 221);\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"\n"
"}"));
        label_7 = new QLabel(Profile);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(460, 370, 111, 61));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("/* \330\263\330\252\330\247\331\212\331\204 \331\204\331\204\331\200 QLabel \330\247\331\204\330\256\330\247\330\265 \330\250\330\271\331\206\331\210\330\247\331\206 \330\247\331\204\330\252\330\267\330\250\331\212\331\202 */\n"
"QLabel#label_7{\n"
"    background-color: transparent;\n"
"    color: #FFE066;\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 27px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"}"));
        pushButton_7 = new QPushButton(Profile);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(640, 360, 191, 61));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-color:transparent;\n"
"	background-color: transparent;\n"
"    color: rgb(220, 138, 221);\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 3px;\n"
"    padding: 10px;\n"
"\n"
"}"));
        PicPor_2 = new QFrame(Profile);
        PicPor_2->setObjectName("PicPor_2");
        PicPor_2->setGeometry(QRect(10, 10, 331, 291));
        PicPor_2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/s.jpg) 0 0 0 0 stretch stretch;\n"
"\n"
"border-radius: 80px;\n"
"\n"
"\n"
""));
        PicPor_2->setFrameShape(QFrame::StyledPanel);
        PicPor_2->setFrameShadow(QFrame::Raised);
        QIcon icon11;
        iconThemeName = QString::fromUtf8("user-available");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon11 = QIcon::fromTheme(iconThemeName);
        } else {
            icon11.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        ERROR->addTab(Profile, icon11, QString());
        Setting_2 = new QWidget();
        Setting_2->setObjectName("Setting_2");
        Setting_2->setStyleSheet(QString::fromUtf8("QWidget#Setting_2 {\n"
"   background-color:#1e1d23;\n"
"}"));
        paramiter = new QTabWidget(Setting_2);
        paramiter->setObjectName("paramiter");
        paramiter->setGeometry(QRect(0, 0, 1921, 1051));
        paramiter->setToolTipDuration(-8);
        paramiter->setStyleSheet(QString::fromUtf8("QWidget#notificatoins {\n"
"    background-color:#1e1d23;\n"
"	border-image: url(:/images/s.jpg) 0 0 0 0 stretch stretch;\n"
"\n"
"}"));
        paramiter->setIconSize(QSize(20, 20));
        paramiter->setDocumentMode(false);
        paramiter->setTabsClosable(false);
        paramiter->setMovable(false);
        paramiter->setTabBarAutoHide(false);
        Editor = new QWidget();
        Editor->setObjectName("Editor");
        Editor->setStyleSheet(QString::fromUtf8("QWidget#Editor {\n"
"    background-color:#1e1d23;\n"
"	border-image: url(:/images/s.jpg) 0 0 0 0 stretch stretch;\n"
"\n"
"}"));
        label_8 = new QLabel(Editor);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 10, 181, 51));
        label_8->setStyleSheet(QString::fromUtf8("QLabel#label_8 {\n"
"    background-color: transparent;\n"
"    color: #FFE066;\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 19px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 1px;\n"
"    padding: 1px;\n"
"}"));
        label_10 = new QLabel(Editor);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 50, 191, 51));
        label_10->setStyleSheet(QString::fromUtf8("QLabel#label_10 {\n"
"    background-color: transparent;\n"
"    color: #FFE066;\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 19px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 1px;\n"
"    padding: 1px;\n"
"}"));
        LPB = new QComboBox(Editor);
        QIcon icon12;
        iconThemeName = QString::fromUtf8("text-x-script");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon12 = QIcon::fromTheme(iconThemeName);
        } else {
            icon12.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        LPB->addItem(icon12, QString());
        QIcon icon13;
        iconThemeName = QString::fromUtf8("emblem-system");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon13 = QIcon::fromTheme(iconThemeName);
        } else {
            icon13.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        LPB->addItem(icon13, QString());
        QIcon icon14;
        iconThemeName = QString::fromUtf8("text-x-generic");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon14 = QIcon::fromTheme(iconThemeName);
        } else {
            icon14.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        LPB->addItem(icon14, QString());
        QIcon icon15;
        iconThemeName = QString::fromUtf8("x-office-document");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon15 = QIcon::fromTheme(iconThemeName);
        } else {
            icon15.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        LPB->addItem(icon15, QString());
        QIcon icon16;
        iconThemeName = QString::fromUtf8("x-office-spreadsheet");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon16 = QIcon::fromTheme(iconThemeName);
        } else {
            icon16.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        LPB->addItem(icon16, QString());
        QIcon icon17;
        iconThemeName = QString::fromUtf8("document-properties");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon17 = QIcon::fromTheme(iconThemeName);
        } else {
            icon17.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        LPB->addItem(icon17, QString());
        QIcon icon18;
        iconThemeName = QString::fromUtf8("font-x-generic");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon18 = QIcon::fromTheme(iconThemeName);
        } else {
            icon18.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        LPB->addItem(icon18, QString());
        LPB->addItem(QString());
        LPB->addItem(QString());
        LPB->addItem(QString());
        LPB->addItem(QString());
        LPB->addItem(QString());
        LPB->setObjectName("LPB");
        LPB->setGeometry(QRect(240, 60, 191, 31));
        Rest = new QPushButton(Editor);
        Rest->setObjectName("Rest");
        Rest->setGeometry(QRect(1740, 10, 161, 41));
        Rest->setStyleSheet(QString::fromUtf8("QPushButton#Rest{\n"
"	background-color:rgb(255, 255, 255);\n"
"font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 17px;\n"
"    font-weight: bold;\n"
"color:rgb(237, 51, 59);\n"
"}"));
        Commit = new QPushButton(Editor);
        Commit->setObjectName("Commit");
        Commit->setGeometry(QRect(1560, 10, 171, 41));
        Commit->setStyleSheet(QString::fromUtf8("QPushButton#Commit{\n"
"	background-color:rgb(53, 132, 228);\n"
"font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 17px;\n"
"    font-weight: bold;\n"
"}"));
        Commit->setIcon(icon3);
        Commit->setIconSize(QSize(20, 20));
        autoSaveBox = new QComboBox(Editor);
        autoSaveBox->addItem(QString());
        autoSaveBox->addItem(QString());
        autoSaveBox->setObjectName("autoSaveBox");
        autoSaveBox->setGeometry(QRect(240, 20, 191, 29));
        label_12 = new QLabel(Editor);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(20, 100, 141, 51));
        label_12->setStyleSheet(QString::fromUtf8("QLabel#label_12 {\n"
"    background-color: transparent;\n"
"    color: #FFE066;\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 19px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 1px;\n"
"    padding: 1px;\n"
"}"));
        TabSpace = new QSpinBox(Editor);
        TabSpace->setObjectName("TabSpace");
        TabSpace->setGeometry(QRect(240, 110, 191, 30));
        label_13 = new QLabel(Editor);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(20, 150, 141, 51));
        label_13->setStyleSheet(QString::fromUtf8("QLabel#label_13 {\n"
"    background-color: transparent;\n"
"    color: #FFE066;\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 19px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 1px;\n"
"    padding: 1px;\n"
"}"));
        label_14 = new QLabel(Editor);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(20, 200, 141, 51));
        label_14->setStyleSheet(QString::fromUtf8("QLabel#label_14 {\n"
"    background-color: transparent;\n"
"    color: #FFE066;\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 19px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 1px;\n"
"    padding: 1px;\n"
"}"));
        fontComboBox = new QFontComboBox(Editor);
        fontComboBox->setObjectName("fontComboBox");
        fontComboBox->setGeometry(QRect(240, 160, 191, 29));
        FontSIze = new QSpinBox(Editor);
        FontSIze->setObjectName("FontSIze");
        FontSIze->setGeometry(QRect(240, 210, 191, 30));
        QIcon icon19;
        iconThemeName = QString::fromUtf8("emblem-documents");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon19 = QIcon::fromTheme(iconThemeName);
        } else {
            icon19.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        paramiter->addTab(Editor, icon19, QString());
        Appearnce = new QWidget();
        Appearnce->setObjectName("Appearnce");
        Appearnce->setEnabled(true);
        Appearnce->setLayoutDirection(Qt::LeftToRight);
        Appearnce->setAutoFillBackground(false);
        Appearnce->setStyleSheet(QString::fromUtf8("QWidget#Appearnce {\n"
"    background-color:#1e1d23;\n"
"	border-image: url(:/images/s.jpg) 0 0 0 0 stretch stretch;\n"
"\n"
"}"));
        label_11 = new QLabel(Appearnce);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 10, 151, 51));
        label_11->setStyleSheet(QString::fromUtf8("QLabel#label_11 {\n"
"    background-color: transparent;\n"
"    color: #FFE066;\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 19px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 1px;\n"
"    padding: 1px;\n"
"}"));
        update = new QComboBox(Appearnce);
        update->addItem(QString());
        update->addItem(QString());
        update->setObjectName("update");
        update->setGeometry(QRect(220, 20, 171, 29));
        label_15 = new QLabel(Appearnce);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(10, 50, 151, 51));
        label_15->setStyleSheet(QString::fromUtf8("QLabel#label_15 {\n"
"    background-color: transparent;\n"
"    color: #FFE066;\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 19px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 1px;\n"
"    padding: 1px;\n"
"}"));
        AutoLogin = new QComboBox(Appearnce);
        AutoLogin->addItem(QString());
        AutoLogin->addItem(QString());
        AutoLogin->setObjectName("AutoLogin");
        AutoLogin->setGeometry(QRect(220, 60, 171, 29));
        QIcon icon20;
        iconThemeName = QString::fromUtf8("applications-development");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon20 = QIcon::fromTheme(iconThemeName);
        } else {
            icon20.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        paramiter->addTab(Appearnce, icon20, QString());
        notifications = new QWidget();
        notifications->setObjectName("notifications");
        notifications->setStyleSheet(QString::fromUtf8("QWidget#notifications {\n"
"    background-color:#1e1d23;\n"
"	border-image: url(:/images/s.jpg) 0 0 0 0 stretch stretch;\n"
"\n"
"}"));
        label_9 = new QLabel(notifications);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 10, 181, 51));
        label_9->setStyleSheet(QString::fromUtf8("QLabel#label_9 {\n"
"    background-color: transparent;\n"
"    color: #FFE066;\n"
"    font-family: \"Trajan Pro\", \"Cinzel\", \"Georgia\", serif;\n"
"    font-size: 19px;\n"
"    font-weight: bold;\n"
"    letter-spacing: 1px;\n"
"    padding: 1px;\n"
"}"));
        NotificatoinsBox_2 = new QCheckBox(notifications);
        NotificatoinsBox_2->setObjectName("NotificatoinsBox_2");
        NotificatoinsBox_2->setGeometry(QRect(200, 30, 16, 16));
        noti = new QComboBox(notifications);
        noti->addItem(QString());
        noti->addItem(QString());
        noti->setObjectName("noti");
        noti->setGeometry(QRect(240, 20, 171, 31));
        QIcon icon21;
        iconThemeName = QString::fromUtf8("view-restore");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon21 = QIcon::fromTheme(iconThemeName);
        } else {
            icon21.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        paramiter->addTab(notifications, icon21, QString());
        QIcon icon22;
        iconThemeName = QString::fromUtf8("applications-other");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon22 = QIcon::fromTheme(iconThemeName);
        } else {
            icon22.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        ERROR->addTab(Setting_2, icon22, QString());

        retranslateUi(Lhome);

        ERROR->setCurrentIndex(3);
        PIC->setDefault(false);
        paramiter->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Lhome);
    } // setupUi

    void retranslateUi(QWidget *Lhome)
    {
        Lhome->setWindowTitle(QCoreApplication::translate("Lhome", "Form", nullptr));
        ERROR->setTabText(ERROR->indexOf(home), QCoreApplication::translate("Lhome", "  Home           ", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Lhome", "Send", nullptr));
        Give->setText(QCoreApplication::translate("Lhome", "GIVE", nullptr));
        ERROR->setTabText(ERROR->indexOf(Meet), QCoreApplication::translate("Lhome", "  Meet                  ", nullptr));
        terminal->setText(QCoreApplication::translate("Lhome", " Terminl", nullptr));
#if QT_CONFIG(shortcut)
        terminal->setShortcut(QCoreApplication::translate("Lhome", "Shift+X", nullptr));
#endif // QT_CONFIG(shortcut)
        CCL->setText(QCoreApplication::translate("Lhome", " Save", nullptr));
#if QT_CONFIG(shortcut)
        CCL->setShortcut(QCoreApplication::translate("Lhome", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        AllTask->setText(QCoreApplication::translate("Lhome", " MyTask", nullptr));
        RunCode->setText(QCoreApplication::translate("Lhome", " Run", nullptr));
#if QT_CONFIG(shortcut)
        RunCode->setShortcut(QCoreApplication::translate("Lhome", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        Exit->setText(QCoreApplication::translate("Lhome", "  Exit", nullptr));
#if QT_CONFIG(shortcut)
        Exit->setShortcut(QCoreApplication::translate("Lhome", "Ctrl+Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        clear->setText(QCoreApplication::translate("Lhome", " clear", nullptr));
        openFiles->setText(QCoreApplication::translate("Lhome", " open", nullptr));
        new_2->setText(QCoreApplication::translate("Lhome", "  New", nullptr));
        ERROR_2->setText(QCoreApplication::translate("Lhome", "ERROR", nullptr));
        ERROR->setTabText(ERROR->indexOf(code), QCoreApplication::translate("Lhome", "             Code             ", nullptr));
        PIC->setText(QCoreApplication::translate("Lhome", "USER", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Lhome", "rank", nullptr));
        label->setText(QCoreApplication::translate("Lhome", "Ranked", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Lhome", "name", nullptr));
        label_2->setText(QCoreApplication::translate("Lhome", "username", nullptr));
        label_3->setText(QCoreApplication::translate("Lhome", "GitHub", nullptr));
        label_4->setText(QCoreApplication::translate("Lhome", "git", nullptr));
        label_5->setText(QCoreApplication::translate("Lhome", "Team", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Lhome", "Team", nullptr));
        label_6->setText(QCoreApplication::translate("Lhome", "NOP", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Lhome", "number of project", nullptr));
        label_7->setText(QCoreApplication::translate("Lhome", "RIT", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Lhome", "Roll in Team", nullptr));
        ERROR->setTabText(ERROR->indexOf(Profile), QCoreApplication::translate("Lhome", "     Profile         ", nullptr));
#if QT_CONFIG(statustip)
        paramiter->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        label_8->setText(QCoreApplication::translate("Lhome", "auto save of file", nullptr));
        label_10->setText(QCoreApplication::translate("Lhome", "Select your long", nullptr));
        LPB->setItemText(0, QCoreApplication::translate("Lhome", "C", nullptr));
        LPB->setItemText(1, QCoreApplication::translate("Lhome", "C++", nullptr));
        LPB->setItemText(2, QCoreApplication::translate("Lhome", "C#", nullptr));
        LPB->setItemText(3, QCoreApplication::translate("Lhome", "Python", nullptr));
        LPB->setItemText(4, QCoreApplication::translate("Lhome", "Java", nullptr));
        LPB->setItemText(5, QCoreApplication::translate("Lhome", "PHP", nullptr));
        LPB->setItemText(6, QCoreApplication::translate("Lhome", "Roby", nullptr));
        LPB->setItemText(7, QCoreApplication::translate("Lhome", "dart", nullptr));
        LPB->setItemText(8, QCoreApplication::translate("Lhome", "Rust", nullptr));
        LPB->setItemText(9, QCoreApplication::translate("Lhome", "assombley", nullptr));
        LPB->setItemText(10, QCoreApplication::translate("Lhome", "Go", nullptr));
        LPB->setItemText(11, QString());

        Rest->setText(QCoreApplication::translate("Lhome", "Rest", nullptr));
        Commit->setText(QCoreApplication::translate("Lhome", " Commit", nullptr));
#if QT_CONFIG(shortcut)
        Commit->setShortcut(QCoreApplication::translate("Lhome", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        autoSaveBox->setItemText(0, QCoreApplication::translate("Lhome", "Enable", nullptr));
        autoSaveBox->setItemText(1, QCoreApplication::translate("Lhome", "Disable", nullptr));

        label_12->setText(QCoreApplication::translate("Lhome", "Tab Space ", nullptr));
        label_13->setText(QCoreApplication::translate("Lhome", "Font Family", nullptr));
        label_14->setText(QCoreApplication::translate("Lhome", "Font Size", nullptr));
        paramiter->setTabText(paramiter->indexOf(Editor), QCoreApplication::translate("Lhome", "                Editor               ", nullptr));
        label_11->setText(QCoreApplication::translate("Lhome", "auto update", nullptr));
        update->setItemText(0, QCoreApplication::translate("Lhome", "Enable", nullptr));
        update->setItemText(1, QCoreApplication::translate("Lhome", "Disable", nullptr));

        label_15->setText(QCoreApplication::translate("Lhome", "auto login", nullptr));
        AutoLogin->setItemText(0, QCoreApplication::translate("Lhome", "Enable", nullptr));
        AutoLogin->setItemText(1, QCoreApplication::translate("Lhome", "Disable", nullptr));

        paramiter->setTabText(paramiter->indexOf(Appearnce), QCoreApplication::translate("Lhome", "             Appearnce              ", nullptr));
        label_9->setText(QCoreApplication::translate("Lhome", " Notifications ", nullptr));
        NotificatoinsBox_2->setText(QCoreApplication::translate("Lhome", "CheckBox", nullptr));
        noti->setItemText(0, QCoreApplication::translate("Lhome", "Disable", nullptr));
        noti->setItemText(1, QCoreApplication::translate("Lhome", "Enable", nullptr));

        paramiter->setTabText(paramiter->indexOf(notifications), QCoreApplication::translate("Lhome", "            notifications            ", nullptr));
        ERROR->setTabText(ERROR->indexOf(Setting_2), QCoreApplication::translate("Lhome", " Settings           ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lhome: public Ui_Lhome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LHOME_H
