#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define lson x << 1
#define rson (x << 1) | 1
int n, m, q, a[N], ret[N];
int sum[N << 2], lazy[N << 2], pre[N << 2];
struct Opt {
	int typ, l, r;
} opt[N];

void pushdown(int x, int l, int r) {
	if(lazy[x] == -1) {
		return ;
	}
	int mid = (l + r) / 2;
	sum[lson] = lazy[x] * (mid - l + 1);
	sum[rson] = lazy[x] * (r - mid);
	lazy[lson] = lazy[x];
	lazy[rson] = lazy[x];
	lazy[x] = -1;
}

void build(int x, int l, int r) {
	if(l == r) {
		sum[x] = a[l];
		lazy[x] = -1;
		return ;
	}
	int mid = (l + r) / 2;
	build(lson, l, mid);
	build(rson, mid + 1, r);
	sum[x] = sum[lson] + sum[rson];
}

void modify(int x, int l, int r, int L, int R, int value) {
	if(R < L) return ;
	if(L <= l && r <= R) {
		sum[x] = (r - l + 1) * value;
		lazy[x] = value;
		return ;
	}
	pushdown(x, l, r);
	int mid = (l + r) / 2;
	if(L <= mid) modify(lson, l, mid, L, R, value);
	if(R > mid) modify(rson, mid + 1, r, L, R, value);
	sum[x] = sum[lson] + sum[rson];
}

int querySinge(int x, int l, int r, int key) {
	if(l == r) {
		return sum[x];
	}
	pushdown(x, l, r);
	int mid = (l + r) / 2;
	if(key <= mid) {
		return querySinge(lson, l, mid, key);
	} else {
		return querySinge(rson, mid + 1, r, key);
	}
} 

int query(int x, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		return sum[x];
	}
	pushdown(x, l, r);
	int mid = (l + r) / 2, ret = 0;
	if(L <= mid) {
		ret += query(lson, l, mid, L, R);
	} if(R > mid) {
		ret += query(rson, mid + 1, r, L, R);
	}
	return ret;
}

void print(int x) {
	printf("%d: ", x);
	for(int i = 1; i <= n; i++) {
		printf("%d ", querySinge(1, 1, n, i));
	}
	printf("\n");
}

int findAns(int x) {
	for(int i = 1; i <= n; i++) {
		if(ret[i] > x) a[i] = 1;
		else a[i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}
	build(1, 1, n);	
	for(int i = 1; i <= m; i++) {
		int cnt = query(1, 1, n, opt[i].l, opt[i].r);
		if(opt[i].typ) {
			modify(1, 1, n, opt[i].l, opt[i].l + cnt - 1, 1);
			modify(1, 1, n, opt[i].l + cnt, opt[i].r, 0);
			// print(x);
		} else {
			modify(1, 1, n, opt[i].l, opt[i].r - cnt, 0);
			modify(1, 1, n, opt[i].r - cnt + 1, opt[i].r, 1);
			// print(x);
		}
	}

	for(int i = 1; i <= n; i++) {
		querySinge(1, 1, n, i);
	}
	return querySinge(1, 1, n, q);
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &ret[i]);	
	}

	int tmp, l, r, best = -1;
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d", &tmp, &l, &r);
		opt[i] = {tmp, l, r};
	}

	scanf("%d", &q);

	l = 1, r = N;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(findAns(mid) == 0) {
			best = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	printf("%d\n", best);
	return 0;
}