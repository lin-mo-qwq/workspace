#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = -1e9;
int f[20][N], a[N], cont[N];
int Log[N], b[N], belong[N];
void init(int n, int ret[]) {
	Log[0] = -1;
	for(int i = 1; i <= n; i++) {
		Log[i] = Log[i >> 1] + 1;
	}

	for(int i = 1; i <= n; i++){
		f[0][i] = ret[i];
	}

	for(int i = 1; i <= 20; i++) {
		int lim = n - (1 << i) + 1;
		for(int j = 1; j <= lim; j++) {
			f[i][j] = max(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
		}
	}
}

int ask_st(int x, int y){
	int len = y - x + 1;
	int k = Log[len];
	if(len <= 0) {
		return INF;
	}
	return max(f[k][x], f[k][y - (1 << k) + 1]);
}

int ask(int x, int y){
	int mid = ask_st(belong[x] + 1, belong[y] - 1);
	int l, r, len = y - x + 1;
	l = b[belong[x]] - cont[x] + 1;
	r = cont[y];
	if(l >= len) l = len;
	if(r >= len) r = len;
	return max(max(l, mid), r);
}

int main() {
	int cnt = 0, n, q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] != a[i - 1])
			++cnt;
		cont[i] = ++b[cnt];
		belong[i] = cnt;
	}
	init(cnt, b);
	for(int i = 0; i < q; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", ask(x, y));
	}
	return 0;
}

