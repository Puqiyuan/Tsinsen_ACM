#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char *s1[16] = {"0000","0001","0010","0011","0100","0101","0110","0111",
		 "1000","1001","1010","1011","1100","1101","1110","1111"};
  register int i, beg, j, k;
  int n;
  char input[100100], htb[400102];
  int resu[133434], len;
  scanf("%d",&n);
  
  while (n--)
    {
      scanf("%s",input);

      len = strlen(input);
      if (len % 3 == 0)
	beg = 0;
      else if (len % 3 == 1)
	{
	  beg = 2; htb[0] = htb[1] = '0';
	}
      else
	{
	  beg = 1; htb[0] = '0';
	}

      if (len * 4 % 3 == 0)
        k = len * 4;
      else if ((len * 4 + 1) % 3 == 0)
        k = len * 4 + 1;
      else
        k = len * 4 + 2;

      for (i = 0; i <= len - 1; i++)
	{
	  if (input[i] <= 57)
	    {
	      htb[beg] = s1[(int)(input[i] - 48)][0];
	      htb[beg + 1] = s1[(int)(input[i] - 48)][1];
	      htb[beg + 2] = s1[(int)(input[i] - 48)][2];
	      htb[beg + 3] = s1[(int)(input[i] - 48)][3];
	      beg += 4;
	    }
	  else
	    {
	      htb[beg] = s1[(int)(input[i] - 55)][0];
	      htb[beg + 1] = s1[(int)(input[i] - 55)][1];
	      htb[beg + 2] = s1[(int)(input[i] - 55)][2];
	      htb[beg + 3] = s1[(int)(input[i] - 55)][3];
	      beg += 4;
	    }
	}
      
      resu[0] = (int)(htb[0] - 48) * 4 + (int)(htb[1] - 48) * 2 + (int)(htb[2] - 48);
      for (j = 1; j <= k / 3 - 1; j++)
	{
	  resu[j] = (int)(htb[j * 3] - 48) * 4 + (int)(htb[j * 3 + 1] - 48) * 2 +
	    (int)(htb[j * 3 + 2] - 48);
	}

      if (resu[0] != 0)
	printf("%d",resu[0]);

      for (j = 1; j <= k / 3 - 1; j++)
	printf("%d",resu[j]);
      printf("\n");
    }
  
  return 0;
}

 
