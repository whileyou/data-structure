#include <stdio.h>		//rmq--->区间最值查询问题 
#include <algorithm>
using namespace std;
int a[200001],tree[4*200001];
void build(int l,int r,int num)
{
	if(l==r)
	{
		tree[num]=a[l];
		return;
	}
	int m=(l+r)/2;
	build(l,m,2*num);
	build(m+1,r,2*num+1);
	tree[num]=max(tree[2*num],tree[2*num+1]);
}
void u(int x,int y,int l,int r,int num)
{
	if(l==r)
	{
		if(l==x) tree[num]=y;
		return;
	}
	if(x<l||x>r) return;
	int m=(l+r)/2;
	u(x,y,l,m,2*num);
	u(x,y,m+1,r,2*num+1);
	tree[num]=max(tree[2*num],tree[2*num+1]);
}
void q(int x,int y,int l,int r,int num,int &t)
{
	if(y<l||x>r) return;
	if(l>=x&&r<=y)
	{
		t=max(tree[num],t);return;
	}
	int m=(l+r)/2;
	q(x,y,l,m,2*num,t);
	q(x,y,m+1,r,2*num+1,t);
}
int main()
{
	int n,m;
	while(~scanf("%d %d",&n,&m))
	{
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		build(1,n,1);
		while(m--)
		{
			char c;int x,y;
			scanf(" %c %d %d",&c,&x,&y);
			if(c=='Q')
			{
				int t=0;
				q(x,y,1,n,1,t);
				printf("%d\n",t);
			}
			else if(c=='U')
			{
				u(x,y,1,n,1);
			}
		}
	}
	return 0;
} 
