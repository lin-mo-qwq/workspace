#include<bits/stdc++.h>
using namespace std;

int n, m;
int f[21][100005];

inline int mlog(int x)
{
	return log(x) / log(2);
}

void build()
{
	for(int i = 1; i <= mlog(m); i++)
		for(int j = 1; j <= m - (1 << i) + 1;j++)
			f[i][j] = min(f[i - 1][j],f[i - 1][j + (1 << (i - 1) )]);
}


int ask(int x, int y)
{
	int p = mlog(y - x + 1);
	return min(f[p][x], f[p][y + 1 - (1 << p)]);
}

int main()
{
	scanf("%d%d", &m, &n);

	for(int i = 1; i <= m; i++)
		scanf("%d", &f[0][i]);
	
	build();
	
	for(int i = 1, x, y; i <= n; i++)
	{
		cin>>x>>y;
		cout<<ask(x, y)<<' ';
	}
	puts("");
	return 0;
}