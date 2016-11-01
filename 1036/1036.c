#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* find_all_primes(int test_num, int* all_primes)
{
  int count = 1, j, cand;

  for (cand = 2; cand <= test_num; cand++)
    {
      for (j = 2; j <= sqrt(cand); j++)
	{
	  if (cand % j == 0)
	    break;
	}

      if (j == (int)sqrt(cand) + 1)
	{
	  all_primes[count] = cand;
	  count++;
	}
    }

  return all_primes;  
}

int* find_divide_primes(int* all_primes, int test_num, int* res)
{
  int quo, remin, count = all_primes[0], c_count = 1, test = 1;

  while (count >= 1 && test_num % all_primes[count] != 0)
    count--;

  res[c_count] = all_primes[count];
  test *= res[c_count];
  c_count++;

  if (test != test_num)
    {
      quo = test_num / all_primes[count];
      
      if (count > 1 && quo % all_primes[count] != 0)
	count--;

      remin = quo % all_primes[count];

      while (test_num != test)
	{
	  while (remin != 0)
	    {
	      if (count > 1)
		count--;
	      remin = quo % all_primes[count];
	    }

	  while (remin == 0)
	    {
	      res[c_count] = all_primes[count];
	      test *= res[c_count];
	      c_count++;

	      quo /= all_primes[count];
	      if (count >= 2 && quo % all_primes[count] != 0)
		count--;
	      	  	  
	      remin = quo % all_primes[count];
	    }
	}

      res[0] = c_count - 1;
    }
  
  else
    {
      res[0] = 1;
      res[1] = test_num;
    }

  return res;
}

int display(int* res, int test_num)
{
  int i;

  if (res[0] == 1)
    printf("%d=%d\n", test_num, test_num);
  else
    {
      printf("%d=", test_num);
      for (i = res[0]; i >= 2; i--)
	printf("%d*", res[i]);
      printf("%d\n", res[i]);
    }

  return 0;
}

int main(int argc, char *argv[])
{
  int a, b, i, len, *store, *all_primes;
  scanf("%d %d", &a, &b);
  len = b - a + 1;
  store = (int*)malloc(len * sizeof(int));
  all_primes = (int*)malloc(1230 * sizeof(int));
  store[0] = a;
  store[len - 1] = b;
  
  for (i = 1; i <= len - 2; i++)
    store[i] = ++a;

  all_primes[0] = 1229;
  all_primes = find_all_primes(10000, all_primes);
  
  for (i = 0; i <= len - 1; i++)
    {
      int *res = (int*)malloc(store[i] * sizeof(int));
      
      res = find_divide_primes(all_primes, store[i], res);
      display(res, store[i]);
      free(res);

    }
  free(store);
    
  return 0;
}
