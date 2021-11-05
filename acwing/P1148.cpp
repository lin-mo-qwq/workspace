#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000, M = 1e4 + 10;
int n, m;
vector<pair<int, int>> g[N];
int p[N], dist1[N][N], dist2[N][N], f[N];
struct edge {
	int u, v, w;
	bool operator < (const edge &t) const {
		return w < t.w;
	}
} e[M];

int find(int x) {
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

void add(int u, int v, int w) {
	g[u].push_back({v, w});
	g[v].push_back({u, w});
}

void dfs(int u, int fa, int md1, int md2, int d1[], int d2[]) {
	d1[u] = md1, d2[u] = md2;
	for(auto i : g[u]) {
		if(i.first != fa) {
			if(i.second > md1) md2 = md1, md1 = i.second;
			else if(i.second < md1 && i.second > md2) md2 = i.second;
			dfs(i.first, u, md1, md2, d1, d2);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[i] = {u, v, w};
	}
	sort(e + 1, e + 1 + m);
	
	for(int i = 1; i <= n; i++) p[i] = i;
	ll sum = 0;
	for(int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int pu = find(e[i].u), pv = find(e[i].v);
		if(pu != pv) {
			p[pu] = pv;
			add(u, v, w);
			sum += w;
			f[i] = 1;
		}
	}

	for(int i = 1; i <= n; i++)
		dfs(i, -1, -1e9, -1e9, dist1[i], dist2[i]);
	ll res = 1e18;
	for(int i = 1; i <= m; i++) {
		if(!f[i]) {
			int u = e[i].u, v = e[i].v, w = e[i].w;
			if(w > dist1[u][v]) {
				res = min(res, sum - dist1[u][v] + w);
			} else if(w > dist2[u][v]) {
				res = min(res, sum - dist2[u][v] + w);
			}
		}
	}
	printf("%lld\n", res);
}