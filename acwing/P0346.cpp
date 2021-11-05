#include<bits/stdc++.h>
using namespace std;
const int N = 6010;
struct Edge {
	int u, v, w;
	bool operator < (const Edge &t) const {
		return w < t.w;
	}
} g[N];
int p[N], size[N];
 
int find(int x) {
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int main() {
	int t; 
	scanf("%d", &t);
	while(t--) {
		int n, res = 0;
		scanf("%d", &n);
		for(int i = 1; i < n; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			g[i] = {u, v, w};	
		} 
		sort(g + 1, g + n);
		for(int i = 1; i <= n; i++) p[i] = i, size[i] = 1;
		for(int i = 1; i < n; i++) {
			int u = find(g[i].u), v = find(g[i].v);
			if(u != v) {
				res += (size[v] * size[u] - 1) * (g[i].w + 1);
				p[u] = v;
				size[v] += size[u];
			}
		}
		printf("%d\n", res);
	}
	return 0;
}