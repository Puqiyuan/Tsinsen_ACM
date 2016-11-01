#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char A[26], input[100];
  int count[26], i, len, j, k = 97;

  for (i = 0; i <= 25; i++)
    {
      A[i] = (char)(k);
      k++;
      count[i] = 0;
    }

  scanf("%s", input);

  len = strlen(input);
  
  for (i = 0; i < len; i++)
    {
      for (j = 0; j <= 25; j++)
	{
	  if (input[i] == A[j])
	    {
	      count[j]++;
	      break;
	    }
	}
    }

  for (i = 0; i <= 25; i++)
    {
      if (count[i] != 0)
	{
	  printf("%c %d\n", i + 97, count[i]);
	}
    }
  
  return 0;
}

