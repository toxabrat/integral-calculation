#include <math.h>
#include "test_functions.h"
double f4(double x)
{
    return pow(2.0, x * x / 0.7) - 5;
}

double f5(double x)
{
    return pow(x, 3.0 / 4);
}

double f6(double x)
{
    return sin(x) + 4;
}
