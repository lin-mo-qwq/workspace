#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lson u << 1
#define rson u << 1 | 1
const int N = 500010;
int n, m;
ll a[N];

struct Node {
	int l, r;
	ll sum, d;
} tr[N << 2];

ll gcd(ll a, ll b) {
	return b? gcd(b, a % b): a;
}

void pushup(Node &t, Node &l, Node &r) {
	t.sum = l.sum + r.sum;
	t.d = gcd(l.d, r.d);
}

void pushup(int u) {
	pushup(tr[u], tr[lson], tr[rson]);
}

void build(int u, int l, int r) {
	if(l == r) {
		ll b = a[l] - a[l - 1];
		tr[u] = {l, r, b, b};
		return ;
	}
	tr[u].l = l,  tr[u].r = r;
	int mid = l + r >> 1;
	build(lson, l, mid), build(rson, mid + 1, r);
	pushup(u);
}

void modify(int u, int x, ll v) {
	if(tr[u].l == x && tr[u].r == x) {
		ll b = tr[u].sum + v;
		tr[u] = {x, x, b, b};
		return ; 
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if(x <= mid) modify(lson, x, v);
	else modify(rson, x, v);
	pushup(u);
}

Node query(int u, int l, int r) {
	if(l <= tr[u].l && tr[u].r <= r) {
		return tr[u];
	}
	int mid = (tr[u].l + tr[u].r) / 2;
	if(r <= mid) return query(lson, l, r);
	else if(l > mid) return query(rson, l, r);
	else {
		auto left = query(lson, l, r);
		auto right = query(rson, l, r);
		Node ans;
		pushup(ans, left, right);
		return ans;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	build(1, 1, n);
	
	char op[3];
	int x, y;
	ll d;

	for(int i = 1; i <= m; i++) {
		scanf("%s%d%d", op, &x, &y);
		if(op[0] == 'C') {
			scanf("%lld", &d);
			modify(1, x, d);
			if((y + 1) <= n) modify(1, y + 1, -d);
		} else {
			auto left = query(1, 1, x).sum;
			auto right = 0ll;
			if((x + 1) <= y)  right = query(1, x + 1, y).d;
			printf("%lld\n", abs(gcd(left, right)));
		}
	}
	return 0;
}