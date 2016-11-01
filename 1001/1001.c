#include <stdio.h>
#include <stdlib.h>

int* convert( int* A, int s )
{
  int i = 0;
  while (i <= 5 && s != 0)
    {
      A[i] = s % 2;
      s = s / 2;
      i++;
    }
  return A;
}

int main(int argc, char *argv[])
{
  int* A = (int*)malloc(6 * sizeof(int));
  int i, j ,k;

  for ( i = 0; i <= 63; i++ )
    {
      for ( k = 0; k <= 5; k++)
	A[k] = 0;
      convert( A, i );
      for ( j = 5; j >= 0; j-- )
	printf("%d",A[j]);
      printf("\n");
    }
  return 0;
}
