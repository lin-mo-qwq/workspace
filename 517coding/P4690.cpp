#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, t;
struct tree2 {
	int sum;
	tree2 *lson, *rson;
} address[N << 4], *root = &address[0];
queue <int> q;

void modify(tree2 *x, int l, int r, int key, int value) {
	if(l == r) {
		x->sum = value;
		return ;
	}

	int mid = (l + r) / 2;
	if(key <= mid) {
		if(x->lson == nullptr) x->lson = &address[++t];
		modify(x->lson, l, mid, key, value);
	} else {
		if(x->rson == nullptr) x->rson = &address[++t];
		modify(x->rson, mid + 1, r, key, value);
	} 

	int tmp = 0;
	if(x->lson != nullptr) tmp += x->lson->sum;
	if(x->rson != nullptr) tmp += x->rson->sum;
	x->sum = tmp;
}

int query(tree2 *x, int l, int r, int k) {
	if(l == r) {
		return l;
	}

	int mid = (l + r) / 2;
	if(x->lson != nullptr && x->lson->sum >= k) {
		return query(x->lson, l, mid, k);
	} else {
		if(x->rson == nullptr) x->rson = &address[++t];
		if(x->lson != nullptr) k -= x->lson->sum;
		return query(x->rson, mid + 1, r, k);
	}
}

int main() {
	scanf("%d", &n);
	char opt[10];
	int x;
	for(int i = 1; i <= n; i++) {
		scanf("%s", opt);
		if(opt[0] == 'i') {
			scanf("%d", &x);
			q.push(x);
			modify(root, 1, 1e9, x, 1);
		} else if(opt[0] == 'o') {
			modify(root, 1, 1e9, q.front(), 0);
			q.pop();
		} else {
			printf("%d\n", query(root, 1, 1e9, (int)(q.size() >> 1) + 1));
		}
	}
	return 0;
}