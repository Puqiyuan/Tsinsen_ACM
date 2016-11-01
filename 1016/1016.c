#include <stdio.h>

int main(int argc, char *argv[])
{
  int n, i;
  float res;

  scanf("%d",&n);
  float store[n][2];
  for (i = 0; i <= n -1; i++)
    scanf("%f %f",&store[i][0], &store[i][1]);
  
  for (i = 0; i <= n - 1; i++)
    {
      res = (float)((int)((3.141592 * (store[i][0] * store[i][0] +
				store[i][1] * store[i][1])) / 100) + 1);
      printf("%.f\n",res);
    }
  
  return 0;
}


