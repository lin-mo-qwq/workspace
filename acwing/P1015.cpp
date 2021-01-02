#include<bits/stdc++.h>
using namespace std;
int f[105][105], t, r, c;

int find_max(int r, int c)
{
	for(int i = 1; i <= r; i++)
		for(int j = 1; j <= c; j++) cin>>f[i][j];
	for(int i = 1; i <= r; i++)
		for(int j = 1; j <= c; j++) f[i][j] = max(f[i - 1][j], f[i][j - 1]) + f[i][j];
	return f[r][c];
}

int main()
{
	cin>>t;
	while(t--)
		cin>>r>>c, cout<<find_max(r, c)<<endl;
	return 0;
}