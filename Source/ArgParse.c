#include "ArgParse.h"
#include "math_operation.h"
#include "functions.h"
#include <string.h>
#include <math.h>
#include <stdio.h>

#define abs(x) (x < 0 ? -x : x)

void arg_parce(int argc, char* argv[])
{
    for( int i = 1; i < argc; i++) {
        if(!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")) {
            
            _help();

        } else if(!strcmp(argv[i], "-r") || !strcmp(argv[i], "--root")) {
            
            _root();

        } else if(!strcmp(argv[i], "-i") || !strcmp(argv[i], "--iterrations")) {
            
            _iterarions();

        } else if(!strcmp(argv[i], "-R") || !strcmp(argv[i], "--test-root")) {
            
            i += 1;
            _test_root(argv[i]);

        } else if(!strcmp(argv[i], "-I") || !strcmp(argv[i], "--test-integral")){
            
            i += 1;
            _test_integral(argv[i]);
        }
    }
}

void _help(void)
{
    printf("-h --help  will display a description of the launch options\n");
    printf("-r --root  displays the intersection points of curves\n");
    printf("-i --iterrations  prints the number of iterations to count intersection points\n");
    printf("-R --test-root finds the intersection points of segments on an interval and prints the error, options(F1:F2:A:B:E:R)\n");
    printf("-I --test-integral  calculates the integral of a function over an interval and prints the error, options(F:A:B:E:R)\n\n");
    return;
}
void _root(void) 
{
    double eps1 = 1e-6;
    double point_f1_f3 = root(f1, f3, 1, 2, eps1);
    double point_f2_f3 = root(f2, f3, 4, 5, eps1);
    double point_f1_f2 = root(f1, f2, 5, 6, eps1);
    printf("%.6lf %.6lf %.6lf\n\n", point_f1_f2, point_f1_f3, point_f2_f3);
    return;
}

void _iterarions(void) 
{
    printf("f1 intersec f2 for %d iterarions\n", get_root_iterations(root, f1, f2, 5, 6, 1e-6));
    printf("f1 intersec f3 for %d iterarions\n", get_root_iterations(root, f1, f3, 1, 2, 1e-6));
    printf("f2 intersec f3 for %d iterarions\n\n", get_root_iterations(root, f2, f3, 4, 5, 1e-6));
    return;
}

void _test_root(char * argv) 
{
    int F1, F2;
    double a, b, e, r;
    char skip;
    sscanf(argv, "%d%c%d%c%lf%c%lf%c%lf%c%lf", &F1, &skip, &F2, &skip, &a, &skip, &b, &skip, &e, &skip, &r);
    double (*f[3])(double) = {&f1, &f2, &f3};
    double ans = root(f[F1 - 1], f[F2 - 1], a, b, e);
    double scale = pow(10, 5);
    double abs_ans = round(ans * scale) / scale;
    printf("%.5lf %.5lf %.7lf\n\n", ans, abs(abs_ans - r), abs(ans - r));
    return;
}

void _test_integral(char *argv) 
{
    int F1;
    double a, b, e, r;
    char skip;
    sscanf(argv, "%d%c%lf%c%lf%c%lf%c%lf", &F1, &skip, &a, &skip, &b, &skip, &e, &skip, &r);
    double (*f[3])(double) = {f1, f2, f3};
    double ans = integral(f[F1 - 1], a, b, e);
    double scale = pow(10, 5);
    double abs_ans = round(ans * scale) / scale;
    printf("%.5lf %.5lf %.7lf\n\n", ans, abs(abs_ans - r), abs(ans - r));
    return;
}

#undef abs