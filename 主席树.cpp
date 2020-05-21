//洛谷P3834
//算法学习:https://www.bilibili.com/video/BV1C4411u7rK?t=1404&p=2 
#include <bits/stdc++.h>
using namespace std;
#define maxn 200001
int n,m,a[maxn],seq[maxn],l,r,k,root[maxn],cnt,nx;
struct tree{
	int l,r,val;
}tree[maxn*40];		//注意主席树开40倍(一般线段树开4倍) 
void update(int l,int r,int x,int pre,int &now)
{
	tree[++cnt]=tree[pre];	//产生新的结点并赋值上一版本信息 
	tree[cnt].val++;	//旧版本基础上更新权值得新版本 
	now=cnt;	//关键点，起两个作用(址传递效果)：
				//1.更新root的信息 
				//2.将该版本线段树上一个结点的左或右指针连上该结点 
	if(l==r) return;	//更新至叶节点，完毕，退出 
	int m=(l+r)>>1;
	//pre与now同步走，便于给新版本线段树结点赋值上一个版本的信息 
	if(x<=m) update(l,m,x,tree[pre].l,tree[now].l);
	else update(m+1,r,x,tree[pre].r,tree[now].r);
}
void ask(int l,int r,int k,int L,int R,int &ans)
{
	if(l==r){	//查找完毕 
		ans=l;return;
	}
	int know=tree[tree[R].l].val-tree[tree[L].l].val,m=(l+r)>>1;
	//若两版本左子树权值之差<=know，则在左子树，否则在右子树 
	//在右子树时，左子树已有know个，需变为k-know 
	if(k<=know)	ask(l,m,k,tree[L].l,tree[R].l,ans);
	else ask(m+1,r,k-know,tree[L].r,tree[R].r,ans);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),seq[i]=a[i];
	//离散化
	sort(seq+1,seq+n+1);	//排序去重
	for(int i=1,j=1;i<=n;i++){
		if(i!=1&&seq[i]==seq[j-1]) continue;
		seq[j++]=seq[i];nx++;
	}
	for(int i=1;i<=n;i++){
		int id=lower_bound(seq+1,seq+1+nx,a[i])-seq;
		update(1,nx,id,root[i-1],root[i]);
	}
	while(m--){
		scanf("%d %d %d",&l,&r,&k);
		int ans=0;
		//前缀和思想，利用第r版本与l-1版本线段树作差得第k小 
		ask(1,nx,k,root[l-1],root[r],ans);
		printf("%d\n",seq[ans]);
	}
	return 0;
}
