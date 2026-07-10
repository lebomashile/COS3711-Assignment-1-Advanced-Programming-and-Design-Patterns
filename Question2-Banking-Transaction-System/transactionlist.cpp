#include "transactionlist.h"

TransactionList *TransactionList::instance = 0;

TransactionList::TransactionList() {
    tList.clear();
}

TransactionList::~TransactionList()
{
    qDeleteAll(tList);
}

void TransactionList::addTransaction(Transaction *t)
{
    tList.append(t);
}

QList<Transaction *> TransactionList::returnList() const
{
    return tList;
}

TransactionList *TransactionList::getInstance()
{
    if (!instance) {
        instance = new TransactionList;
    }
    return instance;

}
