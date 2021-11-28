#include<bits/stdc++.h>
using namespace std;
const int N = 4e4 + 5, M = 16;
int n, m, root;
int depth[N], fa[N][M];
vector<int> g[N];

void dfs(int cur, int pre) {
	depth[cur] = depth[pre] + 1;
	fa[cur][0] = pre;
	for(int i = 1; i < M; i++) 
		fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
	for(auto i : g[cur]) {
		if(pre == i) continue;
		dfs(i, cur);
	}
}

int lca(int x, int y) {
	if(depth[x] > depth[y]) swap(x, y);
	int tmp = (depth[y] - depth[x]);
	for(int i = 0; i < M; i++) 
		if(tmp & (1 << i)) y = fa[y][i];
	if(x == y) return x;
	for(int i = M - 1; i >= 0; i--) {
		if(fa[x][i] != fa[y][i]) {
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		if(v == -1) root = u;
		else g[u].push_back(v), g[v].push_back(u);
	}
	dfs(root, 0);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		int Lca = lca(u, v);
		if(Lca == u) puts("1");
		else if(Lca == v) puts("2");
		else puts("0");
	}
	return 0;
}