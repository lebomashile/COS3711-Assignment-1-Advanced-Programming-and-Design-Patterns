#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QDoubleSpinBox>
#include "transactionlist.h"

class Gui : public QWidget
{
    Q_OBJECT

public:
    Gui(QWidget *parent = nullptr);
    ~Gui();
public slots:
    void deposit();
    void withDrawal();
    void toFile();
private:
    QDoubleSpinBox *amountSpinBox;
    TransactionList *transList;

};
#endif // GUI_H
