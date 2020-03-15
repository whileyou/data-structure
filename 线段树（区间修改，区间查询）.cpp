#include <bits/stdc++.h>	//区间修改、区间查询--->线段树 
#define int long long
using namespace std;
int a[100001],tree[4*100001],lazy[4*100001];
void build(int l,int r,int num)	//num表线段树结点号 
{
	if(l==r)
	{
		tree[num]=a[l];	//叶子结点
		return;
	}
	//不断二分
	int m=(l+r)/2;
	build(l,m,2*num);	//2*num与2*num+1分别表左子节点与右子节点 
	build(m+1,r,2*num+1);
	//从叶节点开始回溯
	tree[num]=tree[2*num]+tree[2*num+1];
}
void update(int x,int y,int k,int l,int r,int num)		//该函数运用lazy-tag思想 
{
	//区间错误，跳回
	if(r<x||l>y) return;
	else	//求加和 
	{
		int len;		//覆盖长度 
		if(l>=x&&r<=y)		//lazy-tag思想--->停止更新 
		{
			lazy[num]+=k;
			return;
		}
		else if(l<x&&r>y) len=y-x+1;
		else if(x>l) len=r-x+1;
		else if(y<r) len=y-l+1;
		tree[num]+=len*k;
	}
	int m=(l+r)/2;
	update(x,y,k,l,m,2*num);update(x,y,k,m+1,r,2*num+1);
}
void ask(int x,int y,int l,int r,int num,int &ans)		//该函数亦运用lazy-tag思想 
{
	if(lazy[num])		//lazy-tag思想--->lazy值下放 
	{
		if(l!=r)
		{
			lazy[2*num]+=lazy[num];
			lazy[2*num+1]+=lazy[num];
		}
		tree[num]+=(r-l+1)*lazy[num];	//更新 
		lazy[num]=0;	//清零 
	}
	if(l>=x&&r<=y)
	{
		ans+=tree[num];
		return;
	}
	if(r<x||l>y) return;
	int m=(l+r)/2;
	ask(x,y,l,m,2*num,ans);ask(x,y,m+1,r,2*num+1,ans);
}
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	//建立线段树 
	build(1,n,1);
	while(m--)
	{
		int d,x,y,k;
		scanf("%lld",&d);
		if(d==1)
		{
			scanf("%lld %lld %lld",&x,&y,&k);
			update(x,y,k,1,n,1);
		}
		else
		{
			scanf("%lld %lld",&x,&y);
			int ans=0;
			ask(x,y,1,n,1,ans);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
