#include "gui.h"
#include <QGridLayout>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QDate>
#include <QDebug>
#include <QMessageBox>
#include "writer.h"

Gui::Gui(QWidget *parent)
    : QWidget(parent),
    amountSpinBox(new QDoubleSpinBox)

{
    setWindowTitle("Banking transactions");
    setMinimumSize(400,100);
    transList= TransactionList::getInstance();

    QGridLayout *layout = new QGridLayout(this);
    QLabel *amountLabel = new QLabel("Amount");
    QLabel *dateNameLabel = new QLabel("Date");
    QLabel *dateValueLabel = new QLabel(QDate::currentDate().toString());
    QPushButton *depositButton = new QPushButton("Deposit");
    QPushButton *withdrawalButton = new QPushButton("Withdrawal");
    QPushButton *toFileButton = new QPushButton("To File");


    layout->addWidget(dateNameLabel,0,0);
    layout->addWidget(dateValueLabel,0,1);
    layout->addWidget(amountLabel,1,0);
    layout->addWidget(amountSpinBox,1,1);
    layout->addWidget(depositButton,2,0);
    layout->addWidget(toFileButton,2,1);
    layout->addWidget(withdrawalButton,3,0);

    connect(depositButton,SIGNAL(clicked()),this,SLOT(deposit()));
    connect(withdrawalButton,SIGNAL(clicked()),this,SLOT(withDrawal()));
    connect(toFileButton,SIGNAL(clicked()),this,SLOT(toFile()));
    setLayout(layout);


}

Gui::~Gui() {}

void Gui::deposit()
{
    Transaction *t = new Transaction(amountSpinBox->value(),QDate::currentDate(),QTime::currentTime(),Transaction::Deposit);

    qDebug() << t->toString();

    transList->addTransaction(t);

}

void Gui::withDrawal()
{
    Transaction *t = new Transaction(amountSpinBox->value(),QDate::currentDate(),QTime::currentTime(),Transaction::Withdrawal);

    qDebug()<< t->toString();
    transList->addTransaction(t);

}

void Gui::toFile()
{
    Writer writer;

    if(writer.writeToFile(transList))
        QMessageBox::information(this,"Successful","Write successful");


}
