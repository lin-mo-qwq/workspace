#include<bits/stdc++.h>
using namespace std;

long long f[1005], n, W, win[1005], w[1005], lose[1005];

int main()
{
	cin>>n>>W;
	for(int i = 1; i <= n; i++) cin>>lose[i]>>win[i]>>w[i];
	for(int i = 1; i <= n; i++)
	{
		for(int j = W; j >= w[i]; j--) 
			f[j] = max(f[j] + lose[i], f[j - w[i]] + win[i]);
		for(int j = w[i] - 1; j >= 0; j--) f[j] += lose[i];
	}
	cout<<f[W] * 5<<endl;	
	return 0;
}