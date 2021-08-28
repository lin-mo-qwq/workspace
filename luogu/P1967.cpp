#include<bits/stdc++.h>
using namespace std;
#define M 10005
#define INF 2147483647

struct edge
{
	int from;
	int to;
	int key;
	friend bool operator < (edge a, edge b)
	{
		return a.key > b.key;
	}
};

struct edge2
{
	int next;
	int to;
	int key;
};

vector <edge> e;
vector <edge2> f;

int dad[M], n, m, cnt, q;
int fa[21][M], head[M], d[M], w[21][M], node[M];

void addedge(int u, int v, int w)
{
	f.push_back((edge2){head[u], v, w});
	head[u] = f.size() - 1;
}

void inp()
{
	int x, y, z;
	cin>>n>>m;
	for(int i = 1; i <= m; i++)
		cin>>x>>y>>z, e.push_back((edge){x, y, z});
}

int anc(int x)
{
	if(x != dad[x]) return dad[x] = anc(dad[x]);
	return x;
}

void uni(int x, int y)
{
	x = anc(x), y = anc(y);
	if(x != y)
		dad[x] = y;
}

bool ask(int x, int y)
{
	return anc(x) == anc(y);
}

void memset()
{
	for(int i = 1; i <= n; i++)
		dad[i] = i;
}

void kruskal()
{
	memset();
	sort(e.begin(), e.end());
	for(int i = 0; i < m; i++)
	{
		if(ask(e[i].from, e[i].to)) continue;
		uni(e[i].from, e[i].to);
		addedge(e[i].from, e[i].to, e[i].key);
		addedge(e[i].to, e[i].from, e[i].key);
		// if(cnt == n - 1)	break;
	}
}

void dfs(int x)
{
	node[x] = 1;
	for(int i = head[x]; i; i = f[i].next)
	{
		int v = f[i].to;
		if(node[v]) continue;
		d[v] = d[x] + 1;
		fa[0][v] = x, w[0][v] = f[i].key;
		dfs(v);	
	}
}

void build()
{
	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= n; j++)
			fa[i][j] = fa[i - 1][fa[i - 1][j]], w[i][j] = min(w[i - 1][j], w[i - 1][fa[i - 1][j]]);
}

int lca(int x, int y)
{
	if(anc(x) != anc(y)) return -1;

	if(d[x] > d[y])
		swap(x, y);

	int ans = INF;

	for(int i = 20; i >= 0; i--)
		if(d[fa[i][y]] >= d[x])
			ans = min(ans, w[i][y]), y=fa[i][y];
	
	if(x == y)
		return ans;
	
	for(int i = 20; i >= 0; i--)
		if(fa[i][y] != fa[i][x])
			ans = min(ans, min(w[i][x], w[i][y])), x = fa[i][x], y = fa[i][y];

	ans=min(ans, min(w[0][x], w[0][y]));

	return ans;
}

int main()
{
	f.push_back((edge2){0, 0, 0});
	inp();
	kruskal();
	for(int i = 1; i <= n; i++)
		if(!node[i])
			d[i] = 1 ,dfs(i), fa[0][i]=i, w[0][i] = INF;
	build();
	cin>>q;
	for(int i = 1, x, y; i <= q; i++)
		cin>>x>>y, cout<<lca(x, y)<<endl;
	return 0;
}