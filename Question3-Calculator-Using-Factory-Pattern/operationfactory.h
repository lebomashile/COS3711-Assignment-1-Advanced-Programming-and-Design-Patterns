#ifndef OPERATIONFACTORY_H
#define OPERATIONFACTORY_H

#include "operation.h"
#include <QString>

class OperationFactory
{
public:
    Operation* createOperation(QString operation) ;
    static OperationFactory* getInstance();
    static void deleteInstance();

private:
    OperationFactory();
    static OperationFactory* onlyInstance;
};
#endif // OPERATIONFACTORY_H
