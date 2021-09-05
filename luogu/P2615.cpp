#include<bits/stdc++.h>
using namespace std;
int n;
int x,y;
int a[100][100];

void giv(int _x,int _y)
{
	x=_x,y=_y;
}

void work(int n)
{

	for(int i=1;i<=n*n;i++)
	{
		if(i==1)
			a[1][n/2+1]=i,giv(1,n/2+1);
		else if (x==1&&y!=n)
			a[n][y+1]=i,giv(n,y+1);
		else if(x!=1&&y==n)
			a[x-1][1]=i,giv(x-1,1);
		else if(x==1&&y==n)
			a[x+1][y]=i,giv(x+1,y);
		else if(x != 1 && y != n)
			(!a[x-1][y+1])?(a[x-1][y+1]=i,giv(x-1,y+1)):(a[x+1][y]=i,giv(x+1,y));
	}
}

void output(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<a[i][j]<<' ';
		puts("");
	}
}

int main()
{
	cin>>n;
	work(n);
	output(n);
	return 0;
}