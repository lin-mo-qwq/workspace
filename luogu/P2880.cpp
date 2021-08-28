#include<bits/stdc++.h>
using namespace std;
int n, q;
int f[21][100005], m[21][100005];

inline int Log(int x)
{
	return std::log(x) / std::log(2);
}

void build()
{
	for(int i = 1; i <= Log(n); i++)
		for(int j = 1; j <= n - (1 << i) + 1; j++)
			f[i][j] = max(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]), m[i][j] = min(m[i - 1][j], m[i - 1][j + (1 << (i - 1))]);
}

int ask(int x, int y)
{
	int p = Log(y - x + 1);
	return max(f[p][x], f[p][y + 1 - (1 << p)]) - min(m[p][x], m[p][y + 1 - (1 << p)]);
}

int main()
{
	cin>>n>>q;
	for(int i = 1; i <= n; i++) cin>>f[0][i], m[0][i] = f[0][i];
	build();
	for(int i = 1, a, b; i <= q; i++)
		cin>>a>>b, cout<<ask(a, b)<<endl;
	return 0;
}