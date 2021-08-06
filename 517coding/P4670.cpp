#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e4 + 5;
const int INF = 0x3f3f3f3f;
#define lson (x << 1)
#define rson (x << 1) + 1
int n, m;
int a[N];
struct seg {
	long long sum, lsum, rsum, maxsum;
	void update(seg l, seg r) {
		sum = l.sum + r.sum;
		lsum = max(l.lsum, l.sum + r.lsum);
		rsum = max(r.rsum, r.sum + l.rsum);
		maxsum = max(l.maxsum, r.maxsum);
		maxsum = max(maxsum, l.rsum + r.lsum);
	}
} t[N << 2];

void build(int x, int l, int r) {
	if(l == r) {
		t[x].sum = t[x].lsum = t[x].rsum = t[x].maxsum = a[l];
		return ;	
	}
	int mid = (l + r) / 2;
	build(lson, l, mid);
	build(rson, mid + 1, r);
	t[x].update(t[lson], t[rson]);
} 

seg query(int x, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		return t[x];
	}
	
	int mid = (l + r) / 2;
	if(L <= mid && R > mid) {
		seg t1 = query(lson, l, mid, L, R);
		seg t2 = query(rson, mid + 1, r, L, R);
		seg tmp;
		tmp.update(t1, t2);
		return tmp;
	} else {
		if(L <= mid) return query(lson, l, mid, L, R);
		else return query(rson, mid + 1, r, L, R);
	}
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
		printf("%lld\n", query(1, 1, n, l, r).maxsum);
	}
	return 0;
}