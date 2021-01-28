#include<bits/stdc++.h>
using namespace std;
int n, V1, V2, f[205][205];
int main()
{
	cin>>n>>V1>>V2;
	for(int i = 1; i <= n; i++)
	{
		int v1, v2;
		cin>>v1>>v2;
		for(int j = V1; j >= v1; j--)
			for(int k = V2; k >= v2; k--)	f[j][k] = max(f[j][k], f[j - v1][k - v2] + 1);
	}
	cout<<f[V1][V2]<<endl;
	return 0;
}