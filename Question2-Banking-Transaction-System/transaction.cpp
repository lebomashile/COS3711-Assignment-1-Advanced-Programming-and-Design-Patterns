#include "transaction.h"


Transaction::Transaction(double amount, QDate date, QTime time, TransactionType type)
    :mAmount(amount),mDate(date),mTime(time),mType(type){

}

QString Transaction::toString() const
{
    QString type;

    if(mType == Deposit)
        type = "Deposit";
    else
        type = "Withdrawal";

    return QString("%1:R%2 on %3 at %4").arg(type,QString::number(mAmount),mDate.toString(),mTime.toString());
}
