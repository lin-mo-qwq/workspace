#include<bits/stdc++.h>
using namespace std;
const int N = 505, INF = 0x3f3f3f3f;
int n, m;
int stop[N], g[N][N];
int dist[N];

void bfs(int x) {
	queue<int> q;
	memset(dist, 0x3f, sizeof dist);
	dist[x] = 0;
	q.push(x);
	while(!q.empty()) {
		int t = q.front();
		q.pop();
		for(int i = 1; i <= m; i++) {
			if(g[t][i] && dist[i] > dist[t] + 1) {
				dist[i] = dist[t] + 1, q.push(i);
			}
		}
	}
} 

int main() {
	scanf("%d%d", &n, &m);
	string line;
	getline(cin, line);
	while(n--) {
		getline(cin, line);
		stringstream ss(line);
		int cnt = 0, p;
		while(ss >> p) stop[++cnt] = p;
		for(int i = 1; i <= cnt; i++) {
			for(int j = i + 1; j <= cnt; j++) {
				g[stop[i]][stop[j]] = 1;
			}
		}
	}
	bfs(1);
	
	if(dist[m] == INF) printf("NO\n");
	else printf("%d\n", max(dist[m] - 1, 0));
	return 0;
}