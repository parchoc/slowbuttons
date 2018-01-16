#ifndef SLOWBUTTON_H
#define SLOWBUTTON_H

#include <QPushButton>

class SlowButton : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(int speed READ speed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(Direction direction READ direction WRITE setDirection NOTIFY directionChanged)

public:
    enum Direction {FastToSlow = 0, SlowToFast = 1, Constant = 2};
    Q_ENUM(Direction)

    SlowButton(QWidget *parent = Q_NULLPTR);
    ~SlowButton();
    void setSpeed(int speed);
    int speed();
    void setDirection(Direction direction);
    Direction direction() const;

protected:
    void enterEvent(QEvent *event) Q_DECL_OVERRIDE;
    void leaveEvent(QEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *e) Q_DECL_OVERRIDE;

private:
    int m_speed;
    Direction m_direction;

signals:
    void speedChanged(int);
    void directionChanged(Direction);
};

#endif // SLOWBUTTON_H
