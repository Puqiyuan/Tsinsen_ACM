#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int test_less(char* write, char* sample)
{
  int i, j, len, flag = 0, k;
  len = strlen(sample);

  for (k = 0; k <= len - 1; k++)
    {
      i = j = 0;
      
      while (i <= len - 1 && j <= len - 2)
	{
	  if (i == k)
	    i++;

	  if (sample[i] != write[j])
	    break;

	  i++; j++;
	  
	  if (j == len - 1)
	    flag = 1;
	}
    }
  
  return flag;
}

int test_more(char* write, char* sample)
{
  int i, j, len, flag = 0, k;
  len = strlen(write);

  for (k = 0; k <= len - 1; k++)
    {
      i = j = 0;

      while (i <= len - 1 && j <= len - 2)
	{
	  if (i == k)
	    i++;

	  if (write[i] != sample[j])
	    break;

	  i++; j++;

	  if (j == len - 1)
	    flag = 1;
	}
    }

  return flag;
}

int test_sub(char* write, char* sample)
{
  int i, j, len, flag = 0, k;
  len = strlen(sample);

  for (k = 0; k <= len - 1; k++)
    {
      i = j = 0;

      while (i <= len - 1)
	{
	  if (i == k)
	    {
	      i++;
	      j++;
	    }

	  if (sample[i] != write[j])
	    break;

	  i++; j++;

	  if (i == len || i == len + 1)
	    flag = 1;
	}
    }

  return flag;
}

int main(int argc, char *argv[])
{
  char check[20];
  int num, i, j, k, m, res1 = 0, res2 = 0, res3 = 0;
  scanf("%s", check);
  scanf("%d", &num);

  char** list = (char**)malloc(num * (sizeof(char*)));
  for (i = 0; i <= num - 1; i++)
    list[i] = (char*)malloc(20 * sizeof(char));

  for (i = 0; i <= num - 1; i++)
    scanf("%s", list[i]);

  for (m = 0; m <= num - 1; m++)
    {
      if ((strlen(check) - strlen(list[m])) == 0 && !strcmp(check, list[m]))
	{
	  printf("%s\n", check);
	  return 0;
	}
    }
  
  for (i = 0; i <= num - 1; i++)
    {
      if ((strlen(check) - strlen(list[i])) == -1)
	res1 = test_less(check, list[i]);

      if (res1 == 1)
	break;
    }

  for (j = 0; j <= num - 1; j++)
    {
      if ((strlen(check) - strlen(list[j])) == 1)
	res2 = test_more(check, list[j]);

      if (res2 == 1)
	break;
    }

  for (k = 0; k <= num - 1; k++)
    {
      if ((strlen(check) - strlen(list[k])) == 0)
	res3 = test_sub(check, list[k]);

      if (res3 == 1)
	break;
    }
  
  if (res1 == 0 && res2 == 0 && res3 == 0)
    puts("NOANSWER");

  if (i < j && i < k && res1 == 1)
    printf("%s\n", list[i]);

  if (j < i && j < k && res2 == 1)
    printf("%s\n", list[j]);

  if (k < i && k < j && res3 == 1)
    printf("%s\n", list[k]);
    
  return 0;
}
