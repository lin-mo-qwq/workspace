#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int m, n, a[N], f[20][N];
int Log[N];
void init() {
	Log[0] = -1;
	for(int i = 1; i <= n; i++) {
		Log[i] = Log[i >> 1] + 1;
	}

	for(int i = 0; i < n; i++) {
		f[0][i] = a[i];
	}

	for(int i = 1; i < 20; i++) {
		int lim = n - (1 << i) + 1;
		for(int j = 0; j < lim; j++) {
			f[i][j] = min(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
		}
	}
}

int ask(int x, int y) {
	int len = y - x + 1;
	int k = Log[len];
	return min(f[k][x], f[k][y - (1 << k) + 1]);
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	init();

	for(int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", ask(x, y));
	}
	return 0;
}