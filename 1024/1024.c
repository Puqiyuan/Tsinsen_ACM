#include <stdio.h>
int main()
{
	int a[10][2]={1,1,1,0,3,1};
	int b[10][3]={1,1,0,0,0,0,2,1,1};
	int i,n;

	for(i=3;i<10;i++)
	{
		a[i][1]=a[i-1][0]-a[i-1][1];
		a[i][0]=a[i-3][0]+a[i-2][0]+a[i][1];
		b[i][2]=b[i-3][0]+b[i-2][0];
		b[i][1]=b[i-1][2]+a[i][1];
		b[i][0]=b[i][2]+b[i][1];
	}
	scanf("%d",&n);
	printf("%d\n%d\n",a[n-1][0],b[n-1][0]);
	return 0;
}
 
