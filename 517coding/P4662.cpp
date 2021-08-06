#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
struct tree2 {
	tree2 *lson, *rson;
	int min;
} address[N << 1], *root = &address[0];
int a[N], t = 0;

void build(tree2 *tree, int l, int r) {
	if(l == r) {
		tree->min = a[l];
		return ;
	}

	int mid = (l + r) / 2;
	tree->lson = &address[++t];
	tree->rson = &address[++t];
	
	build(tree->lson, l, mid);
	build(tree->rson, mid + 1, r);

	tree->min = min(tree->lson->min, tree->rson->min);
}

void modify(tree2 *tree, int l, int r, int x, int value) {
	if(l == r) {
		tree->min += value;
		return ;
	}
	int mid = (l + r) / 2;
	if(x <= mid) modify(tree->lson, l, mid, x, value);
	else modify(tree->rson, mid + 1, r, x, value);
	tree->min = min(tree->lson->min, tree->rson->min);
}

int query(tree2 *tree, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		return tree->min;
	} 

	int ret = INF, mid = (l + r) / 2;

	if(L <= mid) {
		ret = min(ret, query(tree->lson, l, mid, L, R));
	} 
	if(mid < R) {
		ret = min(ret, query(tree->rson, mid + 1, r, L, R));
	}

	return ret;
}

int main() {
	int n, m;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	build(root, 1, n);

	scanf("%d", &m);
	int opt; 
	for(int i = 1; i <= m; i++) {
		scanf("%d", &opt);
		if(opt == 1) {
			int x, value;
			scanf("%d%d", &x, &value);
			++x;
			modify(root, 1, n, x, value);
		} else {
			int l, r;
			scanf("%d%d", &l, &r);
			++l, ++r;
			printf("%d\n", query(root, 1, n, l, r));
		}
	}
	return 0;
}