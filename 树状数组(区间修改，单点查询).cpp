#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500001],b[500001],tree[500001],n,m;	//aԭ���飬b������� 
void add(int x,int k)
{
	while(x<=n)
	{
		tree[x]+=k;
		x+=x&-x;
	}
}
int ask(int x)	//��xǰ׺�� 
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
	//���� 
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(i>1) b[i-1]=a[i]-a[i-1];
		int j=i;
		while(j<=n) 
		{
			tree[j]+=b[i];	//�������ת������״���� 
			j+=j&-j;
		}
	}
	//����
	while(m--)
	{
		int d;
		scanf("%lld",&d);
		if(d==1)	//�����޸� 
		{
			int x,y,k;
			scanf("%lld %lld %lld",&x,&y,&k);
			add(x,k);add(y+1,-k);	//�����ǲ�ֵ���״���飬�߽���������ͬʱ���ӣ����������Ϊ0 
		}
		else		//�����ѯ 
		{
			int x;scanf("%lld",&x);
			printf("%lld\n",a[x]+ask(x));
		}
	} 
	return 0;
}
