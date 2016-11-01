#include <stdlib.h>
#include <stdio.h>

int show(int **res, int N, int flag);

int copy(int **res, int **b, int N)
{
  int i, j;

  for (i = 0; i <= N - 1; i++)
    {
      for (j = 0; j <= N - 1; j++)
	b[i][j] = res[i][j];
    }
  

  return 0;
}

int** multi(int **a, int **res, int **b, int N, int M)
{
  int i, j = 0, k = 0;

  while (M >= 2)
    {
      for (i = 0; i <= N - 1; i++)
	{
	  for (j = 0; j <= N - 1; j++)
	    {
	      res[i][j] = 0;
	      for (k = 0; k <= N - 1; k++)
		res[i][j] += a[i][k] * b[k][j];
	    }
	}

      copy(res, b, N);
      M--;
    }

  return res;
}

int show(int **res,int N, int flag)
{
  int i, j;

  if (flag)
    {
      for (i = 0; i <= N - 1; i++)
	{
	  for (j = 0; j <= N - 1; j++)
	    printf("%d ", res[i][j]);
	  printf("\n");
	}
    }
  else
    {
      for (i = 0; i <= N - 1; i++)
	{
	  for (j = 0; j <= N - 1; j++)
	    {
	      if (i == j)
		printf("1 ");
	      else
		printf("0 ");
	    }
	  printf("\n");
	}
    }

  return 0;
}

int main(int argc, char *argv[])
{
  int N, M, i, j;
  scanf("%d %d", &N, &M);

  int **a = (int**)malloc(N * sizeof(int*));
  for (i = 0; i <= N - 1; i++)
    a[i] = (int*)malloc(N * sizeof(int));

  int **res = (int**)malloc(N * sizeof(int*));
  for (i = 0; i <= N - 1; i++)
    res[i] = (int*)malloc(N * sizeof(int));

  int **b = (int**)malloc(N * sizeof(int*));
  for (i = 0; i <= N - 1; i++)
    b[i] = (int*)malloc(N * sizeof(int));

  for (i = 0; i <= N - 1; i++)
    {
      for (j = 0; j <= N - 1; j++)
	scanf("%d", &a[i][j]);
    }
  
  copy(a, b, N);
  if (M != 0)
    {
      res = multi(a, res, b, N, M);
      show(res, N, 1);
    }
  else
    show(res, N, 0);

  free(a);
  free(res);
  return 0;
}
