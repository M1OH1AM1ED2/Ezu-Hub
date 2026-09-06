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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lhome
{
public:
    QTabWidget *TAB;
    QWidget *Setting;
    QPushButton *pushButton;
    QWidget *Home;
    QWidget *Profile;
    QPushButton *PIC;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
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
    QWidget *code;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *edo;
    QWidget *Meet;

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
        TAB = new QTabWidget(Lhome);
        TAB->setObjectName("TAB");
        TAB->setGeometry(QRect(0, 0, 1951, 1101));
        TAB->setCursor(QCursor(Qt::OpenHandCursor));
        TAB->setStyleSheet(QString::fromUtf8("QWidget#TAB {\n"
"    background-color:#1e1d23;\n"
"	\n"
" \n"
"}"));
        TAB->setTabBarAutoHide(true);
        Setting = new QWidget();
        Setting->setObjectName("Setting");
        Setting->setStyleSheet(QString::fromUtf8("QWidget#Setting {\n"
"    background-color:#1e1d23;\n"
"	border-image: url(:/images/s.jpg) 0 0 0 0 stretch stretch;\n"
"\n"
"}"));
        pushButton = new QPushButton(Setting);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 50, 101, 61));
        pushButton->setStyleSheet(QString::fromUtf8("pushButton{\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("system-shutdown");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(40, 40));
        QIcon icon1;
        iconThemeName = QString::fromUtf8("user-home");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        TAB->addTab(Setting, icon1, QString());
        Home = new QWidget();
        Home->setObjectName("Home");
        Home->setStyleSheet(QString::fromUtf8("QWidget#Home {\n"
"   background-color:#1e1d23;\n"
"	border-image: url(:/images/s.jpg) 0 0 0 0 stretch stretch;\n"
"\n"
"}"));
        QIcon icon2;
        iconThemeName = QString::fromUtf8("applications-other");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        TAB->addTab(Home, icon2, QString());
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
        pushButton_2->setGeometry(QRect(340, 20, 181, 71));
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
        pushButton_5 = new QPushButton(Profile);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(10, 170, 181, 251));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"		border-radius: 75px;\n"
"			}"));
        label = new QLabel(Profile);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 20, 141, 61));
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
        pushButton_3->setGeometry(QRect(390, 90, 171, 61));
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
        label_2->setGeometry(QRect(220, 90, 181, 61));
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
        label_3->setGeometry(QRect(230, 160, 141, 61));
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
        label_4->setGeometry(QRect(380, 160, 571, 61));
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
        label_5->setGeometry(QRect(240, 230, 111, 61));
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
        pushButton_4->setGeometry(QRect(340, 230, 251, 61));
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
        label_6->setGeometry(QRect(250, 300, 111, 61));
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
        pushButton_6->setGeometry(QRect(350, 300, 231, 61));
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
        label_7->setGeometry(QRect(260, 360, 111, 61));
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
        pushButton_7->setGeometry(QRect(350, 360, 191, 61));
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
        QIcon icon3;
        iconThemeName = QString::fromUtf8("user-available");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        TAB->addTab(Profile, icon3, QString());
        code = new QWidget();
        code->setObjectName("code");
        code->setStyleSheet(QString::fromUtf8("QWidget#code {\n"
"   background-color:#1e1d23;\n"
"	border-image: url(:/images/s.jpg) 0 0 0 0 stretch stretch;\n"
"\n"
"}"));
        verticalLayoutWidget = new QWidget(code);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(190, 0, 1731, 1081));
        edo = new QVBoxLayout(verticalLayoutWidget);
        edo->setObjectName("edo");
        edo->setContentsMargins(0, 0, 0, 0);
        TAB->addTab(code, QString());
        Meet = new QWidget();
        Meet->setObjectName("Meet");
        Meet->setStyleSheet(QString::fromUtf8("QWidget#Meet {\n"
"   background-color:#1e1d23;\n"
"	border-image: url(:/images/s.jpg) 0 0 0 0 stretch stretch;\n"
"\n"
"}"));
        TAB->addTab(Meet, QString());

        retranslateUi(Lhome);

        TAB->setCurrentIndex(0);
        PIC->setDefault(false);


        QMetaObject::connectSlotsByName(Lhome);
    } // setupUi

    void retranslateUi(QWidget *Lhome)
    {
        Lhome->setWindowTitle(QCoreApplication::translate("Lhome", "Form", nullptr));
        pushButton->setText(QString());
        TAB->setTabText(TAB->indexOf(Setting), QCoreApplication::translate("Lhome", "  Home           ", nullptr));
        TAB->setTabText(TAB->indexOf(Home), QCoreApplication::translate("Lhome", " Settings           ", nullptr));
        PIC->setText(QCoreApplication::translate("Lhome", "USER", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Lhome", "rank", nullptr));
        pushButton_5->setText(QString());
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
        TAB->setTabText(TAB->indexOf(Profile), QCoreApplication::translate("Lhome", "     Profile         ", nullptr));
        TAB->setTabText(TAB->indexOf(code), QCoreApplication::translate("Lhome", "             Code             ", nullptr));
        TAB->setTabText(TAB->indexOf(Meet), QCoreApplication::translate("Lhome", "          Meet             ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lhome: public Ui_Lhome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LHOME_H
