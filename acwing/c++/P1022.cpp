#include<bits/stdc++.h>
using namespace std;
int V, m, n, f[505][1005];
int main()
{
	cin>>V>>m>>n;
	for(int i = 1; i <= n; i++)
	{	
		int v, w;
		cin>>v>>w;
		for(int k = V; k >= v; k--) 
			for(int j = m - 1; j >= w; j--)
				f[k][j] = max(f[k][j], f[k - v][j - w] + 1);
	}
	cout<<f[V][m - 1]<<' ';
	int tmp = m - 1;
	while(tmp > 0 && f[V][m - 1] == f[V][tmp - 1]) --tmp;
	cout<<m - tmp<<endl;
	return 0;
}
