#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int add(int *res, int *ini1, int *ini2, int max_len)
// Add two integer, they store in int array.
{
  int i, tmp, jw = 0;

  for (i = max_len - 1; i >= 0; i--)
    {
      tmp = ini1[i] + ini2[i];// Add the two number digits.
      res[i] = (jw + tmp) % 10;// The result digit should be modulus of sum of carry and two number
      //digits.
      jw = (tmp + jw) / 10;
    }

  return 0;
}


int show_add(int *res, int len)// Show the computing result of addition.
{
  int i;

  if (res[0] != 0)// If no carry in the highest position, we don't need output this digit.
    printf("%d", res[0]);
  
  for (i = 1; i <= len - 1; i++)
    printf("%d", res[i]);
    
  printf ("\n");

  return 0;
}


int store(char *in)// Store input as char string.
{
  scanf("%s", in);

  return 0;
}


int ctoi(char *in, int len, int max_len, int *ini)
{
  int i, k = max_len - 1;

  for (i = len - 1; i >= 0; i--)
    {
      ini[k] = (int)(in[i] - 48);
      k--;
    }

  return 0;
}


int t_ctoi(int *ini, int max_len)
{
  int i;

  for (i = 0; i <= max_len - 1; i++)
    printf("%d", ini[i]);

  printf("\n");
  return 0;
}


int main(int argc, char *argv[])
{
  char in1[100], in2[100];

  store(in1);
  store(in2);

  int len1 = strlen(in1);
  int len2 = strlen(in2);
  
  int max_len;

  if (len1 > len2)
    max_len = len1 + 1;
  else
    max_len = len2 + 1;

  int *res = (int*)malloc(max_len * sizeof(int));
  int *ini1 = (int*)malloc(max_len * sizeof(int));
  int *ini2 = (int*)malloc(max_len * sizeof(int));

  ctoi(in1, len1, max_len, ini1);
  
  ctoi(in2, len2, max_len, ini2);

  add(res, ini1, ini2, max_len);

  show_add(res, max_len);
  
  return 0;
}
