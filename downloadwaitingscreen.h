#ifndef DOWNLOADWAITINGSCREEN_H
#define DOWNLOADWAITINGSCREEN_H

#include <QWidget>

namespace Ui {
class downloadwaitingscreen;
}

class downloadwaitingscreen : public QWidget
{
    Q_OBJECT

public:
    explicit downloadwaitingscreen(QWidget *parent = nullptr);
    ~downloadwaitingscreen();

private:
    Ui::downloadwaitingscreen *ui;
};

#endif // DOWNLOADWAITINGSCREEN_H
