#include <stdio.h>
#include <stdlib.h>

int merge(int* A, int p, int q, int r)
//其中p，q，r均为一般意义上的数数。
{
  int n1 = q - p + 1, n2 = r - q, i, j, k;
  int* L = (int*)malloc((n1 + 1) * sizeof(int));
  int* R = (int*)malloc((n2 + 1) * sizeof(int));

  for (i = 0; i <= n1 - 1; i++)
    L[i] = A[p + i - 1];

  for (j = 0; j <= n2 - 1; j++)
    R[j] = A[q + j];
  L[n1] = 2147483647;
  R[n2] = 2147483647;
  
  i = j = 0;
  for (k = p - 1; k <= r - 1; k++)
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
  int n, i;
  scanf("%d", &n);
  int* A = (int*)malloc(n * sizeof(int));

  for (i = 0; i <= n - 1; i++)
    scanf("%d",&A[i]);
  merge_sort(A, 1, n);

  for (i = 0; i <= n - 1;i++)
    printf("%d ",A[i]);
  printf("\n");
  return 0;
}
