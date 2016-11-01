#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
  int a, b, i, len, j, count = 0, flag = 1;
  scanf("%d %d", &a, &b);
  int *ran, *res;

  len = b - a + 1;
  ran = (int*)malloc(len * sizeof(int));
  res = (int*)malloc(len * sizeof(int));
  ran[0] = a;
  ran[len - 1] = b;
  for (i = 1; i <= len - 2; i++)
    ran[i] = ++a;

  for (i = 0; i <= len - 1; i++)
    {
      for (j = 2; j <= sqrt(ran[i]); j++)
	{
	  if (ran[i] % j == 0)
	    break;
	}

      if (j == (int)sqrt(ran[i]) + 1)
	{
	  res[count] = ran[i];
	  count++;
	}
    }

  for (i = 0; i < count - 1; i++)
    {
      if (res[i] - res[i+1] == -2)
	{
	  printf("%d %d\n", res[i], res[i+1]);
	  flag = 0;
	}
    }
  if ( flag )
    printf("-1\n");
  
  free(ran);
  free(res);
  return 0;
}

