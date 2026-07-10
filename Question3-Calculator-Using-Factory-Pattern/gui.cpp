#include "gui.h"
#include <QGridLayout>
#include <QPushButton>
#include <QDebug>
#include "operationfactory.h"
#include <QMessageBox>

GUI::GUI(QWidget *parent)
    : QWidget(parent),
    lcdNumber(new QLCDNumber),
    firstDigitSpinBox(new QDoubleSpinBox),
    secondDigitSpinBox(new QDoubleSpinBox)

{
    this->setWindowTitle("Calculator");

    QGridLayout *layout = new QGridLayout(this);
    QPushButton *addButton = new QPushButton("+");
    QPushButton *subtractButton = new QPushButton("-");
    QPushButton *multiButton = new QPushButton("*");
    QPushButton *divisionButton = new QPushButton("/");
    QPushButton *clearButton = new QPushButton("Clear");

    operationFactory = OperationFactory::getInstance();
    firstDigitSpinBox->setMaximum(100000);
    secondDigitSpinBox->setMaximum(100000);

    layout->addWidget(firstDigitSpinBox,0,0);
    layout->addWidget(addButton,0,1);
    layout->addWidget(secondDigitSpinBox,1,0);
    layout->addWidget(subtractButton,1,1);
    layout->addWidget(lcdNumber,3,0);
    layout->addWidget(multiButton,3,1);
    layout->addWidget(clearButton,4,0);
    layout->addWidget(divisionButton,4,1);


    connect(addButton,SIGNAL(clicked()),this,SLOT(calculate()));
    connect(multiButton,SIGNAL(clicked()),this,SLOT(calculate()));
    connect(subtractButton,SIGNAL(clicked()),this,SLOT(calculate()));
    connect(divisionButton,SIGNAL(clicked()),this,SLOT(calculate()));
    connect(clearButton,SIGNAL(clicked()),this,SLOT(clear()));
    connect(lcdNumber,SIGNAL(overflow()),this,SLOT(overFlow()));
    setLayout(layout);
}

GUI::~GUI() {
    operationFactory->deleteInstance();
}

void GUI::calculate()
{
    double x = firstDigitSpinBox->value();
    double y = secondDigitSpinBox->value();
    double answer = 0;
    QString buttonText = qobject_cast<QPushButton*>(sender())->text();
    Operation *operation = NULL;

     if(buttonText == "+")
        operation = operationFactory->createOperation("+");
    else if(buttonText == "-")
        operation = operationFactory->createOperation("-");
    else if(buttonText == "/")
        operation = operationFactory->createOperation("/");
    else if(buttonText == "*")
        operation = operationFactory->createOperation("*");

    if(buttonText == "/"){
        if(y == 0){
            lcdNumber->display("Error");
            return;
        }

    }

    if(operation != NULL){
     answer = operation->compute(x,y);

    lcdNumber->display(answer);
}
    else
        lcdNumber->display("Error");

delete operation;
}

void GUI::clear()
{
    firstDigitSpinBox->setValue(0);
    secondDigitSpinBox->setValue(0);
    lcdNumber->display(0);
}

void GUI::overFlow()
{
    lcdNumber->display("Error");

}
