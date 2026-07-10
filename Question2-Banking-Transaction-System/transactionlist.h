#ifndef TRANSACTIONLIST_H
#define TRANSACTIONLIST_H

#include <QList>
#include "transaction.h"


class TransactionList
{
public:
    ~TransactionList();
    void addTransaction(Transaction *t);
    QList<Transaction*> returnList() const;
    static TransactionList *getInstance();
private:
    TransactionList();
    static TransactionList *instance;
    QList<Transaction*> tList;
};

#endif // TRANSACTIONLIST_H
