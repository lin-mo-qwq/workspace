#include<bits/stdc++.h>
const int N = 1e5 + 5;
const long long INF = 1e13;
#define lson x << 1
#define rson (x << 1) | 1
int n, m, t;
int a[N];
long long sum[N << 2], lazy[N << 2];

void pushdown(int x, int l, int r) {
	if(!lazy[x]) return ;
	int mid = (l + r) / 2;
	sum[lson] += lazy[x] * (mid - l + 1);
	sum[rson] += lazy[x] * (r - mid);
	lazy[lson] += lazy[x];
	lazy[rson] += lazy[x];
	lazy[x] = 0;
}

void build(int x, int l, int r) {
	if(l == r) {
		sum[x] = a[l];
		return ;
	}
	int mid = (l + r) / 2;
	build(lson, l, mid);
	build(rson, mid + 1, r);
	sum[x] = sum[lson] + sum[rson];
}

void modify(int x, int l, int r, int L, int R, int value) {
	if(L <= l && r <= R) {
		sum[x] += value * (r - l + 1);
		lazy[x] += value;
		return ;
	}
	pushdown(x, l, r);
	int mid = (l + r) / 2;
	if(L <= mid) modify(lson, l, mid, L, R, value);
	if(R > mid) modify(rson, mid + 1, r, L, R, value);
	sum[x] = sum[lson] + sum[rson];
}	

long long query(int x, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		return sum[x];
	}
	pushdown(x, l, r);
	int mid = (l + r) / 2;
	long long ret = 0;
	if(L <= mid) ret += query(lson, l, mid, L, R);
	if(R > mid) ret += query(rson, mid + 1, r, L, R);
	return ret;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	build(1, 1, n);
	scanf("%d", &m);
	char opt[2];	
	for(int i = 1; i <= m; i++) { 
		scanf("%s", &opt);
		if(opt[0] == 'C') {
			int l, r, value;
			scanf("%d%d%d", &l, &r, &value);
			modify(1, 1, n, l, r, value);
		} else {
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%lld\n", query(1, 1, n, l, r));
		}
	}
	return 0;
}