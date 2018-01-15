#ifndef SLOWBUTTON_H
#define SLOWBUTTON_H

#include <QPushButton>

class SlowButton : public QPushButton
{
public:
    SlowButton(QWidget *parent = Q_NULLPTR);
    ~SlowButton();

protected:
    void enterEvent(QEvent *event) Q_DECL_OVERRIDE;
    void leaveEvent(QEvent *event) Q_DECL_OVERRIDE;
};

#endif // SLOWBUTTON_H
