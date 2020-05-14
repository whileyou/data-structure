#include<bits/stdc++.h>
using namespace std;
#define maxn 100001
#define int long long
int n,m,p,x,y,k,t,a[maxn];
int tree[maxn*4],lazy1[maxn*4],lazy2[maxn*4];
inline void build(int L,int R,int i)
{
	lazy1[i]=1;
	if(L==R){
		tree[i]=(tree[i]+a[L])%p;return;
	}
	int m=(L+R)>>1;
	build(L,m,i<<1);
	build(m+1,R,(i<<1)+1);
	tree[i]=(tree[i<<1]+tree[(i<<1)+1])%p;
}
inline void down(int L,int R,int i)
{
	if((i<<1)+1<4*maxn)
	{
		lazy1[i<<1]=lazy1[i<<1]*lazy1[i]%p;
		lazy1[(i<<1)+1]=lazy1[(i<<1)+1]*lazy1[i]%p;
		lazy2[i<<1]=lazy2[i<<1]*lazy1[i]%p;
		lazy2[(i<<1)+1]=lazy2[(i<<1)+1]*lazy1[i]%p;
	}
	if((i<<1)+1<4*maxn)
	{
		lazy2[i<<1]=(lazy2[i<<1]+lazy2[i])%p;
		lazy2[(i<<1)+1]=(lazy2[(i<<1)+1]+lazy2[i])%p;
	}
	lazy1[i]=1;lazy2[i]=0;
}
inline void find(int L,int R,int l,int r,int i,int &got)
{
	if(R<l||L>r) return;
	if(lazy1[i]!=1||lazy2[i])
	{
		tree[i]=(tree[i]*lazy1[i]+lazy2[i]*(R-L+1))%p;
		down(L,R,i);
	}
	if(L>=l&&L<=r&&R>=l&&R<=r){		//!!
		got=(got+tree[i])%p;return;
	}
	int m=(L+R)>>1;
	find(L,m,l,r,i<<1,got);
	find(m+1,R,l,r,(i<<1)+1,got);
}
inline void update(int L,int R,int l,int r,int k,int i)
{
	if(R<l||L>r) return;
	if(L>=l&&L<=r&&R>=l&&R<=r){
		if(t==1) lazy1[i]=lazy1[i]*k%p,lazy2[i]=lazy2[i]*k;
		else lazy2[i]=(lazy2[i]+k)%p;
		return;
	}
	if(lazy1[i]!=1||lazy2[i])
	{
		tree[i]=(tree[i]*lazy1[i]+lazy2[i]*(R-L+1))%p;
		down(L,R,i);
	}
	int len,got=0;
	if(t==1){
		if(L<=l&&R>=r) find(L,R,l,r,i,got);
		else if(L>=l&&L<=r) find(L,R,L,r,i,got);
		else find(L,R,l,R,i,got);
		tree[i]=(tree[i]+got*(k-1))%p;
	}
	else{
		if(L<=l&&R>=r) len=r-l+1;
		else if(L>=l&&L<=r) len=r-L+1;
		else len=R-l+1;
		tree[i]=(tree[i]+len*k)%p;
	}
	int m=(L+R)>>1;
	update(L,m,l,r,k,i<<1);
	update(m+1,R,l,r,k,(i<<1)+1);
}
inline void ask(int L,int R,int l,int r,int i,int &ans)
{
	if(R<l||L>r) return;
	if(lazy1[i]!=1||lazy2[i])
	{
		tree[i]=(tree[i]*lazy1[i]+lazy2[i]*(R-L+1))%p;
		down(L,R,i);
	}
	if(L>=l&&L<=r&&R>=l&&R<=r){
		ans=(ans+tree[i])%p;return;
	}
	int m=(L+R)>>1;
	ask(L,m,l,r,i<<1,ans);
	ask(m+1,R,l,r,(i<<1)+1,ans);
}
signed main()
{	
	scanf("%lld %lld %lld",&n,&m,&p);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	build(1,n,1);
	for(int i=1;i<=m;i++){
		scanf("%lld",&t);
		if(t==1||t==2){
			scanf("%lld %lld %lld",&x,&y,&k);
			update(1,n,x,y,k,1);
		}
		else{
			scanf("%lld %lld",&x,&y);
			int ans=0;
			ask(1,n,x,y,1,ans);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
