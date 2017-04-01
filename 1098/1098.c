#include <stdio.h>
 
int main() 
{
  int n, m, a[16], i, j, t, y;
	
  scanf("%d%d", &n, &m);
  for(i = 0; i < n; i++)
    a[i] = 1;
  
  j = n - 1;
  if(m == 1)
    {
      while(1)
	{
	  printf("%d=%d", n, a[0]);
	  
	  for(i = 1; i <= j; i++)
	    printf("+%d", a[i]);
	  printf("\n");
	  
	  if(!j)
	    break;
	  
	  a[j - 1]++, t = a[j] - 1, j--;
	  while(t --)
	    a[++j] = 1;		
	}	
    }
  else{
    while(1)
      {
	printf("%d=%d", n, a[0]);
	
	for(i = 1; i <= j; i++) printf("+%d", a[i]);
	printf("\n");
	if(!j)
	  break;
	y = ++a[j - 1], t = a[j] - 1, j--;
	
	while(t >= y)
	  {
	    a[++j] = y;
	    t -= y;
	  }
	a[j] += t;	
      }
  }
  return 0;
}
