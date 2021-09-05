#include<bits/stdc++.h>
using namespace std;
const int N = 105;
const int INF = 0x3f3f3f3f;
int n, m, level[N], dist[N];
vector<pair<int, int>> E[N];

int dijkstra(int l, int r) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    q.push({0, 0});
    while(!q.empty()) {
        int k = q.top().second;
        q.pop();
        for(auto i : E[k]) {
            if(l <= level[i.first] && level[i.first] <= r && dist[i.first] > dist[k] + i.second) {
                dist[i.first] = dist[k] + i.second;
                q.push({dist[i.first], i.first});
            }
        }
    }
	return dist[1];
}

int main() {
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= n; i++) {
		int price, cnt;
		scanf("%d%d%d", &price, &level[i], &cnt);
		E[0].push_back({i, price});
		int id, v;
		while(cnt--) {
			scanf("%d%d", &id, &v);
			E[id].push_back({i, v});
		}
	}

	int res = INF;
	for(int i = level[1] - m; i <= level[1]; i++) {
		res = min(res, dijkstra(i, i + m));	
	}
	printf("%d\n", res);
	return 0;
}