#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int i, j;
  int* a = malloc(4 * sizeof(int));

  for (i = 1; i <= 9; i++)
    {
      a[0] = a[3] = i;
      for (j = 0; j <= 9; j++)
        {
          a[1] = a[2] = j;
	  printf("%d%d%d%d\n",a[0],a[1],a[2],a[3]);
        }
    }

  return 0;
}
