#include <stdio.h>
#include <stdlib.h>

int max(int* a, int length)
{
  int max = a[0], i, pos = 0;
  for (i = 0; i <= length - 1; i++)
    {
      if (max < a[i])
	{
	  max = a[i];
	  pos = i;
	}
    }

  max = -1001;
  for (i = 0; i <= length - 1; i++)
    {
      if (max < a[i] && i != pos)
	max = a[i];
    }
  
  return max;
}

int min(int* a, int length)
{
  int min = a[0], i, pos = 0;
  for (i = 0; i <= length - 1; i++)
    {
      if (min > a[i])
	{
	  min = a[i];
	  pos = i;
	}
    }

  min = 1001;
  for (i = 0; i <= length - 1; i++)
    {
      if (min > a[i] && i != pos)
	min = a[i];
    }

  return min;
  
}

int sum(int* a, int length)
{
  int sum = 0, i;
  for (i = 0; i <= length - 1; i++)
    {
      sum += a[i] * a[i];
    }
  
  return sum;
}

int main(int argc, char *argv[])
{
  int length, i, maxv, minv, sumv;
  int* a;
  
  scanf("%d",&length);
  a = (int*)malloc(length * sizeof(int));
  for (i = 0; i <= length - 1; i++)
    scanf("%d",&a[i]);
  
  maxv = max(a, length);
  minv = min(a, length);
  sumv = sum(a, length);
  
  printf("%d\n",maxv);
  printf("%d\n",minv);
  printf("%d\n",sumv);
  
  return 0;
}
