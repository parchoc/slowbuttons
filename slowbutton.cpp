#include "slowbutton.h"
#include <windows.h>
#include <QEvent>
#include <QMouseEvent>
#include <QtMath>
#include <math.h>
#include <QDebug>

SlowButton::SlowButton(QWidget *parent) :
    QPushButton(parent)
{
    m_speed = 7;
    setMouseTracking(true);
    m_direction = FastToSlow;
}

SlowButton::~SlowButton()
{
}

void SlowButton::setSpeed(int speed)
{
    m_speed = speed;
    emit speedChanged(speed);
}

int SlowButton::speed()
{
    return m_speed;
}

void SlowButton::setDirection(SlowButton::Direction direction)
{
    m_direction = direction;
    emit directionChanged(direction);
}

SlowButton::Direction SlowButton::direction() const
{
    return m_direction;
}

void SlowButton::enterEvent(QEvent *event)
{
//    SystemParametersInfo(SPI_GETMOUSESPEED, 0, speed, 0);

    if(m_direction == Constant)
        SystemParametersInfo(SPI_SETMOUSESPEED,
                             0,
                             (LPVOID)m_speed,
                             0);

    event->accept();
}

void SlowButton::leaveEvent(QEvent *event)
{
    int _speed = 10;
    SystemParametersInfo(SPI_SETMOUSESPEED,
                         0,
                         (LPVOID)_speed,
                         0);

    event->accept();
}

void SlowButton::mouseMoveEvent(QMouseEvent *e)
{
    int _speed;

    switch (m_direction) {
    case 0:
    {
        //fast->slow
        qreal _x = qSqrt(height()*height()+width()*width())/20;
        _speed = fmax(qFloor(qSqrt(qPow(e->pos().x() - width()/2, 2) + qPow(e->pos().y() - height()/2, 2))/_x), m_speed);
        break;
    }
    case 1:
    {
        //slow->fast
        qreal _x = qSqrt(height()*height()+width()*width())/2;
        _speed = fmax(qFloor(_x/qSqrt(qPow(e->pos().x() - width()/2, 2) + qPow(e->pos().y() - height()/2, 2))), m_speed);
        break;
    }
    }

//    qDebug() << _speed;
    SystemParametersInfo(SPI_SETMOUSESPEED,
                         0,
                         (LPVOID)_speed,
                         0);
    e->accept();
}
