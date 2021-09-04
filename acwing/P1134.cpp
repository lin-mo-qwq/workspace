#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, mod = 100003;
int n, m;
int dist[N], cnt[N], st[N];
vector<int> E[N];

void add(int u, int v) {
	E[u].push_back(v);
}

void bfs() {
	memset(dist, 0x3f, sizeof dist);
	cnt[1] = 1, dist[1] = 0;
	queue<int> q;
	q.push(1);
	
	while(!q.empty()) {
		int t = q.front();
		q.pop();

		if(st[t]) continue;
		st[t] = true;

		for(auto i : E[t]) {
			if(dist[i] > dist[t] + 1) {
				dist[i] = dist[t] + 1;
				cnt[i] = cnt[t];
			} else if(dist[i] == dist[t] + 1) {
				cnt[i] = (cnt[i] + cnt[t]) % mod;
			}
			q.push(i);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}

	bfs();

	for(int i = 1; i <= n; i++) {
		printf("%d\n", cnt[i]);
	}

	return 0;
}