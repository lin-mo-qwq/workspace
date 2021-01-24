#include<bits/stdc++.h>
using namespace std;
int n, W, w[35], f[20005];
int main()
{
	cin>>W>>n;
	for(int i = 1; i <= n; i++) cin>>w[i];
	for(int i = 1; i <= n; i++)
		for(int j = W; j >= w[i]; j--)
			f[j] = max(f[j], f[j - w[i]] + w[i]);
	cout<<W - f[W]<<endl;
	return 0;
}