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

int bin_search(int* A, int a, int low, int hig, int mid)
{
  int flag;
  
  if (A[mid] != a && low <= hig)
    {
      if (A[mid] < a)
        {
          low = mid + 1;
          mid = (hig + low) / 2;
          flag = bin_search(A, a, low, hig, mid);
        }
      else
        {
          hig = mid - 1;
          mid = (low + hig) / 2;
          flag = bin_search(A, a, low, hig, mid);
        }
    }
  else if (low > hig)
    {
      flag = -1;
    }
  else
    flag = mid;

  return flag;
}

int* intersection(int* A1, int* A2, int n, int m, int* res)
{
  int i, k = 1, mid;
  mid = (0 + m) / 2;

  for (i = 0; i <= n - 1; i++)
    {
      if (bin_search(A2, A1[i], 0, m, mid) != -1)
	{
	  res[k] = A1[i];
	  k++;
	}
    }
  res[0] = k;
  
  return res;
}

int main(int argc, char *argv[])
{
  int n, m, i, out, min, j;
  int* res;
  
  scanf("%d", &n);
  int* A1 = (int*)malloc(n * sizeof(int));
  for (i = 0; i <= n - 1; i++)
    scanf("%d",&A1[i]);

  scanf("%d", &m);
  int* A2 = (int*)malloc(m * sizeof(int));
  for (i = 0; i <= m - 1; i++)
    scanf("%d",&A2[i]);

  int* A = (int*)malloc((n + m) * sizeof(int));
  for (i = 0; i <= n - 1; i++)
    A[i] = A1[i];
  for (i = n, j = 0; i <= n + m - 1; i++, j++)
    A[i] = A2[j];
  
  merge_sort(A1, 1, n);
  merge_sort(A2, 1, m);
  merge_sort(A, 1, (n + m));
  
  min = n;
  if (n > m)
    min = m;
  res = (int*)malloc((min+1) * sizeof(int));

  intersection(A1, A2, n, m, res);
  
  for (out = 1; out <= res[0] - 1; out++)
    printf("%d ", res[out]);
  printf("\n");

  for (out = 0; out <= n + m - 3; out++)
    {
      if (A[out] != A[out+1])
	printf("%d ", A[out]);
    }
  if (A[n + m - 2] == A[n + m - 1] )
    printf("%d",A[n + m - 2]);
  else
    {
      printf("%d %d",A[n + m - 2], A[n + m - 1]);
    }
  printf("\n");

  for (out = 0; out <= n - 1; out++)
    {
      j = 1;
      while (j <= res[0])
	{
	  if (A1[out] == res[j])
	    break;
	  else
	    j++;
	}
      if (j == res[0] + 1)
	printf("%d ",A1[out]);
    }

  printf("\n");
  
  return 0;
}
