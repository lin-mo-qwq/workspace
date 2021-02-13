#include<bits/stdc++.h>
using namespace std;
#define M 210
int m, n, k, f[M][M];
int main()
{
	cin>>m>>n>>k;
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for(int i = 1; i <= k; i++)
	{
		int a, b, c;
		cin>>a>>b>>c;
		for(int j = m; j >= 0; j--)
			for(int g = n; g >= 0; g--)
				f[j][g] = max(f[j][g], f[max(0, j - a)][max(0, g - b)] + c);	
	}
	cout<<f[m][n]<<endl;
	return 0;
}