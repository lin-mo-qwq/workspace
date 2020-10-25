#include<bits/stdc++.h>
using namespace std;
int m, n;
int a[105];
int f[105][10005];
int main()
{
	cin>>n>>m;
	for(int i = 1; i <= n; i++) cin>>a[i];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if(j == a[i]) f[i][j] = f[i - 1][j] + 1;
			else if(j > a[i]) f[i][j] = f[i - 1][j - a[i]] + f[i - 1][j];
			else f[i][j] = f[i - 1][j];
		}
	cout<<f[n][m];
	return 0;
}