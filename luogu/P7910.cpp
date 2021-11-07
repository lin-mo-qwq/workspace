#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int idx;
struct Node {
	int value, id;
	int nxt;
} lst[N];

int n, q, a[N];

void del(int now, int id) {
	if(lst[lst[now].nxt].id == id) {
		lst[now].nxt = lst[lst[now].nxt].nxt;
	} else {
		del(lst[now].nxt, id);
	}
}

void add(int now, int value, int id) {
	if(lst[now].nxt == 0 || lst[lst[now].nxt].value > value ||
		((lst[lst[now].nxt].value ==  value) && id < lst[lst[now].nxt].id)) {
		lst[++idx].nxt = lst[now].nxt;
		lst[now].nxt = idx;
		lst[idx].value = value;
		lst[idx].id = id;
	} else {
		add(lst[now].nxt, value, id);
	}
}

void find(int now, int cnt) {
	if(lst[now].nxt != 0) {
		if(now != 0) a[lst[now].id] = cnt;
		find(lst[now].nxt, ++cnt);
	} else {
		a[lst[now].id] = cnt;
		return ;
	}
}

int main() {
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		add(0, x, i);
	}
	find(0, 0);
	for(int i = 1; i <= q; i++) {
		int opt, x, v;
		scanf("%d%d", &opt, &x);
		if(opt == 1) {
			scanf("%d", &v);
			del(0, x);
			add(0, v, x);
			find(0, 0);
		} else {
			printf("%d\n", a[x]);
		}
	}
	return 0;
}