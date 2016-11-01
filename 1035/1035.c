#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n, j, elem, sum;
  scanf("%d", &n);
  while (n != 0)
    {
      if (n == 1)
	printf("%d\n", 0);
      
      else
	{
	  sum = 0;

	  for (elem = 2; elem <= n; elem++)
	    {
	      for (j = 2; j <= sqrt(elem); j++)
		{
		  if (elem % j == 0)
		    break;
		}

	      if (j == (int)sqrt(elem) + 1)
		sum += elem;
	    }
	  printf("%d\n", sum);
 
	}
      scanf("%d", &n);
    }

  return 0;
}

