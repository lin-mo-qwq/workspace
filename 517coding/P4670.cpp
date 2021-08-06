#include<bits/stdc++.h>
using namespace std;
#define lson (x << 1)
#define rson (x << 1) | 1
const int N = 5 * 1e4 + 5;
const int INF = 0x3f3f3f3f;
int n, m;
int a[N];
int sum[N << 2], lsum[N << 2], rsum[N << 2], maxsum[N << 2];

void update(int x) {
	sum[x] = sum[lson] + sum[rson];
	lsum[x] = max(lsum[lson], sum[lson] + lsum[rson]);
	rsum[x] = max(rsum[rson], sum[rson] + rsum[lson]);
	maxsum[x] = max(maxsum[lson], maxsum[rson]);
	maxsum[x] = max(maxsum[x], rsum[lson] + lsum[rson]);
	// fprintf(stderr, "%d %d %d %d %d\n", x, sum[x], lsum[x], rsum[x], maxsum[x]);
}

void build(int x, int l, int r) {
	if(l == r) {
		lsum[x] = rsum[x] = maxsum[x] = sum[x] = a[l];
		return ;
	}
	int mid = (l + r) / 2;
	build(lson, l, mid);
	build(rson, mid + 1, r);
	update(x);
}

int query(int x, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		return maxsum[x];
	}
	int mid = (l + r) / 2, ret = -INF;
	if(L <= mid) ret = max(ret, query(lson, l, mid, L, R));
	if(R > mid) ret = max(ret, query(rson, mid + 1, r, L, R));
	return ret;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	build(1, 1, n);
	int m, l, r;
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d%d", &l, &r);
		printf("%d\n", query(1, 1, n, l, r));
	}
	return 0;
}