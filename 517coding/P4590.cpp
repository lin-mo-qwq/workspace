#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e6;
int q, s, t;
int fa[22][N], dep[N];

void initLca(int cur) {
	for(int i = 1; i < 22; i++) {
		fa[i][cur] = fa[i - 1][fa[i - 1][cur]];
	}
}

void addNode(int cur, int pre) {
	dep[cur] = dep[pre] + 1;
	fa[0][cur] = pre;
	initLca(cur);
}

int lca(int x, int y) {
	if(dep[x] > dep[y]) {
		swap(x, y);
	}

	int tmp = dep[y] - dep[x];

	for(int i = 0; i < 22; i++) {
		if((1 << i) & tmp) {
			y = fa[i][y];
		}
	}

	if(x == y) return x;

	for(int i = 21; i >= 0; i--) {
		if(fa[i][x] != fa[i][y]) {
			x = fa[i][x];
			y = fa[i][y];
		}
	}

	return fa[0][x];
}

int dis(int x, int y) {
	int Lca = lca(x, y);
	return dep[x] + dep[y] - 2 * dep[Lca];
}

void init() {
	dep[1] = 1;
	for(int i = 2; i <= 4; i++) {
		addNode(i, 1);
	}
	s = 2, t = 3;
}

void update(int cur) {
	int tmp = max(dis(cur, s), dis(cur, t));
	if(tmp > dis(s, t)) {
		if(tmp == dis(cur, s)) t = cur;
		else s = cur;
	}
}

int main() {
	scanf("%d", &q);
	init();
	int pre, n = 4;
	for(int i = 1; i <= q; i++) {
		scanf("%d", &pre);
		addNode(n + 1, pre);
		update(n + 1);
		addNode(n + 2, pre);
		update(n + 2);
		n += 2;
		printf("%d\n", dis(s, t));
	}
	return 0;
}