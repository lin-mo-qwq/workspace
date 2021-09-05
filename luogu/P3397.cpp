#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[1005][1005];
int main()
{
	cin>>n>>m;

	for(int i=1;i<=m;i++)
	{
		int x[3],y[3];
		
		for(int j=1;j<=2;j++)
			cin>>x[j]>>y[j];

		for(int j=x[1];j<=x[2];j++)
			f[j][y[1]]+=1,f[j][y[2]+1]-=1;
	}

	for(int i=1,s;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<(f[i][j]=f[i][j-1]+f[i][j])<<' ';
		
		puts("");
	}
	return 0;
}