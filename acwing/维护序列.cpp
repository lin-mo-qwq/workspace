#include<bits/stdc++.h>
#define lson u << 1
#define rson u << 1 | 1
using namespace std;
const int N = 1e5 + 10;

struct Node {
	int l, r; 
	int sum, add, mul;
} tr[N << 2];
int a[N];
int n, p, m;

void pushup(int u) {
	tr[u].sum = (1ll * tr[lson].sum + tr[rson].sum) % p;
}

void build(int u, int l, int r) {
	if(l == r) {
		tr[u] = {l, r, a[l] % p, 0, 1};
		return ;
	}
	tr[u] = {l, r, 0, 0, 1};
	int mid = l + r >> 1;
	build(lson, l, mid), build(rson, mid + 1, r);
	pushup(u);	
}

void pushdown(Node &t, Node &l, Node &r) {
	l.sum = (1ll * l.sum * t.mul + 1ll * (l.r - l.l + 1) * t.add) % p;
	r.sum = (1ll * r.sum * t.mul + 1ll * (r.r - r.l + 1) * t.add) % p;
	l.mul = (1ll * l.mul * t.mul) % p;
	l.add = (1ll * l.add * t.mul + t.add) % p;
	r.mul = (1ll * r.mul * t.mul) % p;
	r.add = (1ll * r.add * t.mul + t.add) % p;
}

void pushdown(int u) {
	pushdown(tr[u], tr[lson], tr[rson]);
	tr[u].mul = 1, tr[u].add = 0;
}

void modify(int u, int l, int r, int k, int d) {
	if(l <= tr[u].l && tr[u].r <= r) {
		tr[u].sum = (1ll * tr[u].sum * k + 
			1ll * (tr[u].r - tr[u].l + 1) * d) % p;
		tr[u].mul = (1ll * tr[u].mul * k) % p;
		tr[u].add = (1ll * tr[u].add * k + d) % p;
		return ;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if(l <= mid) modify(lson, l, r, k, d);
	if(r > mid) modify(rson, l, r, k, d);
	pushup(u);
}

int query(int u, int l, int r) {
	if(l <= tr[u].l && tr[u].r <= r) {
		return tr[u].sum % p;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	long long sum = 0;
	if(l <= mid) sum = query(lson, l, r) % p;
	if(r > mid) sum += query(rson, l, r) % p;
	return sum % p;
}

int main() {
	scanf("%d%d", &n, &p);
	for(int i = 1; i <= n; i++) 
		scanf("%d", &a[i]);
	build(1, 1, n);
	
	scanf("%d", &m);
	int k, l, r, d;
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d", &k, &l, &r);
		if(k == 1) {
			scanf("%d", &d);
			modify(1, l, r, d, 0);
		}
		else if(k == 2) {
			scanf("%d", &d);
			modify(1, l, r, 1, d);
 		} else {
			printf("%d\n", query(1, l, r));
		}
	}
	return 0;
}