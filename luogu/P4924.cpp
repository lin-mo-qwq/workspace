#include<bits/stdc++.h>
using namespace std;

#define len 505

int n,m;
int matrix[len][len];

void ssj(int x,int y,int r)
{
	int tempmatrix[len][len];

	for(int i=x-r;i<=x+r;i++)
		for(int j=y-r;j<=y+r;j++)
			tempmatrix[i][j]=matrix[i][j];

	int h=x+r,k=y-r;

	for(int i=x-r;i<=x+r;i++)
	{	
		for(int j=y-r;j<=y+r;j++)
		{
			matrix[i][j]=tempmatrix[h--][k];
			if(matrix[i][j]==0)
				cout<<"ERRO!";
		}
		h=x+r,k++;
	}
}

void nsj(int x,int y,int r)
{
	int tempmatrix[len][len];

	for(int i=x-r;i<=x+r;i++)
		for(int j=y-r;j<=y+r;j++)
			tempmatrix[i][j]=matrix[i][j];

	int h=x-r,k=y+r;

	for(int i=x-r;i<=x+r;i++)
	{	
		for(int j=y-r;j<=y+r;j++)
		{
			matrix[i][j]=tempmatrix[h++][k];
			if(matrix[i][j]==0)
				cout<<"ERRO!";
		}	
		h=x-r,k--;
	}
}

void work()
{
	int tem=1;
	int x,y,r,z;

	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			matrix[i][j]=tem++;
	
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>r>>z;
		if(!z)
			ssj(x,y,r);			
		else
			nsj(x,y,r);
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<matrix[i][j]<<" ";
		puts("");
	}
}

int main()
{
	work();
	return 0;
}