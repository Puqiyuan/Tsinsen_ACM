#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{ 
  char *s = (char*)malloc(100 * sizeof(char));
  int i, j, k, len, L, flag = 1, diff, max_diff = 0;

  scanf("%s", s);
  len = strlen(s);

  for (i = 0; i <= len - 1; i++)
    {
      for (j = i + 1; j <= len - 1; j += 2)
	{
	  flag = 1;
	  if ( (j - i +1 ) % 2 == 0 )
	    {
	      L = (j - i + 1) / 2;
	      for (k = 0; k <= L - 1; k++)
		{
		  if ( s[i + k] != s[i + L +k])
		    {
		      flag = 0;
		      break;
		    }
		}

	      if (flag)
		diff = j - i + 1;

	      if (diff > max_diff)
		max_diff = diff;
	    }
	}
    }
  printf("%d\n", max_diff);
  free(s);
  
  return 0;
}
