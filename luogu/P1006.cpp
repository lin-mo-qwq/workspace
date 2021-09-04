#include<bits/stdc++.h>
using namespace std;
const int M = 55;
int n, m, ret[M][M], f[2 * M][M][M];
int main()
{
	int i, j, tmp;
	cin>>n>>m;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j++) cin>>ret[i][j];
	for(int k = 2; k <= n + m; k++)
		for(int i1 = 1; i1 <= n; i1++)
			for(int i2 = 1; i2 <= n; i2++)
			{
				int j1 = k - i1, j2 = k - i2;
				if(j1 >= 1 && j1 <= m && j2 <= m && j2 >= 1)
				{
					int &x = f[k][i1][i2], t = ret[i1][j1];
					if(i1 != i2) t += ret[i2][j2]; 
					x = max(x, f[k - 1][i1 - 1][i2 - 1] + t);
					x = max(x, f[k - 1][i1 - 1][i2] + t);
					x = max(x, f[k - 1][i1][i2 - 1] + t);
					x = max(x, f[k - 1][i1][i2] + t);
				}
			}
	
	cout<<f[n + m][n][n];
	return 0;
}
