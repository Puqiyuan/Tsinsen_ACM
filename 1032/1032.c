#include <stdio.h>

int main(int argc, char *argv[])
{
  int i, p, n;

  scanf("%d", &n);

  for (i = 0; i <= n - 1; i++)
    {
      p = i + 65;
      while (p != 64)
	{
	  printf("%c", p);
	  p--;
	}

      p += 2;

      while ( p != i + 66)
	{
	  printf("%c", p);
	  p++;
	}

      printf("\n");
      
    }
  
  return 0;
}
