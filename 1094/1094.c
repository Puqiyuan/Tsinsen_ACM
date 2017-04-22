#include <stdio.h>
#include <stdlib.h>

int count = 1;

int *computing(double *xk, double a, double b, double c, double d)
{
  double fxk = a * (*xk) * (*xk) * (*xk) + b * (*xk) * (*xk) + c * (*xk) + d;

  double dfxk = 3 * a * (*xk) * (*xk) + 2 * b * (*xk) + c;

  *xk = *xk - fxk / dfxk;

  return 0;
}


int test(double *xk, double a, double b, double c, double d)
{
  double err = a * (*xk) * (*xk) * (*xk) + b * (*xk) * (*xk) + c * (*xk) + d;

  if (err < 0)
    err = 0 - err;

  if (err <= 0.0000001)
    return 1;
    
  return 0;
}


int main(int argc, char *argv[])
{
  double a, b, c, d;
  double *x = (double*)malloc(sizeof(double));
  
  scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
  scanf("%lf", x);

  while (!test(x, a, b, c, d))
    {
      computing(x, a, b, c, d);
      count++;
    }

  printf("%.3lf %d\n", *x, count);
  
  return 0;
}

