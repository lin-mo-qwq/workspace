#include<bits/stdc++.h>
using namespace std;

int n,m;
int f[22][1000005];

inline int mlog(int x)
{
	return log(x) / log(2);
}

void build()
{
	for(int i = 1; i <= mlog(n); i++)
		for(int j = 1; j <= n - (1 << i) + 1;j++)
			f[i][j] = max(f[i - 1][j],f[i - 1][j + (1 << (i - 1) )]);
}

void build_min()
{
	for(int i = 1; i <= mlog(n); i++)
		for(int j = 1; j <= n - (1 << i) + 1;j++)
			f[i][j] = min(f[i - 1][j],f[i - 1][j + (1 << (i - 1) )]);
}

int ask(int x, int y)
{
	int p = mlog(y - x + 1);
	return max(f[p][x], f[p][y + 1 - (1 << p)]);
}

int ask_min(int x, int y)
{
	int p = mlog(y - x + 1);
	return min(f[p][x], f[p][y + 1 - (1 << p)]);
}

int main()
{
	scanf("%d%d",&n,&m);

	for(int i = 1; i <= n; i++)
		scanf("%d", &f[0][i]);
	
	build_min();
	for(int i = 1; i <= (n - m + 1); i++)
		printf("%d ", ask_min(i, i + m - 1));
	puts("");
	build();
	for(int i = 1; i <= (n - m + 1); i++)
		printf("%d ", ask(i, i + m - 1));
	puts("");
	return 0;
}