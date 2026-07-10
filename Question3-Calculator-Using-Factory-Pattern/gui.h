#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QLCDNumber>
#include <QDoubleSpinBox>
#include "operationfactory.h"

class GUI : public QWidget
{
    Q_OBJECT

public:
    GUI(QWidget *parent = nullptr);
    ~GUI();
public slots:
    void calculate();
    void clear();
    void overFlow();
private:
    QLCDNumber *lcdNumber;
    QDoubleSpinBox *firstDigitSpinBox;
    QDoubleSpinBox *secondDigitSpinBox;
    OperationFactory *operationFactory;

};
#endif // GUI_H
