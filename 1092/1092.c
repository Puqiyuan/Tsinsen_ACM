#include <stdio.h>


int store_con(char *in_s, int *in_i)// The input is by char string form, and convert each element
// to int.
{
  int i;
  scanf("%s", in_s);

  for (i = 0; i <= 3; i++)
    in_i[i] = (int)(in_s[i] - 48);

  return 0;  
}


int test_store_con(char *in_s, int *in_i)// Show in_s and in_i judge store_con function is correct.
{
  int i;
  printf ("%s\n",in_s);

  for (i = 0; i <= 3; i++)
    printf("%d ", in_i[i]);

  printf("\n");


  return 0;
}


int module(int *in_i)// Add 5 and module.
{
  int i;

  for (i = 0;i <= 3; i++)
    in_i[i] = (in_i[i] + 5) % 10;

  return 0;
}


int swap(int *in_i)// Swap the first and fourth element, second and third element.
{
  int tmp;

  tmp = in_i[0];
  in_i[0] = in_i[3];
  in_i[3] = tmp;

  tmp = in_i[1];
  in_i[1] = in_i[2];
  in_i[2] = tmp;

  return 0;
}


int output(int *in_i)// Output the computing result, if there is no leading 0 output it.
{
  if (in_i[0] != 0)
    printf("%d", in_i[0]);

  printf("%d%d%d\n", in_i[1], in_i[2], in_i[3]);

  return 0;
}


int main(int argc, char *argv[])
{
  char in_s[4];
  int in_i[4];

  store_con(in_s, in_i);

  module(in_i);

  swap(in_i);

  output(in_i);
  
  return 0;
}
