#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500001],b[500001],tree[500001],n,m;	//treeά��xǰ�Ĺ۲⣬�Աȳ�x�ı仯 
void add(int x,int k)
{
	while(x<=n)
	{
		tree[x]+=k;
		x+=x&-x;
	}
}
int ask(int x)	//��xǰ׺��(�ܵĹ۲�仯) 
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
	//����--->��״���鼴Ϊȫ��0(��Ϊ�������aû�з����仯) 
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]); 
	//����
	while(m--)
	{
		int d;
		scanf("%lld",&d);
		if(d==1)	//�����޸� 
		{
			int x,y,k;
			scanf("%lld %lld %lld",&x,&y,&k);
			add(x,k);add(y+1,-k);	//���������ǹ۲��� 
		}
		else		//�����ѯ 
		{
			int x;scanf("%lld",&x);
			printf("%lld\n",a[x]+ask(x));
		}
	} 
	return 0;
}
