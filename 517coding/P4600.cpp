#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, ans;
int vis[N];
int dep[N], fa[22][N], dis[N], value[N];
vector<int> E[N];
struct Edge {
	int u, Lca, v;
	friend bool operator < (Edge x, Edge y) {
		return dep[x.Lca] > dep[y.Lca];
	}
} line[N];

void initLca(int cur, int pre) {
	dep[cur] = dep[pre] + 1;
	fa[0][cur] = pre;

	for(int i = 1; i < 22; i++) {
		fa[i][cur] = fa[i - 1][fa[i - 1][cur]];
	}

	for(auto i : E[cur]) {
		if(i != pre) {
			initLca(i, cur);
		}
	}
}

int lca(int x, int y) {
	if(dep[x] > dep[y]) {
		swap(x, y);
	}

	int tmp = dep[y] - dep[x];
	for(int i = 0; i < 22; i++) {
		if((1 << i) & tmp) {
			y = fa[i][y];
		}
	}

	if(x == y) return x;

	for(int i = 21; i >= 0; i--) {
		if(fa[i][x] != fa[i][y]) {
			x = fa[i][x];
			y = fa[i][y];
		}
	}

	return fa[0][x];
}

bool check(int u, int v, int Lca) {
	if(vis[u] || vis[v]) {
		return false;
	}
	return true;
}

void dfs(int cur, int pre) {
	vis[cur] = 1;
	printf("%d ", cur);
	for(auto i : E[cur]) {
		if(i != pre && !vis[i]) {
			dfs(i, cur);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	int u, v;
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}

	initLca(1, 1);

	for(int i = 1; i <= m; i++) {
		scanf("%d%d", &u, &v);
		line[i] = {u, lca(u, v), v};
	}

	sort(line + 1, line + m + 1);

	for(int i = 1; i <= m; i++) {
		printf("%d\n", line[i].Lca);
		if(check(line[i].u, line[i].v, line[i].Lca)) {
			dfs(line[i].Lca, fa[0][line[i].Lca]);
			ans++;
		} 
	}

	printf("%d\n", ans);
	return 0;
}