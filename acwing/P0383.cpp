#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 1005;
int n, m, S, T;
int st[N][2];
int dist[N][2], cnt[N][2];
vector<PII> E[N];
struct Ver {
	int ver, type, dist;
	friend bool operator > (Ver a, Ver b) {
		return a.dist > b.dist;
	}
} ;

void add(int u, int v, int w) {
	E[u].push_back({v, w});
}

int dijkstra() {
	priority_queue<Ver, vector<Ver>, greater<Ver>> q;	
	memset(dist, 0x3f, sizeof dist);
	memset(cnt, 0, sizeof cnt);
	memset(st, 0, sizeof st);
	dist[S][0] = 0, cnt[S][0] = 1;
	q.push({S, 0, 0});
	
	while(q.size()) {
		Ver t = q.top();
		q.pop();
		int ver = t.ver, type = t.type, distance = t.dist, count = cnt[ver][type];
		
		if(st[ver][type]) continue;
		st[ver][type] = true;

		for(auto i : E[ver]) {
			if(dist[i.first][0] > dist[ver][type] + i.second) {
				dist[i.first][1] = dist[i.first][0];
				cnt[i.first][1] = cnt[i.first][0];
				q.push({i.first, 1, dist[i.first][1]});
				dist[i.first][0] = dist[ver][type] + i.second;
				cnt[i.first][0] = count;
				q.push({i.first, 0, dist[i.first][0]});
			} else if(dist[i.first][0] == dist[ver][type] + i.second) {
				cnt[i.first][0] += count;
			} else if(dist[i.first][1] > dist[ver][type] + i.second) {
				dist[i.first][1] = dist[ver][type] + i.second;
				cnt[i.first][1] = count;
				q.push({i.first, 1, dist[i.first][1]});
			} else if(dist[i.first][1] == dist[ver][type] + i.second) {
				cnt[i.first][1] += count;
			}
		}
	}

	int res = cnt[T][0];
	if(dist[T][0] + 1 == dist[T][1]) res += cnt[T][1];
	return res;
}

int main() {
	int cas;
	scanf("%d", &cas);
	while(cas--) {
		scanf("%d%d", &n, &m);

		for(int i = 0; i < N; i++) {
			E[i].clear();
		}

		for(int i = 1; i <= m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, w);
		}
		scanf("%d%d", &S, &T);
		printf("%d\n", dijkstra());
	}
	return 0;
}