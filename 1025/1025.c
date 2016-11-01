#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
  char A[10], B[10];
  int i, len, flag1 = 1, flag2 = 1;
  scanf("%s", A);
  scanf("%s", B);
  if (strlen(A) == strlen(B))
    {
      len = strlen(A);
      for (i = 0; i < len; i++)
	{
	  if (A[i] != B[i])
	    flag1 = 0;
	  if (toupper(A[i]) != toupper(B[i]))
	    flag2 = 0;
	}
      if (flag1)
	{
	  printf("%d\n", 2);
	  exit(0);
	}
      else if (flag2)
	{
	  printf("%d\n", 3);
	  exit(0);
	}
      else
	printf("%d\n", 4);
      
      
    }
  else
    printf("%d\n",1);
  
  return 0;
}
