#include "operationfactory.h"
#include "division.h"
#include "multiplication.h"
#include "addition.h"
#include "subtraction.h"

OperationFactory* OperationFactory::onlyInstance = NULL;

OperationFactory::OperationFactory()
{
}

OperationFactory* OperationFactory::getInstance()
{
    if(onlyInstance== NULL)
        onlyInstance = new OperationFactory();
    return onlyInstance;
}

void OperationFactory::deleteInstance()
{
    delete onlyInstance;
}

Operation *OperationFactory::createOperation(QString operation)
{
    if(operation == "/")
        return new Division;
    else if(operation == "+")
        return new Addition;
    else if(operation == "-")
        return new Subtraction;
    else if(operation == "*")
        return new Multiplication;
    else
        return nullptr;



}
