#include <stdio.h>
#include <stdlib.h>

int test(int* a, int n, int length)
{
  int sum = 0, flag = 0, i;
  for (i = 0; i <= length - 1;i++)
    sum += a[i];
  if (sum == n)
    flag = 1;
  return flag;
}

int main(int argc, char *argv[])
{
  int i, j, k, n;
  int* a = malloc(5 * sizeof(int));
  int* b = malloc(6 * sizeof(int));

  scanf("%d",&n);
  for (k = 1; k <= 9; k++)
    {
      a[0] = a[4] = k;
      for (i = 0; i <= 9; i++)
	{
	  a[1] = a[3] = i;
	  for (j = 0; j <= 9; j++)
	    {
	      a[2] = j;
	      if (test(a, n, 5))
		printf("%d%d%d%d%d\n",a[0],a[1],a[2],a[3],a[4]);
	    }
	}
    }

  for (i = 1; i <= 9; i++)
    {
      b[0] = b[5] = i;
      for (j = 0; j <= 9; j++)
	{
	  b[1] = b[4] = j;
	  for (k = 0; k <= 9; k++)
	    {
	      b[2] = b[3] = k;
	      if (test(b, n, 6))
		printf("%d%d%d%d%d%d\n",b[0],b[1],b[2],b[3],b[4],b[5]);
	    }
	}
    }
  return 0;
}
