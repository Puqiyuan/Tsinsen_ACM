#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n, k, i = 0, j, i_dire = 4, j_dire = 4, val, nb_cg, p, **res;
  scanf("%d", &n);

  k = (n - 1) * 2;
  val = n;
  j = n - 1;

  if (n == 1)
    {
      printf("%d\n", 1);
      exit(0);
    }

  if (n >= 2)
    {
      res = (int**)malloc(n * sizeof(int*));
      for (p = 0; p <= n - 1; p++)
	res[p] = (int*)malloc(n * sizeof(int));

      for (p = 0; p <= n - 1; p++)
	res[0][p] = (p+1);
      
      for (; k >= 1; k--)
	{
	  if (k % 2 == 0)
	    nb_cg = k / 2;
      
	  else
	    nb_cg = k / 2 + 1;

	  if ( (i_dire % 4 == 0) && (j_dire % 4 == 0) && nb_cg != 0)
	    {
	      while (nb_cg >= 1)
		{
		  i++;
		  res[i][j] = ++val;
		  nb_cg--;
		}
	      i_dire++; j_dire++;
	      
	    }

	  if ( (i_dire % 4 == 1) && (j_dire % 4 == 1) && nb_cg != 0)
	    {
	      while (nb_cg >= 1)
		{
		  j--;
		  res[i][j] = ++val;
		  nb_cg--;
		}

	      i_dire++; j_dire++;
	    }

	  if ( (i_dire % 4 == 2) && (j_dire % 4 == 2) && nb_cg != 0)
	    {
	      while (nb_cg >= 1)
		{
		  i--;
		  res[i][j] = ++val;
		  nb_cg--;
		}

	      i_dire++; j_dire++;
	    }

	  if ( (i_dire % 4 == 3) && (j_dire % 4) == 3 && nb_cg != 0)
	    {
	      while (nb_cg >= 1)
		{
		  j++;
		  res[i][j] = ++val;
		  nb_cg--;
		}

	      i_dire++; j_dire++;
	    }
	}

      for (i = 0; i <= n - 1; i++)
	{
	  for (j = 0; j <= n - 1; j++)
	    printf("%d ", res[i][j]);

	  printf("\n");
	}
    }
  
  free(res);
  return 0;
}
