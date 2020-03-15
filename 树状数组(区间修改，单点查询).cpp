#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500001],b[500001],tree[500001],n,m;	//a原数组，b差分数组 
void add(int x,int k)
{
	while(x<=n)
	{
		tree[x]+=k;
		x+=x&-x;
	}
}
int ask(int x)	//求x前缀和 
{
	int ans=0;
	while(x)
	{
		ans+=tree[x];
		x-=x&-x;
	}
	return ans;
}
signed main()
{
	cin>>n>>m;
	//建立 
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(i>1) b[i-1]=a[i]-a[i-1];
		int j=i;
		while(j<=n) 
		{
			tree[j]+=b[i];	//差分数组转换成树状数组 
			j+=j&-j;
		}
	}
	//操作
	while(m--)
	{
		int d;
		scanf("%lld",&d);
		if(d==1)	//区间修改 
		{
			int x,y,k;
			scanf("%lld %lld %lld",&x,&y,&k);
			add(x,k);add(y+1,-k);	//由于是差分的树状数组，边界内相邻数同时增加，差分增加量为0 
		}
		else		//单点查询 
		{
			int x;scanf("%lld",&x);
			printf("%lld\n",a[x]+ask(x));
		}
	} 
	return 0;
}
