#include <stdio.h>
#include <stdlib.h>

char** put(char** a, int n, int m)
{
  int i, j, k;
  
  for (i = 0; i <= m - 1; i++)
    a[0][i] = (char)(65 + i);
  for (i = 1; i <= n - 1; i++)
    a[i][0] = (char)(65 + i);

  for (i = 0; i <= m - 1; i++)
    {
      j = i + 1; k = 1;
      while (j <= m - 1 && k <= n - 1)
	{
	  a[k][j] = a[0][i];
	  j++;k++;
	}
    }

  for (i = 1; i <= n - 1; i++)
    {
      j = i + 1; k = 1;
      while (j <= n - 1 && k <= m - 1)
	{
	  a[j][k] = a[i][0];
	  j++;k++;
	}
    }
  return a;
}

int main(int argc, char *argv[])
{
  int i, j, n, m;
  scanf("%d %d",&n,&m);
  char** a = (char**)malloc(n * sizeof(char*));
  
  for (i = 0;i <= n; i++)
    {
      a[i] = (char*)malloc(m * sizeof(char));
    }
  put(a, n, m);
  for (i = 0; i <= n-1; i++)
    {
      for (j = 0; j <= m-1; j++)
	{
	  printf("%c",a[i][j]);
	}
      printf("\n");
    }
  return 0;
}
