#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDate>
#include <QTime>

class Transaction
{
public:
    enum TransactionType{
        Deposit,
        Withdrawal
    };
    Transaction(double amount, QDate date,QTime time,TransactionType type);
    QString toString() const;
private:
    double mAmount;
    QDate mDate;
    QTime mTime;
    TransactionType mType;
};

#endif // TRANSACTION_H
