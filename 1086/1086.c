#include <stdio.h>
#include <stdlib.h>


int counting_sort(int *A, int *B, int k, int len)//The main function that implement
//counting sort. B array is the sorted elements lie on. A array is waiting for sorting.
//k is the largest value in A array, and len is the length of array A.
{
  int i, j;
  int *C = (int*)malloc((k + 1) * sizeof(int));//C is a auxiliary array for describing
  //that for each element in array A how many elements smaller than it.

  for (i = 0; i <= k; i++)
    C[i] = 0;

  for (j = 0; j <= len - 1; j++)
    C[A[j]] = C[A[j]] + 1;//every time when we increment one if there is a element in array A
  //correspond index of C array. Until now, for value of C array, is representing that how many
  //elements in A array that equal to index of this value.

  for (i = 1; i <= k; i++)
    C[i] = C[i] + C[i - 1];//Because of the index of C is increasing, obviously. So until now,
  //the value of C array representing how many elements in A array that smaller than index of
  //this value.

  for (j = len - 1; j >= 0; j--)//Now we should to decide which position is belong to value in
    //A array. And put the element to B array.
    {
      B[C[A[j]] - 1] = A[j];
      C[A[j]] = C[A[j]] - 1;//if there are same element in array A, we should put the latter on the
      //left
    }

  return 1;
}


int store(int *in, int n)
{
  int i;

  for (i = 0; i <= n - 1; i++)
    scanf("%d", &in[i]);

  return 1;
}


int display(int *in, int n)
{
  int i = 0;

  for (i = 0; i <= n - 1; i++)
    printf("%d ", in[i]);

  printf("\n");

  return 1;
}


int position(int *in, int n, int x)
{
  int i = 0;

  for (i = 0; i <=  n - 1; i++)
    {
      if (x < in[i])
	return i;
    }

  return i;
}


int add(int *in, int *n)
{
  int new = in[0] + in[1];

  int pos = position(in, *n, new);

  int i;

  for (i = (*n) - 1; i >= pos; i--)
    in[i + 1] = in[i];

  in[pos] = new;

  *n += 1;

  return 1;
}


int delete_two(int *in, int *n)
{
  int i = 0;

  for (i = 0; i <= (*n) - 1; i++)
    in[i] = in[i + 2];

  *n -= 2;

  return 1;
}


int main(int argc, char *argv[])
{
  int *n = (int*)malloc(sizeof(int));
  int sum = 0, tmp;

  scanf("%d", n);

  int *in = (int*)malloc((*n + 1) * sizeof(int));
  int *B = (int*)malloc((*n + 1) * sizeof(int));

  store(in, *n);

  counting_sort(in, B, 1001, *n);

  while (*n >= 1)
    {
      tmp = B[0] + B[1];
      
      sum += B[0] + B[1];
      
      add(B, n);

      delete_two(B, n);
    }

  printf("%d\n", sum - tmp);
  
  return 0;
}
 
 
