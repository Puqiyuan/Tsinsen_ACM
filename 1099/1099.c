#include <stdio.h>
#include <stdlib.h>



int store(char **W1, char **W2)// store 16 words said by 8 eight people
{
  int i;
  
  for (i = 0; i <= 7; i++)
    scanf("%s %s", W1[i], W2[i]);

  return 0;
}


int s_to_n(char *s)// represent string by number
{
  int flag;
  if ( (s[0] == 'm' || s[0] == 'M') && (s[1] == 'o' || s[1] == 'O') &&
       (s[2] == 'n' || s[2] == 'N') && (s[3] == 'd' || s[3] == 'D') &&
       (s[4] == 'a' || s[4] == 'A') && (s[5] == 'y' || s[5] == 'Y') )
    flag = 1;

  if ( (s[0] == 't' || s[0] == 'T') && (s[1] == 'u' || s[1] == 'U') &&
       (s[2] == 'e' || s[2] == 'E') && (s[3] == 's' || s[3] == 'S') &&
       (s[4] == 'd' || s[4] == 'D') && (s[5] == 'a' || s[5] == 'A') &&
       (s[6] == 'y' || s[6] == 'Y') )
    flag = 2;

  if ( (s[0] == 'w' || s[0] == 'W') && (s[1] == 'e' || s[1] == 'E') &&
       (s[2] == 'd' || s[2] == 'D') && (s[3] == 'n' || s[3] == 'N') &&
       (s[4] == 'e' || s[4] == 'E') && (s[5] == 's' || s[5] == 'S') &&
       (s[6] == 'd' || s[6] == 'D') && (s[7] == 'a' || s[7] == 'A') &&
       (s[8] == 'y' || s[8] == 'Y') )
    flag = 3;

  if ( (s[0] == 't' || s[0] == 'T') && (s[1] == 'h' || s[1] == 'H') &&
       (s[2] == 'u' || s[2] == 'U') && (s[3] == 'r' || s[3] == 'R') &&
       (s[4] == 's' || s[4] == 'S') && (s[5] == 'd' || s[5] == 'D') &&
       (s[6] == 'a' || s[6] == 'A') && (s[7] == 'y' || s[7] == 'Y') )
    flag = 4;

  if ( (s[0] == 'f' || s[0] == 'F') && (s[1] == 'r' || s[1] == 'R') &&
       (s[2] == 'i' || s[2] == 'I') && (s[3] == 'd' || s[3] == 'D') &&
       (s[4] == 'a' || s[4] == 'A') && (s[5] == 'y' || s[5] == 'Y') )
    flag = 5;

  if ( (s[0] == 's' || s[0] == 'S') && (s[1] == 'a' || s[1] == 'A') &&
       (s[2] == 't' || s[2] == 'T') && (s[3] == 'u' || s[3] == 'U') &&
       (s[4] == 'r' || s[4] == 'R') && (s[5] == 'd' || s[5] == 'D') &&
       (s[6] == 'a' || s[6] == 'A') && (s[7] == 'y' || s[7] == 'Y') )
    flag = 6;

  if ( (s[0] == 's' || s[0] == 'S') && (s[1] == 'u' || s[1] == 'U') &&
       (s[2] == 'n' || s[2] == 'N') && (s[3] == 'd' || s[3] == 'D') &&
       (s[4] == 'a' || s[4] == 'A') && (s[5] == 'y' || s[5] == 'Y') )
    flag = 7;
  

  return flag;
}


int store_int(int **n, char **s1, char **s2)// store all int values with respect to string
{
  int i;

  for (i = 0; i <= 7; i++)
    {
      n[i][0] = s_to_n(s1[i]);
      n[i][1] = s_to_n(s2[i]);
    }

  return 0;
}


int judge(int **n, int day, int *res)// check one day if it is a solution
{
  int i;

  res[0] = day;
  
  for (i = 0; i <= 7; i++)
    {
      if ( ( (n[i][1] != day) && (n[i][0] != day)) ||
	   ( ((n[i][1] != day) == 0) && (n[i][0] == day)) )
	res[i+1] = 1;

      else
	res[i+1] = 0;
    }

  return 0;
}


int result(int *res)// a solution should agree with all 16 words
{
  int count = 0, i;

  for (i = 1; i <= 8; i++)
    {
      if (res[i] == 1)
	count++;
    }

  return count;
}


int answer_show(int n)// show string rather than number
{
  if (n == 1)
    printf("Monday\n");
  
  else if (n == 2)
    printf("Tuesday\n");

  else if (n == 3)
    printf("Wednesday\n");

  else if (n == 4)
    printf("Thursday\n");

  else if (n == 5)
    printf("Friday\n");

  else if (n == 6)
    printf("Saturday\n");

  else
    printf("Sunday\n");

  return 0;
}


int main(int argc, char *argv[])
{
  char **W1, **W2;
  int i, **n, *res, *answers, day, k = 0, u_answer;
  
  W1 = (char**)malloc(8 * sizeof(char*));
  W2 = (char**)malloc(8 * sizeof(char*));
  n = (int**)malloc(8 * sizeof(int*));
  res = (int*)malloc(8 * sizeof(int));
  answers = (int*)malloc(7 * sizeof(int));
  
  for (i = 0; i <= 7; i++)
    {
      W1[i] = (char*)malloc(10 * sizeof(char));
      W2[i] = (char*)malloc(10 * sizeof(char));
      n[i] = (int*)malloc(2 * sizeof(int));
    }

  store(W1, W2);
  store_int(n, W1, W2);

  for (day = 1; day <= 7; day++)
    {
      judge(n, day, res);

      if (result(res) == 8)
	{
	  answers[k] = res[0];
	  k++;
	}
    }

  u_answer = answers[0];
  for (i = 0; i <= k - 1; i++)
    {
      if (answers[i] < u_answer)
	u_answer = answers[i];
    }
  
  answer_show(u_answer);
  
  return 0;
}
