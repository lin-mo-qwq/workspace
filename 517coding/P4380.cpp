#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, d;
int p[N], p1, p2;
int ret[N];
int fa[20][N], dep[N];
vector<int> E[N];

int bfs(int x) {
	queue<int> q;
	q.push(x);
	ret[x] = 0;
	int mx = 0;
	while(!q.empty()) {
		int t = q.front();
		q.pop();
		for(auto i : E[t]) {
			if(~ret[i]) continue;
			ret[i] = ret[t] + 1;
			if(ret[mx] < ret[i] && p[i]) {
				mx = i;
			}
			q.push(i);
		}
	}
	return mx;
}

void dfs(int cur, int dad) {
	dep[cur] = dep[dad] + 1;
	fa[0][cur] = dad;
	for(auto i : E[cur]) {
		if(i != dad) {
			dfs(i, cur);
		}
	}
}	

void init() {
	for(int i = 1; i < 20; i++) {
		for(int j = 1; j <= n; j++) {
			fa[i][j] = fa[i - 1][fa[i - 1][j]];
		}
	}
}

int lca(int x, int y) {
	if(dep[x] > dep[y]) {
		swap(x, y);
	}
	int tmp = dep[y] - dep[x];
	for(int i = 0; i < 20; i++) {
		if(tmp & (1 << i)) {
			y = fa[i][y];
		}
	}

	if(x == y) return x;

	for(int i = 19; i >= 0; i--) {
		if(fa[i][x] != fa[i][y]) {
			x = fa[i][x];
			y = fa[i][y];
		}
	}

	return fa[0][x];
}

int main() {
	memset(ret, -1, sizeof ret);
	scanf("%d%d%d", &n, &m, &d);
	int u, v, x;
	for(int i = 1; i <= m; i++) {
		scanf("%d", &x);
		p[x] = 1;
	}
	for(int i = 1; i < n; i++) {
		scanf("%d %d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	p1 = bfs(1);
	memset(ret, -1, sizeof ret);
	p2 = bfs(p1);
	dfs(1, 1);
	init();
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int t1 = (dep[p1] + dep[i] - (2 * dep[lca(p1, i)]));
		int t2 = (dep[p2] + dep[i] - (2 * dep[lca(p2, i)]));
		if(t1 <= d) {
			if(t2 <= d || p2 == 0){
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
