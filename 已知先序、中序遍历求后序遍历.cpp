#include <bits/stdc++.h>
using namespace std;
char a[100],b[100];
void solve(int x,int y,int z)	//�������  �������   ���ڵ������λ�����ĳ���(Ҳ�����Խ�������䳤��) 
{
	if(z==0) return;
	int len;
	//��ӡ���ڵ�
	 printf("%c",b[y+z-1]);
	for(int i=x;i<x+z;i++)
	{
		if(a[i]==b[y+z-1]) len=i-x;
	}
	//Ѱ�������� 
	solve(x,y,len);
	//Ѱ�������� 
	solve(x+len+1,y+len,z-len-1);
}
int main()
{
	scanf("%s %s",a,b);
	solve(0,0,strlen(a));
	return 0;
}
