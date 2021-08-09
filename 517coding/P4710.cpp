#include<cstdio>
#include<vector>
using namespace std;
const int N = 2e5 + 10;
#define lson (x << 1)
#define rson (x << 1) | 1
int n, m, t;
int a[N], in[N], out[N], id[N], pre[N], map[N];
vector<int> E[N];
long long sum[N << 2], lazy[N << 2]; 

void dfs(int cur, int fa) {
	in[cur] = ++t;
	id[t] = 1;
	map[t] = cur;
	for(auto i : E[cur]) {
		if(i != fa) {
			dfs(i, cur);
		}
	}
	out[cur] = ++t;
	id[t] = -1;
	map[t] = cur;
}

void build(int x, int l, int r) {
	if(l == r) {
		sum[x] = id[l] * a[map[l]];
		return ;
	}
	int mid = (l + r) / 2;
	build(lson, l, mid);
	build(rson, mid + 1, r);
	sum[x] = sum[lson] + sum[rson];
}

void pushdown(int x, int l, int r) {
	if(!lazy[x]) return ;
	int mid = (l + r) / 2;
	sum[lson] += lazy[x] * (pre[mid] - pre[l - 1]);
	sum[rson] += lazy[x] * (pre[r] - pre[mid]);
	lazy[lson] += lazy[x];
	lazy[rson] += lazy[x];
	lazy[x] = 0;
}

void modify(int x, int l, int r, int L, int R, int value) {
	if(L <= l && r <= R) {
		sum[x] += (long long)(pre[r] - pre[l - 1]) * value;		
		lazy[x] += value;
		return ;
	}
	pushdown(x, l, r);
	int mid = (l + r) / 2;
	if(L <= mid) modify(lson, l, mid, L, R, value);
	if(R > mid) modify(rson, mid + 1, r, L, R, value);
	sum[x] = sum[lson] + sum[rson];
}

void modifySinge(int x, int l, int r, int key, int value) {
	if(l == r) {
		sum[x] += value;
		return ;
	}
	pushdown(x, l, r);
	int mid = (l + r) / 2;
	if(key <= mid) modifySinge(lson, l, mid, key, value);
	else modifySinge(rson, mid + 1, r, key, value);
	sum[x] = sum[lson] + sum[rson];
}

long long query(int x, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		return sum[x];
	}
	pushdown(x, l, r);
	int mid = (l + r) / 2;
	long long ret = 0;
	if(L <= mid) {
		ret += query(lson, l, mid, L, R);
	} if(R > mid) {
		ret += query(rson, mid + 1, r, L, R);
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int u, v;
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs(1, 1);
	for(int i = 1; i <= t; i++) {
		pre[i] = pre[i - 1] + id[i];
	}

	build(1, 1, t);
	int opt, x, value;
	for(int i = 1; i <= m; i++) {
		scanf("%d%d", &opt, &x);
		if(opt == 1) {
			scanf("%d", &value);
			modifySinge(1, 1, t, in[x], value);
			modifySinge(1, 1, t, out[x], -value);
		} else if(opt == 2) {
			scanf("%d", &value);
			modify(1, 1, t, in[x], out[x], value);
		} else {
			printf("%lld\n", query(1, 1, t, 1, in[x]));
		}
	}
	return 0;
}