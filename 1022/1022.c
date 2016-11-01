#include <stdio.h>
int main(int argc, char *argv[])
{
  int n, h, m, s;
  scanf("%d", &n);
  h = n / 3600;
  m = (n - h * 3600) / 60;
  s = n - 3600 * h - m * 60;
  printf("%d:%d:%d\n",h, m, s);
  
  return 0;
}
