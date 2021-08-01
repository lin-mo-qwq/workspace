#include<bits/stdc++.h>
using namespace std; 
const int N = 2 * 1e5 + 5;
int n, c[N], type[N], cnt = 1;
vector<int> E[N], G[N];
int dis[N];
void dfs(int cur, int pre) {
	if(c[cur] != c[pre]) {
		type[cur] = ++cnt;
		G[type[pre]].push_back(type[cur]);
		G[type[cur]].push_back(type[pre]);
	} else {
		type[cur] = type[pre];
	}
	for(auto nxt : E[cur]) {
		if(nxt == pre) continue;
		dfs(nxt, cur);
	}
}

int bfs(int x){
	memset(dis, -1, sizeof dis);
	dis[x] = 0;
	queue<int> q;
	q.push(x);
	int res = x;
	while(!q.empty()) {
		int top = q.front();
		q.pop();
		for(auto nxt : G[top]) {
			if(dis[nxt] == -1) {
				dis[nxt] = dis[top] + 1;
				if(dis[res] < dis[nxt]) res = nxt;
				q.push(nxt);
			}
		}
	}
	return res;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	int u, v;
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	type[1] = 1;
	dfs(1, 1);
	int s = bfs(1), t = bfs(s);
	printf("%d\n", (dis[t] + 1) >> 1);
	return 0;
}