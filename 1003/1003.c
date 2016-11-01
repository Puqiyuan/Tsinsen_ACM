#include <stdio.h>
#include <stdlib.h>

char** put(char** a)
{
  int i, j, k;
  
  for (i = 0; i <= 17; i++)
    a[0][i] = (char)(65 + i);
  for (i = 1; i <= 24; i++)
    a[i][0] = (char)(65 + i);

  for (i = 0; i <= 17; i++)
    {
      j = i + 1; k = 1;
      while (j <= 17 && k <= 24)
	{
	  a[k][j] = a[0][i];
	  j++;k++;
	}
    }

  for (i = 1; i <= 24; i++)
    {
      j = i + 1; k = 1;
      while (j <= 24 && k <= 17)
	{
	  a[j][k] = a[i][0];
	  j++;k++;
	}
    }
  return a;
}

int main(int argc, char *argv[])
{
  char** a = (char**)malloc(25 * sizeof(char*));
  int i, j;
  
  for (i = 0;i <= 25; i++)
    {
      a[i] = (char*)malloc(18 * sizeof(char));
    }
  put(a);
  for (i = 0; i <= 24; i++)
    {
      for (j = 0; j <= 17; j++)
	{
	  printf("%c",a[i][j]);
	}
      printf("\n");
    }
  return 0;
}
