#include<bits/stdc++.h>
using namespace std;
int n, ret[205], sum[205], f[205][205];

int find_min()
{
	for(int l = 2; l <= n; l++)
		for(int i = 1, j = l; j <= 2 * n; i++, j++)
		{
			f[i][j] = f[i][i] + f[i + 1][j] + sum[j] - sum[i - 1];
			for(int k = i + 1; k < j; k++)
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + sum[j] - sum[i - 1]);	
		}
	int ans = f[1][n];
	for(int i = 2; i <= n; i++)
		ans = min(ans, f[i][i + n - 1]);
	return ans;
}

int find_max()
{
	memset(f, 0, sizeof(f));
	for(int l = 2; l <= n; l++)
		for(int i = 1, j = l; j <= 2 * n; i++, j++)
		{
			f[i][j] = f[i][i] + f[i + 1][j] + sum[j] - sum[i - 1];
			for(int k = i + 1; k < j; k++)
				f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + sum[j] - sum[i - 1]);	
		}
	int ans = f[1][n];
	for(int i = 2; i <= n; i++)
		ans = max(ans, f[i][i + n - 1]);
	return ans;
}

int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++)	cin>>ret[i];	
 	for(int i = 1; i <= n; i++) ret[i + n] = ret[i];
	for(int i = 1; i <= n * 2; i++) sum[i] = sum[i - 1] + ret[i];
	cout<<find_min()<<endl<<find_max()<<endl;
	return 0;
}