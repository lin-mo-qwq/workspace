#include<bits/stdc++.h>
using namespace std;
const int M = 1e7 + 5;
long n, W, w[M], v[M], f[M], ans;
int main()
{
	cin>>W>>n;
	for(int i = 1; i <= n; i++) cin>>w[i]>>v[i];
	for(int i = 1; i <= n; i++)
		for(int j = w[i]; j <= W; j++) 
			f[j] = max(f[j - w[i]] + v[i], f[j]), ans = max(ans, f[j]);
	cout<<ans;
	return 0;
}
