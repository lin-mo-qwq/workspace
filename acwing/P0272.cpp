#include<bits/stdc++.h>
using namespace std;

#define M 3000
int n, a[M], b[M], f[M][M], ans;
int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i];
	for(int i = 1; i <= n; i++) cin>>b[i];
	for(int i = 1; i <= n; i++)
	{
		int max_vel = 1;
		for(int j = 1; j <= n; j++)
		{
			f[i][j] = f[i - 1][j];
			if(a[i] == b[j])	f[i][j] = max(max_vel, f[i][j]);
			if(b[j] < a[i]) max_vel = max(f[i - 1][j] + 1, max_vel);
		}
	}
	for(int i = 1; i <= n; i++) ans = max(ans, f[i][n]);
	cout<<ans<<endl;
	return 0;
}