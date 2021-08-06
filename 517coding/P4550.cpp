#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, s, k;
int f[N][15];
vector<pair<int, int>> E[N];

void update(int &x, int y) {
	if(x > y)
		x = y;
}

void dfs(int cur, int pre) {
	int res = 0;
	for(auto nxt : E[cur]) {
		if(nxt.first == pre) continue;
		dfs(nxt.first, cur);
		for(int m = k; m >= 0; m--) {
			f[cur][m] += f[nxt.first][0] + 2 * nxt.second;
			for(int i = 1; i <= m; i++) {
				update(f[cur][m], f[cur][m - i] + i * nxt.second + f[nxt.first][i]);
			}
		} 
	}
}

int main() {
	scanf("%d%d%d", &n, &s, &k);
	int u, v, w;
	for(int i = 1; i < n; i++) {
		scanf("%d%d%d", &u, &v, &w);
		E[u].push_back(make_pair(v, w));
		E[v].push_back(make_pair(u, w));
	}
	dfs(s, s);
	printf("%d\n", f[s][k]);
	return 0;
}