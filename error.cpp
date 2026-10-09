#include "error.h"
#include "ui_error.h"

ERROR::ERROR(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ERROR)
{
    ui->setupUi(this);
}

ERROR::~ERROR()
{
    delete ui;
}
