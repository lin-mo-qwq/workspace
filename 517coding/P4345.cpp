#include<bits/stdc++.h>
using namespace std;
const int N = 3 * 1e5 + 5;
int n, q;
int sz[N],
	mx[N],
	centroid[N];
int fa[N];
int head[N], nxt[N << 1], to[N], cnt = -1;

void add(int u, int v) {
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
}

void dfs(int cur, int dad) {
	sz[cur] = 1;
	centroid[cur] = cur;
	int res = 0;
	for(int i = head[cur]; ~i; i = nxt[i]) {
		int v = to[i];
		if(v != dad) {
			dfs(v, cur);
			sz[cur] += sz[v];
			if(sz[res] < sz[v]) {
				res = v;
			}
		}
	}

	if((sz[res] << 1) > sz[cur]) {
		int tmp = centroid[res];
		while(((sz[cur] - sz[tmp]) << 1) > sz[cur]) {
			tmp = fa[tmp];
		}
		centroid[cur] = tmp;
	}
}

int main() {
	memset(head, -1, sizeof head);
	scanf("%d%d", &n, &q);
	int x;
	for(int i = 2; i <= n; i++) {
		scanf("%d", &x);
		add(x, i);
		fa[i] = x;
	}
	dfs(1, 0);
	for(int i = 1; i <= q; i++) {
		scanf("%d", &x);
		printf("%d\n", centroid[x]);
	}
	return 0;
}