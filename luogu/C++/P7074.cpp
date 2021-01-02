#include<bits/stdc++.h>
using namespace std;
#define M 1005
long long n, m, ret[M][M], f[M][M];
int main()
{
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) cin>>ret[i][j];
	memset(f, -0x3f, sizeof(f));
	f[1][0] = 0;
	for(int j = 1; j <= m; j++)
	{
		long long s = -1e18;
		for(int i = 1; i <= n; i++)
			s = max(s, f[i][j - 1]) + ret[i][j], f[i][j] = s;
		s = -1e18;
		for(int i = n; i >= 1; i--)
			s = max(s, f[i][j - 1]) + ret[i][j], f[i][j] = max(s, f[i][j]);
	}
	cout<<f[n][m]<<endl;
	return 0;
}