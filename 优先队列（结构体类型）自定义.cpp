#include <stdio.h>
#include <algorithm>	//hdu 1873
#include <queue>
using namespace std;
typedef struct Ill{
	int val,num;
	friend bool operator<(Ill a,Ill b)	//��������Զ��� 
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
		priority_queue<Ill> q[4];	//ע���ٴ������൱������(�ں��ʵĵط�����������ȷ����) 
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
