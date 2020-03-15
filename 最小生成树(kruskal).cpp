#include <bits/stdc++.h>	//kruskal算法(蕴含并查集思想--->判断图是否构成环) 
using namespace std;		//见洛谷P3366 
int pre[5001],ans,all;
struct edge{
	int x,y,z;
}edge[200001];
int find(int x)
{
	if(!pre[x]||pre[x]==x) return x;
	return pre[x]=find(pre[x]);		//路径压缩 
}
bool cmp(struct edge a,struct edge b)
{
	return a.z<b.z;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		edge[i+1].x=x,edge[i+1].y=y,edge[i+1].z=z;
		int prex=find(x),prey=find(y);
		pre[prex]=prey;
	}
	int jud=0,t=0;
	for(int i=1;i<=n;i++)	//并查集判断图是否连通 
	{
		if(!find(i)&&!jud)
		{
			jud=1;continue;
		}
		if(!t) t=find(i);
		else if(t!=find(i))
		{
			cout<<"orz";return 0;
		}
	}
	sort(edge+1,edge+m+1,cmp);
	memset(pre,0,sizeof(pre));
	for(int i=1;all<n-1;i++)	//并查集查询所选边与残图是否连通，连通必成环！ 
	{
		int prex=find(edge[i].x),prey=find(edge[i].y);
		if(prex!=prey)
		{
			ans+=edge[i].z;
			all++;
			if(!prex) pre[edge[i].x]=prey;
			else if(!prey) pre[edge[i].y]=prex;
			else pre[prex]=prey;
		}
	}
	cout<<ans;
	return 0;
}
