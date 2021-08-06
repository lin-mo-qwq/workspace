#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5; 
int n, x;
int fa[20][N], dep[N], mx[N], mxName[N];
vector<int> E[N];

void dfs(int cur, int dad) {
	dep[cur] = dep[dad] + 1;
	fa[0][cur] = dad;
	mx[cur] = dep[cur];
	int res = cur;
	for(auto i : E[cur]) {
		if(i != dad) {
			dfs(i, cur);
			if(mx[res] < mx[i]) {
				res = i;
			}
			mx[cur] = max(mx[cur], mx[i]);
		}
	}
	mxName[cur] = res;
}

void init() {
	for(int i = 1; i < 20; i++) {
		for(int j = 1; j <= n; j++) {
			fa[i][j] = fa[i - 1][fa[i - 1][j]];
		}
	}
}

int ask(int x, int y) {
	int tmp = dep[x] - dep[y] - 1;
	for(int i = 19; i >= 0; i--) {
		if(tmp & (1 << i)) {
			x = fa[i][x];
		}
	}
	return x;
}

int main() {
	scanf("%d%d", &n, &x);
	int u, v;
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs(1, 1);
	init();
	int a = 1, b = x, cas = 0;
	while(a != b) {
		cas++;
		if(cas % 2) {
			if((dep[b] - dep[a]) > 2) {
				b = fa[0][b];
			} else {
				if(dep[b] - dep[a] == 1) 
					b = mxName[b];
			}
		} else {
			a = ask(b, a);
		}
		// printf("%d %d\n", a, b);
	}

	printf("%d\n", cas);
	return 0;
}