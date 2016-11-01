#include <iostream>
using namespace std;
 
 
int maxmin_0(int a,int b, int c,int *max,int *min)
{
	
  if(a>b)
    *max=a;
  else
    *max=b;
  if(*max<c)
    *max=c;
	
 
  if(a<b)
    *min=a;
  else
    *min=b;
  if(*min>c)
    {	*min=c;}
  return *max,*min;
 
	
	
}

int maxmin_1(int a,int b, int c,int &max,int &min)
{
	
  if(a>b)
    max=a;
  else
    max=b;
  if(max<c)
    max=c;
  if(a<b)
    min=a;
  else
    min=b;
  if(min>c)
    { min=c;}
  return max,min;
	
	
}

