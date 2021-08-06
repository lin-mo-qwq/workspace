#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define lson (x << 1)
#define rson (x << 1) | 1
int n, m;
int sum[N << 2];
int in[N], out[N], t;
vector<int> E[N];

void dfs(int cur, int pre) {
	in[cur] = ++t;
	for(auto i : E[cur]) {
		if(i != pre) {
			dfs(i, cur);
		}
	}
	out[cur] = t;
}

void build(int x, int l, int r) {
	if(l == r) {
		sum[x] = 1;
		return ;
	}

	int mid = (l + r) / 2;
	build(lson, l, mid);
	build(rson, mid + 1, r);

	sum[x] = sum[lson] + sum[rson];
}

void modify(int x, int l, int r, int key) {
	if(l == r) {
		if(sum[x]) sum[x] = 0;
		else sum[x] = 1;
		return ;
	}

	int mid = (l + r) / 2;
	if(key <= mid) modify(lson, l, mid, key);
	else modify(rson, mid + 1, r, key);
	
	sum[x] = sum[lson] + sum[rson];
}

int query(int x, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		return sum[x];
	}

	int mid = (l + r) / 2, ret = 0;
	if(L <= mid) ret += query(lson, l, mid, L, R);
	if(R > mid) ret += query(rson, mid + 1, r, L, R);

	return ret;
}

int main() {
	scanf("%d", &n);
	int u, v;
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}

	dfs(1, 1);
	
	build(1, 1, n);

	scanf("%d", &m);
	char opt[2];
	int cur;
	for(int i = 1; i <= m; i++) {
		scanf("%s%d", &opt, &cur);
		if(opt[0] == 'C') {
			modify(1, 1, n, in[cur]);
		} else {
			printf("%d\n", query(1, 1, n, in[cur], out[cur]));
		}
	}
	return 0;
}