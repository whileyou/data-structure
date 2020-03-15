#include <bits/stdc++.h>
using namespace std;		//�����޸ģ������ѯ 
int a[500001],tree[500001];
int lowbit(int x)
{
	return x&-x;
}
int ask(int x)
{
	int ans=0;
	while(x)
	{
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	//������״����
	for(int i=1;i<=n;i++)
	{
		int x=i;
		while(x<=n)
		{
			tree[x]+=a[i]; 
			x+=lowbit(x);
		}
	} 
	while(m--)
	{
		int d,x,y;
		scanf("%d %d %d",&d,&x,&y);
		if(d==1)	//���� 
		{
			int xx=x;
			while(xx<=n)
			{
				tree[xx]+=y;
				xx+=lowbit(xx);
			}
		}
		else	//��ѯ 
		{
			printf("%d\n",ask(y)-ask(x-1));
		}
	}
	return 0;
}
