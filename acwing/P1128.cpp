#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;
int n, m;
int dist[N];
vector<pair<int, int>> E[N];

int dijkstra(int x) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;	
	memset(dist, 0x3f, sizeof dist);
	dist[x] = 0;
	q.push(make_pair(0, x));
	while(!q.empty()) {
		int k = q.top().second;
		q.pop();
		for(auto i : E[k]) {
			if(dist[i.first] > dist[k] + i.second) {
				dist[i.first] = dist[k] + i.second;
				q.push(make_pair(dist[i.first], i.first));
			}
		}
	}

    int mx = 0;
    for(int i = 1; i <= n; i++) {
        mx = max(dist[i], mx);
    }
    if(mx == INF) return -1;
	return mx;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		E[u].push_back(make_pair(v, w));
		E[v].push_back(make_pair(u, w));
	}
    printf("%d\n", dijkstra(1));
	return 0;
}