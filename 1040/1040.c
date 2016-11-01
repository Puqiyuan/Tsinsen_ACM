#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
  int i, j, c_p, stop, count = 0, n, amount = 2;
  scanf("%d", &n);

  i = j = 0;
  stop = (int)( (sqrt(8 * n + 1) - 1) / 2) + 1;

  while (amount <= stop && count != n - 1)
    {
      c_p = 1;

      if (amount % 2 == 0)
	{
	  i = 0; j++;
	  count++;
	  while (c_p <= amount - 1 && count != n - 1)
	    {
	      i++; j--;
	      count++;
	      c_p++;
	    }
	  amount++;
	}

      else
	{
	  i++; j = 0;
	  count++;
	  while (c_p <= amount - 1 && count != n - 1)
	    {
	      i--; j++;
	      count++;
	      c_p++;
	    }
	  amount++;
	}
    }

  printf("%d/%d\n",i + 1, j + 1);
  
  return 0;
}
