#include<bits/stdc++.h>
using namespace std;
const int N = 255;
int n, b, m;
int Log[N], g[N][N][10];
int a[N][N], f[N][N][10];

void init() {
	Log[0] = -1;
	for(int i = 1; i <= n; i++) {
		Log[i] = Log[i >> 1] + 1;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			g[i][j][0] = f[i][j][0] = a[i][j];
		}
	}

	for(int k = 1; k <= 10; k++) {
		int lim = n - (1 << k) + 1;
		for(int i = 1; i <= lim; i++) {
			for(int j = 1; j <= lim; j++) {
				int t1 = max(f[i][j][k - 1], f[i + (1 << (k - 1))][j][k - 1]);
				int t2 = max(f[i][j + (1 << (k - 1))][k - 1],
							 f[i + (1 << (k - 1))][j + (1 << (k - 1))][k - 1]);
				int t3 = min(g[i][j][k - 1], g[i + (1 << (k - 1))][j][k - 1]);
				int t4 = min(g[i][j + (1 << (k - 1))][k - 1],
							 g[i + (1 << (k - 1))][j + (1 << (k - 1))][k - 1]);
				f[i][j][k] = max(t1, t2);
				g[i][j][k] = min(t3, t4);
			}
		}
	}

}

int ask_max(int x, int y) {
	int k = Log[b];
	int t1 = max(f[x][y][k], f[(x + b) - (1 << k)][y][k]);
	int t2 = max(f[x][(y + b) - (1 << k)][k],
				 f[(x + b) - (1 << k)][(y + b) - (1 << k)][k]);
	return max(t1, t2);
}

int ask_min(int x, int y) {
	int k = Log[b];
	int t1 = min(g[x][y][k], g[(x + b) - (1 << k)][y][k]);
	int t2 = min(g[x][(y + b) - (1 << k)][k],
				 g[(x + b) - (1 << k)][(y + b) - (1 << k)][k]);
	return min(t1, t2);
}

int main() {
	scanf("%d%d%d", &n, &b, &m);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	init();

	int x, y;
	for(int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		printf("%d\n", ask_max(x, y) - ask_min(x, y));
	}
	return 0;
}