#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m1, m2;
bool st[N];
int dist[N], cnt[N];
vector<pair<int, int>> g[N];

bool spfa() {
	queue<int> q;
	memset(st, 0, sizeof st);
	memset(cnt, 0, sizeof cnt);
	memset(dist, 0, sizeof dist);
	for(int i = 1; i <= n; i++) {
		q.push(i), st[i] = true;
	}

	while(!q.empty()) {
		int t = q.front(); q.pop();
		st[t] = false;
		for(auto i : g[t]) {
			if(dist[i.first] > dist[t] + i.second) {
				dist[i.first] = dist[t] + i.second;
				cnt[i.first] = cnt[t] + 1;
				if(cnt[i.first] >= n) return true;
				if(!st[i.first]) q.push(i.first);
			}
		}
	}
	return false;
}

int main() {
	int f;
	scanf("%d", &f);
	while(f--) {
		scanf("%d%d%d", &n, &m1, &m2);
		for(int i = 1; i <= n; i++) g[i].clear();
		for(int i = 1; i <= m1; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}
		for(int i = 1; i <= m2; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			g[u].push_back({v, -w});
		}
		if(spfa()) printf("YES\n");
		else puts("NO"); 
	}
	return 0;
}