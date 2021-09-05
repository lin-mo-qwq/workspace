#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e4 + 5, INF = 0x3f3f3f3f;
int n, m, root[10];
int dist[10][N];
int vis[10];
typedef pair<int, int> PII;
vector<PII> E[N];

long long dfs(int now, int start, long long distance) {
	if(now == 6) return distance;
	long long res = INF;
	for(int i = 1; i <= 5; i++) {
		if(!vis[i]) {
			int nxt = root[i];
			vis[i] = true;
			res = min(res, dfs(now + 1, i, distance + dist[start][nxt]));
			vis[i] = false;
		}
	}
	return res;
}

void dijkstra(int start, int dist[]) {
	memset(dist, 0x3f, N * 4);
	priority_queue<PII, vector<PII>, greater<PII>> q;
	dist[start] = 0;
	q.push({0, start});	
	while(!q.empty()) {
		int k = q.top().second;
		q.pop();
		for(auto i : E[k]) {
			if(dist[i.first] > dist[k] + i.second) {
				dist[i.first] = dist[k] + i.second;
				q.push({dist[i.first], i.first});
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	root[0] = 1;
	for(int i = 1; i <= 5; i++) {
		scanf("%d", &root[i]);
	}
	int u, v, w;
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		E[u].push_back({v, w});
		E[v].push_back({u, w});
	}	

	for(int i = 0; i <= 5; i++) {
		dijkstra(root[i], dist[i]);
	}

	printf("%lld\n", dfs(1, 0, 0));
	return 0;
}