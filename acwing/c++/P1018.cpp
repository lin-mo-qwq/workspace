#include<bits/stdc++.h>
using namespace std;
int n, f[105][105], f[105][105];

int find_min()
{
	f[1][1] = f[1][1];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i != j || i != 1)
				f[i][j] = min(f[i][j - 1], f[i - 1][j]) + f[i][j];
	return f[n][n];
} 

int main()
{
	cin>>n;
	// cout<<f[0][0]<<endl;
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) cin>>f[i][j];
	cout<<find_min()<<endl;
	return 0;
}