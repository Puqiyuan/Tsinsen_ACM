#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned int* my_pow(int base, int power, unsigned int* res)
{
  int i = 1;
  *res = 1;
  while (i != power + 1)
    {
      *res *= 16;
      i++;
      
    }
  *res *= base;

  return res;  
}

int computing(char* s)
{
  unsigned int* res;
  res = (unsigned int*)malloc(sizeof(unsigned int));
  int i, length = strlen(s), power = strlen(s) - 1;
  unsigned int sum = 0;

  for (i = 0; i <= length - 1; i++)
    {
      if (s[i] >= 48 && s[i] <= 57) 
	{
	  res = my_pow((int)(s[i] - 48), power, res);
	  sum += *res;
	  power--;
	}
      else
	{
	  res = my_pow((int)(s[i] - 55), power, res);
	  sum += *res;
	  power--;
	}
    }

  printf("%u\n",sum);
  
  return 0;
}

int main(int argc, char *argv[])
{
  char s[8];
  scanf("%s",s);
  computing(s);
  
  return 0;
}

