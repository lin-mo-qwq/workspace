#include<bits/stdc++.h>
using namespace std;
const int N = 105, INF = 0x3f3f3f3f;
int n, m;
int path[N], cnt;
int d[N][N], g[N][N], pos[N][N];

void getPath(int i, int j) {
	if(pos[i][j] == 0) return ;
	int k = pos[i][j];
	getPath(i, k);
	path[++cnt] = k;
	getPath(k, j);
}

int main() {
	scanf("%d%d", &n, &m);

	memset(g, 0x3f, sizeof g);
	for(int i = 1; i <= n; i++) g[i][i] = 0;

	for(int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u][v] = g[v][u] = min(g[u][v], w);
	}

	int res = INF;
	memcpy(d, g, sizeof g);

	for(int k = 1; k <= n; k++) {
		for(int i = 1; i < k; i++)
			for(int j = i + 1; j < k; j++)
				if(d[i][j] * 1ll + g[i][k] + g[k][j] < res) {
					res = d[i][j] + g[i][k] + g[k][j];
					cnt = 0;
					path[++cnt] = k;
					path[++cnt] = i;
					getPath(i, j);
					path[++cnt] = j;
				}


		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					pos[i][j] = k;
				}
	}

	if(res == INF) puts("No solution.");
	else for(int i = 1; i <= cnt; i++) printf("%d ", path[i]);
	return 0;
}