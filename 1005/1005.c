#include <stdio.h>

int test(int a)
{
  int i, j, k;
  i = a / 100;
  j = (a - i * 100) / 10;
  k = a - i * 100 - j * 10;
  if (a == i * i * i + j * j * j + k * k * k)
    printf ("%d\n",a);
  return 0;
}

int main(int argc, char *argv[])
{
  int a;
  for (a = 100; a < 1000; ++a)
    {
      test(a);
    }
  return 0;
}
