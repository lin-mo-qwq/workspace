#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lson u << 1
#define rson u << 1 | 1

const int N = 1e5 + 5;

int n, m;
ll a[N];
struct Node {
	int l, r;
	ll sum, add;
} tr[N << 2];

void pushdown(Node &t, Node &l, Node &r) {
	if(!t.add) return ;
	l.sum += (l.r - l.l + 1) * t.add;
	r.sum += (r.r - r.l + 1) * t.add;
	l.add += t.add, r.add += t.add;
	t.add = 0;
}

void pushdown(int u) {
	pushdown(tr[u], tr[lson], tr[rson]);
}

void pushup(int u) {
	tr[u].sum = tr[lson].sum + tr[rson].sum;
}

void build(int u, int l, int r) {
	if(l == r) {
		tr[u] = {l, r, a[l], 0};
		return ;
	}
	tr[u] = {l, r};
	int mid = l + r >> 1;
	build(lson, l, mid), build(rson, mid + 1, r);
	pushup(u);
}

void modify(int u, int l, int r, ll d) {
	if(l <= tr[u].l && tr[u].r <= r) {
		tr[u].sum += (tr[u].r - tr[u].l + 1) * d;
		tr[u].add += d;
		return ;
	}
	pushdown(u);
	int mid = (tr[u].l + tr[u].r) >> 1;
	if(l <= mid) modify(lson, l, r, d);
	if(r > mid) modify(rson, l, r, d);
	pushup(u);
}

ll query(int u, int l, int r) {
	if(l <= tr[u].l && tr[u].r <= r) {
		return tr[u].sum;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	ll sum = 0;
	if(l <= mid) sum = query(lson, l, r);
	if(r > mid) sum += query(rson, l, r);
	return sum;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	build(1, 1, n);
	
	char op[2];
	int l, r;
	for(int i = 1; i <= m; i++) {
		scanf("%s%d%d", op, &l, &r);
		if(op[0] == 'C') {
			ll d;
			scanf("%lld", &d);
			modify(1, l, r, d);
		} else {
			printf("%lld\n", query(1, l, r));
		}
	}
	return 0;
}