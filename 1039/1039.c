#include <stdio.h>
#include <stdlib.h>

int merge(int* A, int p, int q, int r)
{
  int n1 = q - p + 1, n2 = r - q, i, j, k;
  int* L = (int*)malloc(n1 * sizeof(int));
  int* R = (int*)malloc(n2 * sizeof(int));

  for (i = 0; i <= n1 - 1; i++)
    L[i] = A[p + i - 1];

  for (j = 0; j <= n2 - 1; j++)
    R[j] = A[q + j];
  
  i = j = 0;
  for (k = p - 1; k <= r - 1; k++)
    {
      if (i <= n1 -1 && j <= n2 - 1)
        {
          if (L[i] <= R[j])
            {
              A[k] = L[i];
              i++;
            }
          else
            {
              A[k] = R[j];
              j++;
            }
        }
      else
        {
          if (i > n1 - 1 && j <= n2 - 1)
            {
              A[k] = R[j];
              j++;
            }
          else if (j > n2 - 1 && i <= n1 - 1)
            {
              A[k] = L[i];
              i++;
            }
        }
    }

  return 0;
}

int merge_sort(int* A, int p, int r)
{
  int q;
  
  if (p < r)
    {
      q = (p + r) / 2;
      merge_sort(A, p, q);
      merge_sort(A, q + 1, r);
      merge(A, p, q, r);
    }

  return 0;
}


int main(int argc, char *argv[])
{
  int N, i, flag = 1;
  scanf("%d", &N);
  
  int *in = (int*)malloc(N * sizeof(int));
  int *check = (int*)malloc((N - 1) * sizeof(int));

  for (i = 0; i <= N - 1; i++)
    scanf("%d", &in[i]);

  for (i = 0; i <= N - 2; i++)
    check[i] = abs(in[i] - in[i + 1]);

  merge_sort(check, 1, N - 1);
  
  for (i = 0; i <= N - 2; i++)
    {
      if ( i + 1 != check[i])
	{
	  flag = 0;
	  break;
	}
    }

  if (flag)
    printf("I'm happy!!\n");
  else
    printf("I'm unhappy!!\n");
  
  free(check);
  free(in);
  return 0;
}
