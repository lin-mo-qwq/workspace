#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 20, M = 1 << 11;
int n, m, p, k;
int g[N][N], dist[N * N][M], key[N * N];
int st[N * N][M];
vector<PII> E[N * N];
set<PII> edge;

void add(int u, int v, int w) {
	E[u].push_back({v, w});
}

void build() {
	int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			for(int u = 0; u < 4; u++) {
				int x = i + dx[u], y = j + dy[u];
				if(!x || x > n || !y || y > m) continue;
				int a = g[i][j], b = g[x][y];
				if(!edge.count({a, b})) {
					add(a, b, 0);
				}
			}
		}
	}
}

int bfs() {
	deque<PII> q;
	memset(dist, 0x3f, sizeof dist);
	dist[1][0] = 0;
	q.push_back({1, 0});
	while(!q.empty()) {
		PII t = q.front();
		q.pop_front();

		if(st[t.first][t.second]) continue;
		st[t.first][t.second] = true;

		if(t.first == n * m) return dist[t.first][t.second];

		if(key[t.first]) {
			int mask = t.second | key[t.first];
			if(dist[t.first][mask] > dist[t.first][t.second]) {
				dist[t.first][mask] = dist[t.first][t.second];
				q.push_front({t.first, mask});
			}
		}

		for(auto i : E[t.first]) {
			if(i.second && !(t.second & (1 << (i.second - 1))))
				continue;
			if(dist[i.first][t.second] > dist[t.first][t.second] + 1) {
				dist[i.first][t.second] = dist[t.first][t.second] + 1;
				q.push_back({i.first, t.second});
			}
		}
	}

	return -1;
}

int main() {
	scanf("%d%d%d%d", &n, &m, &p, &k);
	for(int i = 1, t = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			g[i][j] = t++;
		}
	}

	for(int i = 1; i <= k; i++) {
		int a, b, x, y, w;
		scanf("%d%d%d%d%d", &a, &b, &x, &y, &w);
		int u = g[a][b], v = g[x][y];
		edge.insert({u, v}), edge.insert({v, u});
		if(w) {
			add(u, v, w), add(v, u, w);
		}
	}

	build();

	int s;
	scanf("%d", &s);
	for(int i = 1; i <= s; i++) {
		int x, y, q;
		scanf("%d%d%d", &x, &y, &q);
		key[g[x][y]] |= 1 << (q - 1);
	}

	printf("%d", bfs());
	return 0;
}