#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int partition(char **A, int p, int r);
int quick_sort(char **A, int p, int r);

char *store(char *res)// store the input string to res
{
  scanf("%s", res);

  return res;
}


int show(char *res)//test for store function
{
  int len = strlen(res), i;

  for (i = 0; i <= len - 1; i++)
    printf("%c", res[i]);

  printf("\n");

  return 0;
}


char *sub_str(char *sub, int start, int sub_len, char *par)//store one sub string to sub
{
  int i, j = 0;
  
  for (i = start; i <= start + sub_len - 1 && j <= sub_len - 1; i++)
    {
      sub[j] = par[i];
      j++;
    }

  return sub;
}


int show_sub(char *sub)//test for sub_str function
{
  puts(sub);

  return 0;
}


char **store_sub(char **res, int sub_len, char *sub, int r)//store all sub strings of res string
{
  int i;

  for (i = 0; i <= sub_len - 1; i++)
    res[r][i] = sub[i];

  return res;
}


int show_subs(char **subs, int r)// test for store_sub function
{
  int i;
  for (i = 0; i <= r - 1; i++)
    printf("%s ", subs[i]);

  printf("\n");
  return 0;
}


int quick_sort(char **A, int p, int r)// sort all sub string by dictionary order
{
  int q;
  
  if (p < r)
    {
      q = partition(A, p, r);
      quick_sort(A, p, q - 1);
      quick_sort(A, q + 1, r);
    }

  return 0;
}


int partition(char **A, int p, int r)// part of quick sort
{
  char *x = A[r];
  int i = p - 1, j;
  char *tmp1, *tmp2;

  for (j = p; j <= r - 1; j++)
    {
      if (strcmp(A[j], x) < 0)
	{
	  i++;
	  tmp1 = A[i];
	  A[i] = A[j];
	  A[j] = tmp1;
	}
    }

  tmp2 = A[i + 1];
  A[i + 1] = A[r];
  A[r] = tmp2;

  return i + 1;
}


int main(int argc, char *argv[])
{
  int i, len, sub_len;
  char *res = (char*)malloc(1001 * sizeof(char));// res for storing input string
  
  store(res);

  scanf("%d", &sub_len);//input the length of sub string

  len = strlen(res);

  char **subs = (char**)malloc((len - sub_len + 1) * sizeof(char*));// subs for store
  //all sub strings
  
  for (i = 0; i <= len - sub_len; i++)
    subs[i] = (char*)malloc(sub_len * sizeof(char));

  for (i = 0; i <= len - sub_len; i++)
    {
      char *sub = (char*)malloc(sub_len * sizeof(char));

      sub_str(sub, i, sub_len, res);

      store_sub(subs, sub_len, sub, i);
      
    }

  quick_sort(subs, 0, len - sub_len);
  
  show_subs(subs, len - sub_len + 1);
  
  
  return 0;
}
