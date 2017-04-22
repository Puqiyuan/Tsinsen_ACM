#include <stdio.h>
#include <stdlib.h>


int store_input(int *res)// store input data.
{
  scanf("%d %d %d %d", &res[0], &res[1], &res[2], &res[3]);

  return 0;
}


int test_sol(int *sol)// test a solution, these four values should be different.
{
  if ((sol[0] != sol[1]) && (sol[0] != sol[2]) && (sol[0] != sol[3]) &&
      (sol[1] != sol[2]) && (sol[1] != sol[3]) && (sol[2] != sol[3]))
    return 1;

  
  return 0;
}


int show(int *sol)
{
  printf("%d %d %d %d\n", sol[0], sol[1], sol[2], sol[3]);
  
  return 0;
}


int output_sol(int **big_sol)// Output solution, big_sol is a two dimensional array it contains
// four rows and eight columns, for each rows 1, 2, 3, 4 representing A, B, C, D majors. And for
// each column N it's value is 1 or 0, if it is 1 that indicate Nth classroom satisfy corresponding
// major.
{
  int i, j, k, l, sol[4], flag = 0;

  for (i = 0; i <= 7; i++)
    {
      if (big_sol[0][i] != 0)
	{
	  sol[0] = i + 1;
	  for (j = 0; j <= 7; j++)
	    {
	      if (big_sol[1][j] != 0)
		{
		  sol[1] = j + 1;
		  for (k = 0; k <= 7; k++)
		    {
		      if (big_sol[2][k] != 0)
			{
			  sol[2] = k + 1;
			  for (l = 0; l <= 7; l++)
			    {
			      if (big_sol[3][l] != 0)
				{
				  sol[3] = l + 1;

				  if (test_sol(sol))
				    {
				      flag = 1;
				      show(sol);
				    }

				}
			    }
			}
		    }
		}
	    }
	}
    }

  if (!flag)
    {
      printf("%d\n", -1);
    }
  
  return 0;
}


int put_big_sol(int *in, int **big_sol)
{
  int i, j, room[8] = {120, 40, 85, 50, 100, 140, 70, 100};

  for (i = 0; i <= 3; i++)
    {
      for (j = 0; j <= 7; j++)
	big_sol[i][j] = 0;
    }
  

  for (i = 0; i <= 7; i++)
    {
      if (in[0] <= room[i])
	big_sol[0][i] = 1;

      if (in[1] <= room[i])
	big_sol[1][i] = 1;

      if (in[2] <= room[i])
	big_sol[2][i] = 1;

      if (in[3] <= room[i])
	big_sol[3][i] = 1;
    }

  return 0;
}


int display(int **big_sol)
{
  int i, j;

  for (i = 0; i <= 3; i++)
    {
      for (j = 0; j <= 7; j++)
	printf("%d ", big_sol[i][j]);

      printf("\n");
    }

  return 0;
}


int main(int argc, char *argv[])
{
  int i, in[4];

  store_input(in);

    int **big_sol = (int**)malloc(4 * sizeof(int*));
  for (i = 0; i <= 3; i++)
    big_sol[i] = (int*)malloc(8 * sizeof(int));
  
  put_big_sol(in, big_sol);
  
  output_sol(big_sol);
  
  return 0;
}
