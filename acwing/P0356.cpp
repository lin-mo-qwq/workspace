#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 3e5 + 5, INF = 0x3f3f3f3f;
typedef long long ll;
int n, m;
int p[N];
int dep[N], fa[N][20], d1[N][20], d2[N][20];
int h[N], e[M], w[M], ne[M], idx;
struct Edge {
	int a, b, w;
	int used;
	bool operator < (const Edge &t) const {
		return w < t.w;
	}
} edge[M];

int find(int x) {
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

ll kruskal() {
	sort(edge + 1, edge + 1 + m);
	for(int i = 1; i <= n; i++) p[i] = i;
	ll res = 0;
	for(int i = 1; i <= m; i++) {
		int a = find(edge[i].a), b = find(edge[i].b), w = edge[i].w;
		if(a != b) {
			p[a] = b;
			res += w;
			edge[i].used = 1;
		}
	}
	return res;
}

void dfs(int cur) {
	for(int i = h[cur]; ~i; i = ne[i]) {
		int j = e[i];
		if(dep[j] != -1) continue;
		fa[j][0] = cur;
		dep[j] = dep[cur] + 1;
		d1[j][0] = w[i];
		d2[j][0] = -INF;
		for(int k = 1; k < 20; k++) {
			int anc = fa[j][k - 1];
			fa[j][k] = fa[anc][k - 1];
			int dist[4] = {d1[j][k - 1], d2[j][k - 1], d1[anc][k - 1], d2[anc][k - 1]};
			d1[j][k] = d2[j][k] = -INF;
			for(int i = 0; i < 4; i++) {
				int d = dist[i];
				if(d > d1[j][k]) d2[j][k] = d1[j][k], d1[j][k] = d;
				if(d != d1[j][k] && d > d2[j][k]) d2[j][k] = d;
			}
		}
		dfs(j);
	}
}

int lca(int a, int b, int w) {
	if(dep[a] > dep[b]) swap(a, b);
	int tmp = (dep[b] - dep[a]);
	int dist[N * 2];
	int cnt = 0;
	for(int i = 0; i < 20; i++) {
		if(tmp & (1 << i)) {
			dist[++cnt] = d1[b][i];
			dist[++cnt] = d2[b][i];
			b = fa[b][i];
		}
	}

	if(a != b) {
		for(int i = 19; i >= 0; i--) {
			if(fa[a][i] != fa[b][i]) {
				dist[++cnt] = d1[a][i];
				dist[++cnt] = d2[a][i];
				dist[++cnt] = d1[b][i];
				dist[++cnt] = d2[b][i];
				a = fa[a][i];
				b = fa[b][i];
			}
		}
		dist[++cnt] = d1[a][0];
		dist[++cnt] = d1[b][0];
	}

	int d1 = -INF, d2 = -INF;
	for(int i = 1; i <= cnt; i++) {
		int d = dist[i];
		if(d > d1) d2 = d1, d1 = d;
		if(d != d1 && d > d2) d2 = d;
	}
	if(w > d1) return w - d1;
	else return w - d2;
}

void build() {
	memset(h, -1, sizeof h);
	for(int i = 1; i <= m; i++) {
		if(edge[i].used) {
			int a = edge[i].a, b = edge[i].b, w = edge[i].w;
			add(a, b, w);
			add(b, a, w);
		}
	}
	memset(dep, -1, sizeof dep);
	dep[0] = 0, dep[1] = 1;
	dfs(1);
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		edge[i] = {a, b, w};
	}

	ll sum = kruskal();
	build();

	ll res = 1e18;
	for(int i = 1; i <= m; i++) {
		if(!edge[i].used) {
			int a = edge[i].a, b = edge[i].b, w = edge[i].w;
			res = min(res, sum + lca(a, b, w));
		}
	}
	printf("%lld\n", res);
	return 0;
}