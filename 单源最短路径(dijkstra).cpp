#include <bits/stdc++.h>	//�㷨ѧϰ��ַ��https://www.bilibili.com/video/av54668527/?spm_id_from=333.788.videocard.0 
using namespace std;		//��Դ���·��(dijkstra) //��ʽǰ���ǣ��ٽӾ����ڴ�(��a[10000][10000]�ͻ�ը��)��
int visit[10001],go[10001],head[10001],jud;
struct edge{
	int to,w,next;
}edge[500001];
int main()
{
	int n,m,s,s1;
	cin>>n>>m>>s;
	s1=s;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		edge[i].to=y,edge[i].w=z,edge[i].next=head[x],head[x]=i;
	}
	//sΪ���
	while(jud<n)
	{
		visit[s]=1;
		jud++;
		for(int i=head[s];i;i=edge[i].next)	 //1.�������׼������ͨ�ĵ��·��ֵ 
		{
			if(!visit[edge[i].to]&&(!go[edge[i].to]||go[edge[i].to]>go[s]+edge[i].w))
			go[edge[i].to]=go[s]+edge[i].w;
		}
		int min=INT_MAX,t;
		for(int i=1;i<=n;i++)	//2.Ѱ����Сֵ(����Ϊ��׼��)
		{
			if(!visit[i]&&go[i]&&min>go[i])
			{
				min=go[i];t=i;
			}
		}
		if(min==INT_MAX) break;
		s=t;					//3.��Ϊ��׼��ʹ��
	}
	for(int i=1;i<=n;i++)
	{
		if(i>1) cout<<" ";
		if(i!=s1&&!go[i]) cout<<INT_MAX;
		else cout<<go[i];
	}
	return 0;
}
