#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n, i, target;

  scanf("%d", &n);
  int* in = (int*)malloc(n * sizeof(int));
  for (i = 0; i <= n - 1; i++)
    scanf("%d", &in[i]);

  scanf("%d", &target);
  for (i = 0; i <= n - 1; i++)
    {
      if (in[i] == target)
	{
	  printf("%d\n",i + 1);
	  break;
	}
    }
  if (i == n)
    printf("%d\n", -1);
  return 0;
}
