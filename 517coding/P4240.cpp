#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
struct seg {
	int l, r;
	friend bool operator < (seg a, seg b) {
		return a.l < b.l;
	}
} a[N], q[N];
int n, m, cnt, R[N], f[25][N], t[N];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i].l ,&a[i].r);
		t[++cnt] = a[i].l;
		t[++cnt] = a[i].r;
	}
	for(int i = 1; i <= m; i++) {
		scanf("%d%d", &q[i].l, &q[i].r);
		t[++cnt] = q[i].l;
		t[++cnt] = q[i].r;
	}

	sort(t + 1, t + 1 + cnt);

	int len = unique(t + 1, t + 1 + cnt) - t - 1;

	for(int i = 1; i <= n; i++) {
		a[i].l = lower_bound(t + 1, t + 1 + len, a[i].l) - t;
		a[i].r = lower_bound(t + 1, t + 1 + len, a[i].r) - t;
	}

	for(int i = 1; i <= m; i++) {
		q[i].l = lower_bound(t + 1, t + 1 + len, q[i].l) - t;
		q[i].r = lower_bound(t + 1, t + 1 + len, q[i].r) - t;
	}

	memset(R, 0x3f, sizeof(R));

	for(int i = 1; i <= n; i++) {
		R[a[i].l] = min(R[a[i].l], a[i].r);
	}

	for(int i = N - 2; i >= 0; i--) {
		R[i] = min(R[i + 1], R[i]);
		f[0][i] = R[i];
	}

	for(int i = 1; i <= 20; i++) {
		for(int j = 1; j <= N; j++) {
			if(f[i - 1][j] != INF)
				f[i][j] = f[i - 1][f[i - 1][j]];
			else f[i][j] = INF;
		}
	}

	for(int i = 1; i <= m; i++) {
		int ret = 0;
		for(int j = 20; j >= 0; j--) {
			if(f[j][q[i].l] <= q[i].r) {
				q[i].l = f[j][q[i].l];
				ret += 1 << j;
			}
		}
		printf("%d\n", ret);
	}

	return 0;
}