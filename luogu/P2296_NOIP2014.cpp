#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
int n, m, s, t;
int vis[N], dis[N], vis1[N];
vector<int> g1[N], g2[N];

void dfs(int x) {
	vis[x] = true;
	for(auto i : g2[x]) {
		if(!vis[i])
			dfs(i);
	}
}

void bfs(int x) {
	memset(dis, -1, sizeof dis);
	queue<int> q;
	q.push(x); dis[x] = 0;
	while(!q.empty()) {
		int f = q.front();
		q.pop();
		for(auto i : g1[f]) {
			if(dis[i] == -1 && vis1[i]) {
				dis[i] = dis[f] + 1;
				q.push(i);
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g1[u].push_back(v);
		g2[v].push_back(u);
	}
	scanf("%d%d", &s, &t);
	dfs(t);
	for(int i = 1; i <= n; i++) {
		vis1[i] = vis[i];
		for(auto j : g1[i]) {
			vis1[i] &= vis[j];
		}
	}
	bfs(s);
	printf("%d\n", dis[t]);
	return 0;
}