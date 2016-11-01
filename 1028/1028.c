#include <stdio.h>

int gcd(int x, int y)
{
  int i, res;
  
  for (i = y; i >= 1; i--)
    {
      if (x % i == 0 && y % i == 0)
	{
	  res = i;
	  break;
	}
    }

  return res;
}
int main(int argc, char *argv[])
{
  int x, y, z;
  scanf("%d %d %d", &x, &y, &z);

  switch(z)
    {
    case 1:
      printf("%d\n", x + y);
      break;
      
    case 2:
      printf("%d\n", x - y);
      break;
      
    case 3:
      printf("%d\n", x * y);
      break;
      
    case 4:
      printf("%d\n", x / y);
      break;
      
    case 5:
      printf("%d\n", x % y);
      break;
      
    case 6:
      if (x > y)
	printf("%d\n", gcd(x, y));
      else
	printf("%d\n", gcd(y, x));
      break;
      
    case 7:
      if (x > y)
	printf("%d\n", x * y / gcd(x, y));
      else
	printf("%d\n", x * y / gcd(y, x));
    }
  
  return 0;
}
