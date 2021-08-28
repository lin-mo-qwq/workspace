#include<bits/stdc++.h>
using namespace std;

#define M 1005
#define mod 1000007
int n, m, a[M], f[M][M];

int main()
{
	cin>>n>>m;
	for(int i = 1; i <= n; i++) cin>>a[i];
	f[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= m; j++)
			for(int k = 0; k <= min(j , a[i]); k++) f[i][j] = (f[i - 1][j - k] + f[i][j]) % mod;
	cout<<f[n][m] % mod<<endl;
	return 0;
}