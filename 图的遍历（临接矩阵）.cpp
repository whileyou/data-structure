#include <bits/stdc++.h>
using namespace std;
#define n 5
int visit[n];
int graph[n][n]={
	{0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0}
	};
void scan(int i)	//��ѡ���������ٽӵ�ɨ�� 
{
	printf("%d\n",i);
	visit[i]=1;
	for(int j=0;j<n;j++)
	{
		if(graph[i][j]&&!visit[j]) scan(j);		 //������һ���ٽӵ� 
	}
}
int main()
{
	//dfs����
	scan(0);
	return 0;
}
