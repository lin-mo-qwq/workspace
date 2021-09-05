#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, m, s, t;
double dist[N];
vector<pair<int, double>> E[N];

double sPath(int x) {
	priority_queue<pair<double, int>> q;
	memset(dist, -0x3f, sizeof dist);
	dist[x] = 1.0;
	q.push(make_pair(1.0, x));
	while(!q.empty()) {
		int k = q.top().second;
		q.pop();
		for(auto i : E[k]) {
			if(dist[i.first] < dist[k] * i.second) {
				dist[i.first] = dist[k] * i.second;
				q.push(make_pair(dist[i.first], i.first));
			}
		}
	}
	return dist[t];
}

int main() {
	scanf("%d%d", &n, &m);
	int u, v, w;
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		E[u].push_back({v, (100 - w) / 100.0});
		E[v].push_back({u, (100 - w) / 100.0});
	}
	scanf("%d%d", &s, &t);
	printf("%.8lf\n", (double)100.0 / sPath(s));
	return 0;
}