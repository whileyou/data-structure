#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500001],b[500001],tree[500001],n,m;	//tree维护x前的观测，对比出x的变化 
void add(int x,int k)
{
	while(x<=n)
	{
		tree[x]+=k;
		x+=x&-x;
	}
}
int ask(int x)	//求x前缀和(总的观测变化) 
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
	//建立--->树状数组即为全是0(因为相对数组a没有发生变化) 
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]); 
	//操作
	while(m--)
	{
		int d;
		scanf("%lld",&d);
		if(d==1)	//区间修改 
		{
			int x,y,k;
			scanf("%lld %lld %lld",&x,&y,&k);
			add(x,k);add(y+1,-k);	//区间两侧是观测者 
		}
		else		//单点查询 
		{
			int x;scanf("%lld",&x);
			printf("%lld\n",a[x]+ask(x));
		}
	} 
	return 0;
}
