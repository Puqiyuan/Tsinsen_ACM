#include <stdio.h>
#include <stdlib.h>

int* convert(int* res, int a, int s)
{
  int i = 1;

  res[0] = a % s;
  a = a / s;

  while (a != 0)
    {
      res[i] = a % s;
      a = a / s;
      i++;
    }

  return res;
}

int output(int* res)
{
  int i, begain;

  for (i = 31; i >= 0; i--)
    {
      if (res[i] > 0)
	{
	  begain = i;
	  break;
	}
    }

  for (i = begain; i >= 0; i--)
    {
      if (res[i] <= 9)
	printf("%d",res[i]);
      else
	printf("%c",(char)(res[i] + 55));
    }
  printf("\n");

  return 0;
}

int main(int argc, char *argv[])
{
  int n, i, s;
  int* res = (int*)malloc(32 * sizeof(int));

  for (i = 0; i <= 31; i++)
    res[i] = 0;

  scanf("%d%d",&n,&s);
  res = convert(res, n, s);
  output(res);
  
  return 0;
}

