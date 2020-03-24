#include <bits/stdc++.h>
using namespace std;
char a[100],b[100];
void solve(int x,int y,int z)	//中序起点  后序起点   根节点离后序位置起点的长度(也是需跨越的左区间长度) 
{
	if(z==0) return;
	int len;
	//打印根节点
	 printf("%c",b[y+z-1]);
	for(int i=x;i<x+z;i++)
	{
		if(a[i]==b[y+z-1]) len=i-x;
	}
	//寻找左子树 
	solve(x,y,len);
	//寻找右子树 
	solve(x+len+1,y+len,z-len-1);
}
int main()
{
	scanf("%s %s",a,b);
	solve(0,0,strlen(a));
	return 0;
}
