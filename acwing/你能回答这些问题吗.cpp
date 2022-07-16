#include<bits/stdc++.h>
using namespace std;
#define lson u << 1
#define rson u << 1 | 1
const int N = 5e5 + 5;
struct Node {
	int lmax, rmax, tmax, sum;
	void r(int x) {
		lmax = rmax = tmax = sum = x;
	}
} tr[N << 2];
int a[N];

void pushup(Node &t, Node &l, Node &r) {
	t.lmax = max(l.lmax, l.sum + r.lmax);
	t.rmax = max(r.rmax, r.sum + l.rmax);
	t.tmax = max(max(l.tmax, r.tmax), r.lmax + l.rmax);
	t.sum = l.sum + r.sum;
}

void pushup(int u) {
	pushup(tr[u], tr[lson], tr[rson]);
}

void build(int u, int l, int r) {
	if(l == r) {
		tr[u].r(a[l]);
		return ;
	}
	int mid = l + r >> 1;
	build(lson, l, mid), build(rson, mid + 1, r);
	pushup(u);
}

void modify(int u, int l, int r, int x, int v) {
	if(l == r) {
		tr[u].r(v);
		return ;
	}
	int mid = l + r >> 1;
	if(x <= mid) modify(lson, l, mid, x, v);
	else modify(rson, mid + 1, r, x, v);
	pushup(u);
}

Node query(int u, int l, int r, int a, int b) {
	if(a <= l && r <= b) return tr[u];
	int mid = l + r >> 1;
	if(b <= mid) {
		return query(lson, l, mid, a, b);
	} else if(a > mid) {
		return query(rson, mid + 1, r, a, b);
	} else {
		Node t1 = query(lson, l, mid, a, b);
		Node t2 = query(rson, mid + 1, r, a, b);
		Node ans;
		pushup(ans, t1, t2);
		return ans;
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	build(1, 1, n);
	for(int i = 1; i <= m; i++) { 
		int k, x, y;
		scanf("%d%d%d", &k, &x, &y);
		if(k == 1) {
			if(x > y) swap(x, y);
			printf("%d\n", query(1, 1, n, x, y).tmax);
		} else {
			modify(1, 1, n, x, y);
		}
	}
	return 0;
}