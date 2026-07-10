#ifndef WRITER_H
#define WRITER_H

#include "transactionlist.h"

class Writer
{
public:
    Writer();
    bool writeToFile(TransactionList *t);
};

#endif // WRITER_H
