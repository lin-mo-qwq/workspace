#include<bits/stdc++.h>
using namespace std;

int n;
char opt[105];
int p[105], f[105][105];
int g[105][105];
const int INF = 1145148989;


void inp()
{
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		cin>>opt[i], opt[i + n] = opt[i];
		cin>>p[i], p[i + n] = p[i];
	}
}

void memset()
{
	for (int i = 1; i <= n * 2; i++)
		for (int j = 1; j <= n * 2; j++)
			f[i][j] = -INF, g[i][j] = INF;

	for (int i = 1; i <= n * 2; i++)
		f[i][i] = g[i][i] = p[i];
}

void DP()
{
	for (int l = 2; l <= n; l++)
		for (int i = 1, j = l; j <= n * 2; i++, j++)
		{
			for (int k = i; k < j; k++)
			{
				if (opt[k + 1] == 't')
				{
					f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j]);
					g[i][j] = min(g[i][j], g[i][k] + g[k + 1][j]);
				}
				if (opt[k + 1] == 'x')
				{
					f[i][j] = max(f[i][j], max(f[i][k] * f[k + 1][j], max(g[i][k] * g[k + 1][j], max(f[i][k] * g[k + 1][j], g[i][k] * f[k + 1][j]) ) ) );
					g[i][j] = min(g[i][j], min(f[i][k] * f[k + 1][j], min(g[i][k] * g[k + 1][j], min(f[i][k] * g[k + 1][j], g[i][k] * f[k + 1][j]))));
				}
			}
		}

	int ans= -INF;

	for(int i = 1; i <= n ; i++)
		ans = max(f[i][i + n - 1], ans);	
	
	cout<<ans<<endl;

	for(int i = 1; i <= n; i++)	
		if(f[i][i + n -1] == ans)
			cout<<i<<' ';

	puts("");
}

int main()
{
	inp();
	memset();
	DP();
	return 0;
}