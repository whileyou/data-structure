#include <bits/stdc++.h>	//�����޸ġ������ѯ--->�߶��� 
#define int long long
using namespace std;
int a[100001],tree[4*100001],lazy[4*100001];
void build(int l,int r,int num)	//num���߶������� 
{
	if(l==r)
	{
		tree[num]=a[l];	//Ҷ�ӽ��
		return;
	}
	//���϶���
	int m=(l+r)/2;
	build(l,m,2*num);	//2*num��2*num+1�ֱ�����ӽڵ������ӽڵ� 
	build(m+1,r,2*num+1);
	//��Ҷ�ڵ㿪ʼ����
	tree[num]=tree[2*num]+tree[2*num+1];
}
void update(int x,int y,int k,int l,int r,int num)		//�ú�������lazy-tag˼�� 
{
	//�����������
	if(r<x||l>y) return;
	else	//��Ӻ� 
	{
		int len;		//���ǳ��� 
		if(l>=x&&r<=y)		//lazy-tag˼��--->ֹͣ���� 
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
void ask(int x,int y,int l,int r,int num,int &ans)		//�ú���������lazy-tag˼�� 
{
	if(lazy[num])		//lazy-tag˼��--->lazyֵ�·� 
	{
		if(l!=r)
		{
			lazy[2*num]+=lazy[num];
			lazy[2*num+1]+=lazy[num];
		}
		tree[num]+=(r-l+1)*lazy[num];	//���� 
		lazy[num]=0;	//���� 
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
	//�����߶��� 
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
