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
void scan(int i)	//对选定结点进行临接点扫描 
{
	printf("%d\n",i);
	visit[i]=1;
	for(int j=0;j<n;j++)
	{
		if(graph[i][j]&&!visit[j]) scan(j);		 //跳入下一个临接点 
	}
}
int main()
{
	//dfs遍历
	scan(0);
	return 0;
}
