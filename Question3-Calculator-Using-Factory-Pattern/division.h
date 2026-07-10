#ifndef DIVISION_H
#define DIVISION_H

#include "operation.h"

class Division : public Operation
{
public:
    double compute(double x, double y);

};

#endif // DIVISION_H
