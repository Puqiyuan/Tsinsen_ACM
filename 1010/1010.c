#include <stdio.h>

int* convert(int* result, int n)
{
  int s;
  
  result[0] = n % 16;
  s = n / 16;
  result[1] = s % 16;

  return result;
}

int main(int argc, char *argv[])
{
  int n;
  int result[2];
  
  scanf("%d",&n);
  convert(result, n);
  if (result[1] >= 10)
    printf("%c",(char)(result[1] + 55));
  else
    printf("%d",result[1]);
  if (result[0] >= 10)
    printf("%c\n",(char)result[0] + 55);
  else
    printf("%d\n",result[0]);
  return 0;
}
