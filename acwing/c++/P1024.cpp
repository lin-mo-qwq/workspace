#include<bits/stdc++.h>
using namespace std;
int V, n, f[20005], v[35];
int main()
{
	cin>>V>>n;
	for(int i = 1; i <= n; i++) cin>>v[i];
	for(int i = 1; i <= n; i++)
		for(int j = V; j >= v[i]; j--) f[j] = max(f[j], f[j - v[i]] + v[i]);
	cout<<V - f[V];
	return 0;
}