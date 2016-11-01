#include <stdio.h>

int find_solutions(int h)
{
  if (h < 1)
    return 0;

  if (h == 1)
    return 1;

  if (h == 2)
    return 2;

  if (h == 3)
    return 4;

  return find_solutions(h - 1) + find_solutions(h - 2) + find_solutions(h - 3);
}

int main(int argc, char *argv[])
{
  int h;
  scanf("%d", &h);
  if (h >= 4 && h <= 20)
    printf("%d\n", find_solutions(h));
  else
    printf("0\n");
  
  return 0;
}

