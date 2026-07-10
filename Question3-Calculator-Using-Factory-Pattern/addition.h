#ifndef ADDITION_H
#define ADDITION_H

#include "operation.h"

class Addition : public Operation
{
public:
    double compute(double x, double y);

};

#endif // ADDITION_H
