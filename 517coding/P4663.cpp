#include<bits/stdc++.h>
const int N = 1e5 + 5;
const long long INF = 1e13;
#define lson x << 1
#define rson (x << 1) | 1
int n, m, t;
int a[N];
long long sum[N << 2], min[N << 2], lazy[N << 2];

void pushdown(int x, int l, int r) {
	if(!lazy[x]) return ;
	int mid = (l + r) / 2;
	sum[lson] += lazy[x] * (mid - l + 1);
	sum[rson] += lazy[x] * (r - mid);
	lazy[lson] += lazy[x];
	lazy[rson] += lazy[x];
	min[lson] += lazy[x];
	min[rson] += lazy[x];
	lazy[x] = 0;
}

void build(int x, int l, int r) {
	if(l == r) {
		min[x] = sum[x] = a[l];
		return ;
	}
	int mid = (l + r) / 2;
	build(lson, l, mid);
	build(rson, mid + 1, r);
	sum[x] = sum[lson] + sum[rson];
	min[x] = std::min(min[lson], min[rson]);
}

void modify(int x, int l, int r, int L, int R, int value) {
	if(L <= l && r <= R) {
		sum[x] += value * (r - l + 1);
		lazy[x] += value;
		min[x] += value;
		return ;
	}
	pushdown(x, l, r);
	int mid = (l + r) / 2;
	if(L <= mid) modify(lson, l, mid, L, R, value);
	if(R > mid) modify(rson, mid + 1, r, L, R, value);
	sum[x] = sum[lson] + sum[rson];
	min[x] = std::min(min[lson], min[rson]);
}	

long long query(int x, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		return min[x];
	}
	pushdown(x, l, r);
	int mid = (l + r) / 2;
	long long ret = INF;
	if(L <= mid) ret = std::min(ret, query(lson, l, mid, L, R));
	if(R > mid) ret = std::min(ret, query(rson, mid + 1, r, L, R));
	return ret;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	build(1, 1, n);
	scanf("%d", &m);
	int l, r, value;	
	for(int i = 1; i <= m; i++) { 
		scanf("%d%d", &l, &r);
		if(getchar() != '\n') {
			scanf("%d", &value);
			l++, r++;
			modify(1, 1, n, l, r, value);
		} else {
			l++, r++;
			printf("%lld\n", query(1, 1, n, l, r));
		}
	}
	return 0;
}