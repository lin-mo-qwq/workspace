#include<bits/stdc++.h>
using namespace std;
int n, ret[1005], f[1005], ans;
int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>ret[i], f[i] = ret[i];

	for(int i = 1; i <= n; i++)
		for(int j = 1; j < i; j++)
			if(ret[i] > ret[j])	f[i] = max(f[i], f[j] + ret[i]);
	
	for(int i = 1; i <= n; i++) ans = max(ans, f[i]);

	cout<<ans<<endl;
	return 0;
}