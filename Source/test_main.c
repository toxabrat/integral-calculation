#include <stdio.h>
#include "math_operation.h"
#include "test_functions.h"

int main(int argc, char* argv[]) {
   printf("----------------------test-root----------------------");
   printf("\n\n                      Test1");
   printf("\nfunction1: 2 ^ (x * x / 0.7) - 5");
   printf("\nfunction2: x ^ (3 / 4)");
   printf("\ninterval: [1, 2]");
   printf("\nanswer: 1.361 , program: %.6lf",root(f4, f5, 1, 2, 1e-8));
   printf("\n\n                      Test2");
   printf("\nfunction1: sin(x) + 4");
   printf("\nfunction2: x ^ (3 / 4)");
   printf("\ninterval: [6, 7]");
   printf("\nanswer: 6.223 , program: %.6lf",root(f5, f6, 6, 7, 1e-8));
   printf("\n\n                      Test3");
   printf("\nfunction1: sin(x) + 4");
   printf("\nfunction2: 2 ^ (x * x / 0.7) - 5");
   printf("\ninterval: [1, 2]");
   printf("\nanswer: 6.223 , program: %.6lf",root(f5, f6, 6, 7, 1e-8));
   printf("\n\n----------------------test-factorial----------------------");
   printf("\n\n                      Test1");
   printf("\nfunction1: 2 ^ (x * x / 0.7) - 5");
   printf("\ninterval: [0, 2]");
   printf("\nanswer: 6.0057137885 , program: %.6lf", integral(f4, 0, 2, 1e-9));
   printf("\n\n                      Test2");
   printf("\nfunction2: x ^ (3 / 4)");
   printf("\ninterval: [0, 10]");
   printf("\nanswer: 32.1337900109, program: %.6lf", integral(f5, 0, 10, 1e-9));
   printf("\n\n                      Test3");
   printf("\nfunction1: sin(x) + 4");
   printf("\ninterval: [0, 10]");
   printf("\nanswer: 41.8390715291 , program: %.6lf", integral(f6, 0, 10, 1e-9));
   return 0;
}