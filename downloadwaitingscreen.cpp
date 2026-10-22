#include "downloadwaitingscreen.h"
#include "ui_downloadwaitingscreen.h"

downloadwaitingscreen::downloadwaitingscreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::downloadwaitingscreen)
{
    ui->setupUi(this);
}

downloadwaitingscreen::~downloadwaitingscreen()
{
    delete ui;
}
