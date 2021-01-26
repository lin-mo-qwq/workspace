#include<bits/stdc++.h>
using namespace std;
#define M 20005
int n, m, f[M], g[M], q[M];
int main()
{
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
	{
		int v, w, s;
		cin>>v>>w>>s;
		memcpy(g, f, sizeof f);
		for(int j = 0; j < v; j++)
		{
			int hh = 0, tt = -1;
			for(int k = j; k <= m; k += v)
			{
				if(hh <= tt && q[hh] < k - s * v) hh++;
				if(hh <= tt) f[k] = max(f[k], g[q[hh]] + (k - q[hh]) / v * w);
				while(hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j) / v * w) tt--;
				q[++tt] = k;
			}
		}
	}
	cout<<f[m]<<endl;
	return 0;
}