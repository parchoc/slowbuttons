#include "slowbutton.h"
#include <windows.h>
#include <QEvent>

SlowButton::SlowButton(QWidget *parent) :
    QPushButton(parent)
{
}

SlowButton::~SlowButton()
{
}

void SlowButton::enterEvent(QEvent *event)
{
//    SystemParametersInfo(SPI_GETMOUSESPEED, 0, speed, 0);

    int speed = 5;
    SystemParametersInfo(SPI_SETMOUSESPEED,
                         0,
                         (LPVOID)speed,
                         0);

//    setText(QString::number(speed[0]));
    event->accept();
}

void SlowButton::leaveEvent(QEvent *event)
{
    int speed = 10;
    SystemParametersInfo(SPI_SETMOUSESPEED,
                         0,
                         (LPVOID)speed,
                         0);

    event->accept();
}
