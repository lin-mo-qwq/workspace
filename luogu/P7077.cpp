#include<cstdio>
#include<vector>
using namespace std;
const int mod = 998244353, N = 1e5 + 5;
typedef long long ll;
#define lson x << 1
#define rson (x << 1) | 1

struct function {
	int type;
	int p, v;	
} fct[N];

int n, m;
ll sum[N << 2], lazy[N << 2], a[N];
vector<int> E[N];

void build(int x, int l, int r) {
	if(l == r) {
		sum[x] = a[l];
		lazy[x] = 1;
		return ;
	}
	int mid = (l + r) / 2;
	build(lson, l, mid); 
	build(rson, mid + 1, r);
	lazy[x] = 1;
	sum[x] = (sum[lson] + sum[rson]) % mod;
}

void pushdown(int x) {
	if(lazy[x] == 1) return ; 
	sum[lson] = (sum[lson] * (lazy[x] % mod)) % mod;
	sum[rson] = (sum[rson] * (lazy[x] % mod)) % mod;
	lazy[lson] = (lazy[lson] * lazy[x]) % mod;
	lazy[rson] = (lazy[rson] * lazy[x]) % mod;
	lazy[x] = 1;
}

void modifyRange(int x) {
	sum[1] = (sum[1] * (x % mod)) % mod;
	lazy[1] = (lazy[1] * (x % mod)) % mod;
}

void modifySinge(int x, int l, int r, int key, int value) {
	if(l == r) {
		sum[x] = (sum[x] + (value % mod)) % mod;
		return ;
	}
	pushdown(x);	
	int mid = (l + r) / 2;
	if(key <= mid) modifySinge(lson, l, mid, key, value);
	else modifySinge(rson, mid + 1, r, key, value);
}

ll query(int x, int l, int r, int key) {
	if(l == r) {
		return sum[x];
	}
	pushdown(x);
	int mid = (l + r) / 2;
	if(key <= mid) return query(lson, l, mid, key);
	else return query(rson, mid + 1, r, key);
}

void run(int id) {
	if(fct[id].type == 1) {
		modifySinge(1, 1, n, fct[id].p, fct[id].v);
	} else if(fct[id].type == 2) {
		modifyRange(fct[id].v);
	} else {
		for(auto i : E[id]) {
			run(i);
		}
	}		
}

int main() {	
	// freopen("P7077.in", "r", stdin);
	// freopen("P7077.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	
	build(1, 1, n);
	scanf("%d", &m);
	int type, p, v, c, g;
	for(int i = 1; i <= m; i++) {
		scanf("%d", &type);
		if(type == 1) {
			scanf("%d%d", &p, &v);
			fct[i] = {type, p, v};	
		} else if(type == 2) {
			scanf("%d", &v);
			fct[i] = {type, 0, v};
		} else {
			scanf("%d", &c);
			for(int j = 1; j <= c; j++) {
				scanf("%d", &g);
				E[i].push_back(g);
			}
			fct[i] = {type, 0, 0};
		}
	}

	int q, tmp;
	scanf("%d", &q);
	for(int i = 1; i <= q; i++) {
		scanf("%d", &tmp);
		run(tmp);
	}

	for(int i = 1; i <= n; i++) {
		printf("%lld ", query(1, 1, n, i));
	}
	printf("\n");
	return 0;
}