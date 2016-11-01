#include <stdio.h>
int main(int argc, char *argv[])
{
  int i, j, m, n;

  for (i = 65; i <= 68; i++)
    {
      for (j = 65; j <= 68; j++)
	{
	  for (m = 65; m <= 68; m++)
	    {
	      for (n = 65; n <= 68; n++)
		{
		  printf("%c%c%c%c\n",i, j, m, n);
		}
	    }
	}
    }
  return 0;
}

