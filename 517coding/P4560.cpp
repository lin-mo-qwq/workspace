#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e4 + 5, M = 505;
int n, m;
int f[N][M];
long long ans = 0;
vector<int> E[N];

int min(int x, int y) {
	if(x < y) return x;
	return y;
}

void dfs(int cur, int pre) {
	f[cur][0] = 1;
	for(auto nxt : E[cur]) { 
		if(nxt == pre) continue;
		dfs(nxt, cur);
		for(int k = m + 1; k >= 1; k--) {
			f[cur][k] += f[nxt][k - 1];
		}
	}
	
	ans += f[cur][m];
	long long res = 0;
	for(auto nxt : E[cur]) { 
		if(nxt == pre) continue;
		for(int k = 1; k < m; k++) {
			res += (f[nxt][k - 1] * 
				   (f[cur][m - k] - f[nxt][m - k - 1]));
		}
	}
	
	ans += res >> 1;
	return ;
}

int main() {
	scanf("%d%d", &n, &m);
	int u, v;
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs(1, 1);
	printf("%d\n", ans);
	return 0;
}