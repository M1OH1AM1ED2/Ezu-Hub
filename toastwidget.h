#ifndef TOASTWIDGET_H
#define TOASTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QString>

class ToastWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ToastWidget(QWidget *parent = nullptr);

    static void showToast(QWidget *parent,
                const QString &message,
                int duration = 3000,
                int high = 0);

private:
    QLabel *messageLabel;
};

#endif // TOASTWIDGET_H
