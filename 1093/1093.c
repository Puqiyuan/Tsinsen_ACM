#include <stdio.h>


int judge(int year)
{
  if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    return 1;

  return 0;
}


int main(int argc, char *argv[])
{
  int year;

  scanf("%d", &year);

  if (judge(year))
    printf("yes\n");

  else
    printf("no\n");
  
  return 0;
}

