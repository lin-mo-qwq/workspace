#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, dep[N], sum[N], fa[22][N];
vector<pair<int, int>> E[N];

void dfs(int cur, int pre) {
	dep[cur] = dep[pre] + 1;
	fa[0][cur] = pre;
	for(auto nxt : E[cur]) {
		if(nxt.first != pre) {
			sum[nxt.first] = sum[cur] + nxt.second;
			dfs(nxt.first, cur);
		}
	}
}

int bfs(int x) {
	int tmp[N];
	memset(tmp, -1, sizeof tmp);
	tmp[x] = 0;	
	queue <int> q;
	q.push(x);

	while(!q.empty()) {
		int top = q.front();
		q.pop();

		for(auto nxt : E[top]) {
			if(tmp[nxt.first] == -1) {
				tmp[nxt.first] = tmp[top] + nxt.second;
				q.push(nxt.first);
			}
		}
	}

	int mx = 1;
	for(int i = 1; i <= n; i++) {
		if(tmp[mx] < tmp[i]) 
			mx = i;
	} 
	return mx;
}

void init() {
	for(int i = 1; i < 22; i++) {
		for(int j = 1; j <= n; j++) {
			fa[i][j] = fa[i - 1][fa[i - 1][j]];
		}
	}
}

int lca(int x, int y) {
	if(dep[x] > dep[y]) 
		swap(x, y);
	
	int tmp = dep[y] - dep[x];
	for(int i = 0; i < 22; i++) {
		if((1 << i) & tmp) {
			y = fa[i][y];
		}
	}

	if(x == y) 
		return x;

	for(int i = 21; i >= 0; i--) {
		if(fa[i][x] != fa[i][y]) {
			x = fa[i][x];
			y = fa[i][y];
		}
	}

	return fa[0][x];
}

int dis(int u, int v) {
	int Lca = lca(u, v);
	return sum[u] + sum[v] - 2 * sum[Lca];
}

int main() {
	scanf("%d", &n);
	int u, v;
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		E[u].push_back(make_pair((i + 1), v));
		E[(i + 1)].push_back(make_pair(u, v));
	}

	dfs(1, 1);
	init();
	int s = bfs(1), t = bfs(s);
	for(int i = 1; i <= n; i++) {
		printf("%d\n", max(dis(i, s), dis(i, t)));
	}
	return 0;
}