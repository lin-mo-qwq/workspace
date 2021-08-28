#include<bits/stdc++.h>
using namespace std;
const int N = 205;
int k, t, S, E, n;
int g[N][N], res[N][N];

void mul(int c[][N], int a[][N], int b[][N]) {
	static int tmp[N][N];
	memset(tmp, 0x3f, sizeof tmp);
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				tmp[i][j] = min(tmp[i][j], a[i][k] + b[k][j]);
			}
		}
	}
	memcpy(c, tmp, sizeof tmp);
}

void qmi() {
	memset(res, 0x3f, sizeof res);
	for(int i = 1; i <= n; i++) res[i][i] = 0;
	while(k) {
		if(k & 1) mul(res, res, g);
		mul(g, g, g);
		k >>= 1;
	}
}

int main() {	
	map<int, int> ids;
	memset(g, 0x3f, sizeof g);
	scanf("%d%d%d%d", &k, &t, &S, &E);
	for(int i = 1; i <= t; i++) {
		int u, v, w;
		scanf("%d%d%d", &w, &u, &v);
		if(!ids.count(u)) ids[u] = ++n;
		if(!ids.count(v)) ids[v] = ++n;
		u = ids[u], v = ids[v];
		g[u][v] = g[v][u] = min(g[u][v], w);
	}
	
	qmi();

	printf("%d\n", res[ids[S]][ids[E]]);

	return 0;
}