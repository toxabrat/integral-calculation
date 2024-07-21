#include <stdio.h>
#include "math_operation.h"
#include "functions.h"
#include "ArgParse.h"

int main(int argc, char* argv[]) 
{
   if(argc != 1) {
      arg_parce(argc, argv);
      return 0;
   }
   double eps1 = 1e-6, eps2 = 1e-6;
   double point_f1_f3 = root(f1, f3, 1, 2, eps1);
   double point_f2_f3 = root(f2, f3, 4, 5, eps1);
   double point_f1_f2 = root(f1, f2, 5, 6, eps1);
   double ans = integral(f1, point_f1_f3, point_f1_f2, eps2);
   ans -= integral(f3, point_f1_f3, point_f2_f3, eps2);
   ans -= integral(f2, point_f2_f3, point_f1_f2, eps2);
   printf("%.06lf", ans);
   return 0;
}


