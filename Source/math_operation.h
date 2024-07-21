
double root (double (*f)(double), double (*g)(double), double a, double b, double eps1);

int get_root_iterations(double (*ff) (double (*)(double), double (*)(double), double, double, double), \
                                double (*f)(double), double (*g)(double), double a, double b, double eps1);
                            
double integral (double (*f)(double), double a, double b, double eps2);

int root_iterarions (double a, double eps1);