#include<bits/stdc++.h>
using namespace std;
const int N = 6 * 1e3 + 5;
int n, w[N], f[N][2];
vector<int> E[N];

void dfs(int cur, int pre) {
	f[cur][1] = w[cur];
	for(auto i : E[cur]) {
		if(i != pre) {
			dfs(i, cur);
			f[cur][0] += max(f[i][1], f[i][0]);
			f[cur][1] += f[i][0];
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	int u, v;
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}

	dfs(1, 1);
	printf("%d\n", max(f[1][1], f[1][0]));
	return 0;
}
