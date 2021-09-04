#include<bits/stdc++.h>
using namespace std;
int n, m, f[10005];
int main()
{
	f[0] = 1;
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
	{
		int tmp;
		cin>>tmp;
		for(int j = m; j >= tmp; j--) f[j] = f[j] + f[j - tmp];
	}
	cout<<f[m]<<endl;
	return 0;
}