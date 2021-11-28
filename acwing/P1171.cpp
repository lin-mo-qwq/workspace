#include<bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
int n, m;
int dist[N];
int st[N];
int res[N];
int p[N];
vector<pair<int, int>> query[N];
int e[N], w[N], h[N], ne[N], idx;

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int find(int x) {
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void dfs(int cur, int pre) {
	for(int i = h[cur]; ~i; i = ne[i]) {
		if(e[i] == pre) continue;
		dist[e[i]] = dist[cur] + w[i];
		dfs(e[i], cur);	
	}
}

void tarjan(int cur) {
	st[cur] = 1;
	for(int i = h[cur]; ~i; i = ne[i]) {
		if(!st[e[i]]) {
			tarjan(e[i]);
			p[e[i]] = cur;
		}
	}

	for(auto item : query[cur]) {
		int j = item.first, i = item.second;
		if(st[j] == 2) {
			int lca = find(j);
			res[i] = dist[cur] + dist[j] - 2 * dist[lca];
		}
	}
	st[cur] = 2;
}

int main() {
	scanf("%d%d", &n, &m);
	memset(h, -1, sizeof h);
	for(int i = 1; i < n; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w), add(v, u, w);
	}
	for(int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		if(u != v) {
			query[u].push_back({v, i});
			query[v].push_back({u, i});
		}
	}

	for(int i = 1; i <= n; i++) p[i] = i;

	dfs(1, 1);
	tarjan(1);

	for(int i = 1; i <= m; i++) printf("%d\n", res[i]);
	return 0;
}