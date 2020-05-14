#include<bits/stdc++.h>
using namespace std;

int n,m,s;
int f[1000][1000];

void inp()
{
	cin>>n>>m>>s;

	for(int i=1;i<=m;i++)
	{
		int from,to,key;
		cin>>from>>to>>key;
		f[from][to]=key;
	}
}	

void floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
}

void print()
{
	for(int i=1;i<=n;i++)
		cout<<f[s][i]<<endl;
}

int main()
{
	inp();
	floyd();
	print();
	return 0;
}