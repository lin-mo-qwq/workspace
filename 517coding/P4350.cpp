#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, k;
int vis[N];
int cnt[N], ans[N];
int deep[N], fa[20][N];
vector<pair<int, int>> E[N];

void dfs(int cur, int pre) {
	vis[cur] = 1;
	deep[cur] = deep[pre] + 1;
	fa[0][cur] = pre;
	for(auto i : E[cur]) {
		if(!vis[i.first]) {
			dfs(i.first, cur);
		}
	}
}

void init() {
	for(int i = 1; i <= 20; i++) {
		for(int j = 1; j <= n; j++) {
			fa[i][j] = fa[i - 1][fa[i - 1][j]];
		}
	}
}

int lca(int x, int y) {
	if(deep[x] > deep[y]) {
		swap(x, y);
	}

	int tmp = deep[y] - deep[x];

	for(int i = 1; i <= 20; i++) {
		if(tmp & (1 << i)) {
			y = fa[i][y];
		}
	}

	if(x == y) {
		return x;
	}

	for(int i = 20; i >= 1; i--) {
		if(fa[i][x] != fa[i][y]) {
			x = fa[i][x];
			y = fa[i][y];
		}
	}

	return fa[0][x];
}

void dfs2(int cur) {
	vis[cur] = 1;
	for(auto i : E[cur]) {
		if(!vis[i.first]) {
			dfs2(i.first);
			cnt[cur] += cnt[i.first];
			ans[i.second] = cnt[i.first];
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].push_back(make_pair(v, i));
		E[v].push_back(make_pair(u, i));
	}
	fa[0][1] = 1;
	dfs(1, 1);
	init();
	memset(vis, 0, sizeof vis);
	scanf("%d", &k);
	for(int i = 1; i <= k; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		cnt[a]++, cnt[b]++;
		cnt[lca(a, b)] -= 2;
	}

	dfs2(1);

	for(int i = 1; i < n; i++) {
		printf("%d ", ans[i]);
	}
	puts("");
	return 0;
}