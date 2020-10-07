#include<bits/stdc++.h>
using namespace std;

int n, m;
int f[21][2000005];

inline int mlog(int x)
{
	return log(x) / log(2);
}

void build()
{
	for(int i = 1;i <= mlog(n); i++)
		for(int j = 1; j <= n - (1 << i) + 1; j++)
			f[i][j] = min(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
}

int ask(int x, int y)
{
	int p=mlog(y - x + 1);
	return min(f[p][x], f[p][y + 1 - (1 << p)]);
}

int main()
{	
	cin>>n>>m;

	for (int i = 1; i <= n; i++)
		cin>>f[0][i];
	
	build();

	for (int i = 1; i <= (n - m + 1); i++)
		cout<<ask(i, (i + m - 1))<<endl;
	return 0;
}