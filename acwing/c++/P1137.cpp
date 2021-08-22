#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 1005, INF = 0x3f3f3f3f;
int n, m, s, dist[N];
vector<PII> E[N];

int dijkstra() {
	priority_queue<PII, vector<PII>, greater<PII>> q;
	memset(dist, 0x3f, sizeof dist);
	dist[0] = 0;
	q.push({0, 0});
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
	
	if(dist[s] == INF) return -1;
	return dist[s]; 
}

int main() {
	while(~scanf("%d%d%d", &n, &m, &s)) {
		for(int i = 0; i < N; i++) {
			E[i].clear();
		}

		for(int i = 1; i <= m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			E[u].push_back({v, w});
		}
		int w;
		scanf("%d", &w);
		for(int i = 1; i <= w; i++) {
			int t;
			scanf("%d", &t);
			E[0].push_back({t, 0});
		}

		printf("%d\n", dijkstra());
	}
	return 0;
}