#include <stdio.h>
#include <stdlib.h>

double max(double a, double b)
{
  if (a > b)
    return a;

  else
    return b;
}

double min(double a, double b)
{
  if (a < b)
    return a;

  else
    return b;
}

int judge_y(double *A, double *B)//y判断相离
{
  double A_min_y, B_max_y, A_max_y, B_min_y;
  int flag = 1;
  
  A_min_y = min(A[1], A[3]);
  B_max_y = max(B[1], B[3]);

  if (A_min_y >= B_max_y)
    flag = 0;

  B_min_y = min(B[1], B[3]);
  A_max_y = max(A[1], A[3]);

  if (B_min_y >= A_max_y)
    flag = 0;

  return flag;
}

int judge_x(double *A, double *B)//x判断相离
{
  double A_min_x, B_max_x, A_max_x, B_min_x;
  int flag = 1;

  A_min_x = min(A[0], A[2]);
  B_max_x = max(B[0], B[2]);

  if (A_min_x >= B_max_x)
    flag = 0;

  B_min_x = min(B[0], B[2]);
  A_max_x = max(A[0], A[2]);

  if (B_min_x >= A_max_x)
    flag = 0;

  return flag;
}

double* insertion_sort( double* A, int length )//插入排序用于对四个x和四个y值进行排序，分别取x和y第二大，第三大
{                                            //值做差相乘即为交的面积。
  int i, j;
  double key;
  
  for ( j = 0; j <= length - 1; j++ )
    {
      key = A[j];
      i = j - 1;
      while ( i >= 0 && A[i] < key )
        {
          A[i + 1] = A[i];
          i = i - 1;
        }
      A[i + 1] = key;
    }
  
  return A;
}



int main(int argc, char *argv[])
{
  double A[4], B[4], X[4], Y[4], area = 0;
  int flag = 1;

  scanf("%lf %lf %lf %lf", &A[0], &A[1], &A[2], &A[3]);//A矩形两点

  scanf("%lf %lf %lf %lf", &B[0], &B[1], &B[2], &B[3]);//B矩形两点

  flag = judge_y(A, B);
  if (flag == 1)
    {
      flag = judge_y(B, A);
      if (flag == 1)
	{
	  flag = judge_x(A, B);
	  if (flag == 1)
	    flag = judge_x(B, A);
	}
    }
    
  if ( !flag )
    printf("0.00\n");

  else
    {
      X[0] = A[0]; X[1] = A[2]; X[2] = B[0]; X[3] = B[2];
      Y[0] = A[1]; Y[1] = A[3]; Y[2] = B[1]; Y[3] = B[3];
      
      insertion_sort(X, 4);
      insertion_sort(Y, 4);

      area = (X[2] - X[1]) * (Y[2] - Y[1]);
      printf("%.2f\n", area);
    }
  
  return 0;
}
