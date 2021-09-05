#include<bits/stdc++.h>
using namespace std;

#define M 500005
vector<int> V[M];
int n, k, deep[M], poi[M], fa[21][M], ans;

void inp()
{
	cin >> n >> k;
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		V[x].push_back(y);
		V[y].push_back(x);
	}
}

void dfs(int x)
{
	for(int i = 0; i < V[x].size(); i++)
	{
		int v = V[x][i];
		if(v == fa[0][x]) continue;
		fa[0][v] = x, deep[v] = deep[x] + 1;
		dfs(v);
	}
}

void build()
{
	for(int i = 1; i <= 18; i++)
		for(int j = 1; j <= n; j++)
			fa[i][j] = fa[i - 1][fa[i - 1][j]];
}

int lca(int x, int y)
{
	if(deep[x]>deep[y])
		swap(x,y);
	
	int temp=deep[y]-deep[x];

	
	for(int i=20;i>=0;i--)
		if(temp>=(1 << i))
			y=fa[i][y],temp-=(1<<i);
	
	if(x==y)
		return x;

	for(int i=20;i>=0;i--)
		if(fa[i][y]!=fa[i][x])
			x=fa[i][x], y=fa[i][y];

	return fa[0][y];
}

void dfs2(int x)
{
	for(int i = 0; i < V[x].size(); i++)
	{
		int v = V[x][i];
		if(v == fa[0][x]) continue;
		dfs2(v);
		poi[x] += poi[v];
	}
	ans = max(ans, poi[x]);
}

int main()
{
	inp();
	dfs(1);
	build();

	for(int i = 1; i <= k; i++)
	{
		int x, y;
		cin >> x >> y;
		int Lca=lca(x, y);
		poi[x]++, poi[y]++, poi[Lca]--, poi[fa[0][Lca]]--;
	}
	dfs2(1);
	cout << ans << endl;
	return 0;
}