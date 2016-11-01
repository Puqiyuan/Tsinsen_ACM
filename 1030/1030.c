#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

struct node{
  char name[25];
  int jf,js,jq;
  int l;
}a[15];
int min(int x,int y) {return x<y?x:y;}
int comp(const void *x,const void *y)
{
  node n1=*(node *)x;
  node n2=*(node *)y;
  if(n1.jf!=n2.jf) return n2.jf-n1.jf;
  else if(n1.js!=n2.js) return n2.js-n1.js;
  else if(n1.jq!=n2.jq) return n2.jq-n1.jq;
  else
    {
      for(int i=0;i<min(n1.l,n2.l);i++)
	if(n1.name[i]!=n2.name[i]) return n1.name[i]-n2.name[i];
    }
  return n1.l-n2.l;
}
int main()
{
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
    {
      scanf("%s",a[i].name);
      scanf("%d%d%d",&a[i].jf,&a[i].js,&a[i].jq);
      a[i].l=strlen(a[i].name);
    }
  qsort(a+1,n,sizeof(node),comp);
  for(int i=1;i<=n;i++)
    printf("%s\n",a[i].name);
  return 0;
}
 
