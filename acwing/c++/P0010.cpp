#include<bits/stdc++.h>
using namespace std;
const int M = 1005, mod = 1e9 + 7;
int n, m, f[M], g[M];
int main()
{
	cin>>n>>m;
	
	memset(f, -0x3f, sizeof f);
	f[0] = 0, g[0] = 1;

	for(int i = 1; i <= n; i++)
	{
		int v, w;
		cin>>v>>w;
		for(int j = m; j >= v; j--)
		{
			int cnt = 0;
			int maxv = max(f[j], f[j - v] + w);
			if(maxv == f[j]) cnt += g[j];
			if(maxv == f[j - v] + w) cnt += g[j - v];
			g[j] = cnt % mod, f[j] = maxv;
		}
	}	

	int res = 0, cnt = 0;
	for(int i = 0; i <= m; i++) res = max(res, f[i]);
	
	for(int i = 0; i <= m; i++)
		if(f[i] == res) cnt = cnt + g[i] % mod;
	
	cout<<cnt<<endl;
	return 0;
}		