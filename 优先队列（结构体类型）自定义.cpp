#include <stdio.h>
#include <algorithm>	//hdu 1873
#include <queue>
using namespace std;
typedef struct Ill{
	int val,num;
	friend bool operator<(Ill a,Ill b)	//排序规则自定义 
	{
		if(a.val==b.val) return a.num>b.num;
		return a.val<b.val;
	}
}ill;
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		char x[5];int a,b,k=0;
		priority_queue<Ill> q[4];	//注意再次声明相当于重置(在合适的地方声明让其正确重置) 
		while(n--)
		{
			scanf("%s",x);
			if(x[0]=='I')
			{
				scanf("%d %d",&a,&b);k++;
				ill ill;
				ill.val=b;ill.num=k;
				q[a].push(ill);
			}
			else
			{
				scanf("%d",&a);
				if(q[a].empty()) printf("EMPTY\n");
				else
				{
					printf("%d\n",q[a].top().num);
					q[a].pop();
				}
			}
		}
	}
	return 0;
}
