#include<bits/stdc++.h>
using namespace std;
int n, m, f[3005];
int main()
{
	cin>>n>>m;
	// memset(f, 0x3f, sizeof(f));
	f[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		int coin;
		cin>>coin;
		for(int j = coin; j <= m; j++) f[j] += f[j - coin];
	}
	cout<<f[m]<<endl;
	return 0;
}	