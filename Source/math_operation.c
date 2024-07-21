#include "math_operation.h"
#include <stdio.h>
#include <math.h> 

static int number_of_iterations = 0; // глобальная переменная для подсчета итераций в функции root

double root (double (*f)(double), double (*g)(double), double a, double b, double eps1) 
{
    if (b - a < eps1) {
        return (b + a) / 2;
    }

    number_of_iterations += 1;
    double c = (b + a) / 2;
    double f_a = f(a) - g(a), f_c = f(c) - g(c);
    if(signbit (f_a) != signbit (f_c) && (signbit (f_a) == 0 || signbit (f_c) == 0)) { // сравнение знаков числа
        return root(f, g, a, c, eps1);
    } else {
        return root(f, g, c, b, eps1);
    }

}

int get_root_iterations(double (*ff) (double (*)(double), double (*)(double), double, double, double), \
                                double (*f)(double), double (*g)(double), double a, double b, double eps1)
{   
    number_of_iterations = 0;
    ff(f, g, a, b, eps1);
    int ans = number_of_iterations;
    number_of_iterations = 0;
    return ans;
}

#define abs(x) (x < 0 ? -x : x)

double integral (double (*f)(double), double a, double b, double eps2) 
{
    
    double I_n = 0, I_2n = 0;
    const double p = 1.0 / 3;
    long long n = 10;
    while(n <= 1000000 || abs(I_n - I_2n) * p > eps2) {
        double sum = 0;
        double h = (b - a) / n;
        for(int i = 0; i <= n; i++) {
            if(i % n == 0) {
                sum += 0.5 * f(a + i * h);
            } else {
                sum += f(a + i * h);
            }
        }
        sum *= h;
        I_n = I_2n;
        I_2n = sum;
        n *= 2;
    }

    return I_2n;
}

#undef abs

