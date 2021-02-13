#include<bits/stdc++.h>
using namespace std;
const int M = 15;
int n, ret[M][M], f[2 * M][M][M];
int main()
{
	int i, j, tmp;
	cin>>n;
	while(cin>>i>>j>>tmp, i || j || tmp) ret[i][j] = tmp;
	for(int k = 2; k <= 2 * n; k++)
		for(int i1 = 1; i1 <= n; i1++)
			for(int i2 = 1; i2 <= n; i2++)
			{
				int j1 = k - i1, j2 = k - i2;
				if(j1 >= 1 && j1 <= n && j2 <= n && j2 >= 1)
				{
					int &x = f[k][i1][i2], t = ret[i1][j1];
					if(i1 != i2) t += ret[i2][j2]; 
					x = max(x, f[k - 1][i1 - 1][i2 - 1] + t);
					x = max(x, f[k - 1][i1 - 1][i2] + t);
					x = max(x, f[k - 1][i1][i2 - 1] + t);
					x = max(x, f[k - 1][i1][i2] + t);
				}
			}
	
	cout<<f[2 * n][n][n];
	return 0;
}
