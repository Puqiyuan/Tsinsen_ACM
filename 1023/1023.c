 #include"stdio.h"
int main()
{
    int a[11],i,n;
    scanf("%d",&n);
    a[0]=1;
    a[1]=1;
    for(i=2;i<=n;i++)
        a[i]=a[i-1]+a[i-2];
    printf("%d\n",a[n]);
    return 0;
}
 
