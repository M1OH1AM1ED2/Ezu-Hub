#ifndef ERROR_H
#define ERROR_H

#include <QWidget>

namespace Ui {
class ERROR;
}

class ERROR : public QWidget
{
    Q_OBJECT

public:
    explicit ERROR(QWidget *parent = nullptr);
    ~ERROR();

private:
    Ui::ERROR *ui;
};

#endif // ERROR_H
