#include<bits/stdc++.h>
using namespace std;
const int N = 105, M = 205;
int n, k;
int w[N], f[N][M][2];
vector<int> E[N];

void update(int &x, int y) {
	if(x < y) x = y;
}

void dfs(int cur, int pre) {
	for(auto nxt : E[cur]) {
		if(nxt == pre) continue;
		dfs(nxt, cur);
		for(int m = k; m >= 1; m--) {
			for(int i = 1; i <= m; i++) {
				update(f[cur][m][0], f[cur][m - i][1] + f[nxt][i - 1][0]);
				update(f[cur][m][0], f[cur][m - i][0] + f[nxt][i - 2][1]);
				update(f[cur][m][1], f[cur][m - i][1] + f[nxt][i - 2][1]);
			}
		}	
	}
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		for(int j = 0; j <= k; j++) {
			f[i][j][0] = f[i][j][1] = w[i];
		}
	}
	int u, v;
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs(1, 1);
	printf("%d\n", max(f[1][k][0], f[1][k][1]));
	return 0;
}