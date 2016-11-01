#include <stdio.h>
#include <stdlib.h>

int* convert(int* res, int a)
{
  int i = 1;
  
  res[0] = a % 16;
  a = a / 16;
  
  while (a != 0)
    {
      res[i] = a % 16;
      a = a / 16;
      i++;
    }

  return res;  
}

int output(int* res)
{
  int i, begain;
  
  for (i = 7; i >= 0; i--)
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
  int n, i;
  int* res = (int*)malloc(8 * sizeof(int));

  for (i = 0; i <= 7; i++)
    res[i] = 0;

  scanf("%d",&n);
  res = convert(res, n);
  output(res);
  
  return 0;
}
