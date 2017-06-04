#include <stdio.h>
#include <stdlib.h>


int sub(int *in, int *last)
{
  int i;

  for (i = 0; i <= (*last) - 1; i++)
    in[i] = in[i + 1] - in[i];

  *last -= 1;
  return 1;
}


int show(int *in, int *last)
{
  int i = 0;

  for (i = 0; i <= *last; i++)
    printf("%d ", in[i]);

  printf("\n");

  return 1;
}


int main(int argc, char *argv[])
{
  int n, s = 0, i;
  int *last = (int*)malloc(sizeof(int));
  scanf("%d", &n);
  
  int *in = (int*)malloc(n * sizeof(int));

  for (i = 0; i <= n - 1; i++)
    scanf("%d", &in[i]);

  *last = n - 1;

  while (*last >= 0)
    {
      s += in[(*last)];
      sub(in, last);
    }

  printf("%d\n", s);
  
  return 0;
}
