#include "toastwidget.h"
#include <QVBoxLayout>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QTimer>
ToastWidget::ToastWidget(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint |
        Qt::Tool |
        Qt::WindowStaysOnTopHint);

    setAttribute(Qt::WA_TranslucentBackground);

    messageLabel = new QLabel(this);
    messageLabel->setAlignment(Qt::AlignCenter);

    messageLabel->setStyleSheet(
    "QLabel {"
    "background-color: #df0f85;"
    "color: white;"
    "border-radius: 14px;"
    "padding: 18px 30px;"
    "font-size: 13px;"
    "min-width: 360px;"
    "min-height: 40px;"
    "}"
);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(messageLabel);
    adjustSize();
}
void ToastWidget::showToast(QWidget *parent,
        const QString &message,
        int duration,
        int high)
{
    if (!parent)
        return;

    ToastWidget *toast = new ToastWidget(parent);

    toast->messageLabel->setText(message);
toast->adjustSize();

int x = (parent->width() - toast->width()) / 2 + toast->width();
int y = (parent->height() - toast->height()) / 2 - 300 - high ;

toast->move(x, y);
toast->show();

    QGraphicsOpacityEffect *effect =
        new QGraphicsOpacityEffect(toast);

    toast->setGraphicsEffect(effect);

    QPropertyAnimation *showAnimation =
        new QPropertyAnimation(effect, "opacity", toast);
    showAnimation->setDuration(250);
    showAnimation->setStartValue(0.0);
    showAnimation->setEndValue(1.0);
    showAnimation->start(QAbstractAnimation::DeleteWhenStopped);

    QTimer::singleShot(duration, [toast]()
    {
        QGraphicsOpacityEffect *effect =
            qobject_cast<QGraphicsOpacityEffect *>(
                toast->graphicsEffect()
            );

        QPropertyAnimation *hideAnimation =
            new QPropertyAnimation(effect, "opacity", toast);

        hideAnimation->setDuration(300);
        hideAnimation->setStartValue(1.0);
        hideAnimation->setEndValue(0.0);

        QObject::connect(hideAnimation,
            &QPropertyAnimation::finished,
            toast,
            &ToastWidget::deleteLater);

        hideAnimation->start(QAbstractAnimation::DeleteWhenStopped);
    });
}
