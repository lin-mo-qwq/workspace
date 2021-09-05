#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 25005, INF = 0x3f3f3f3f;
int t, mr, mp, s;
vector<PII> E[N];
int bcnt, id[N], bin[N];
vector<int> block[N];
queue<int> q;
int dist[N], st[N];
void dfs(int u, int bid) {
	id[u] = bid;
	block[bid].push_back(u);
	for(auto i : E[u]) {
		if(!id[i.first]) {
			dfs(i.first, bid);
		}
	}
}

void dijkstra(int bid) {
	priority_queue<PII, vector<PII>, greater<PII>> heap; 

	for(auto i : block[bid]) {
		heap.push({dist[i], i});		
	}

	while(!heap.empty()) {
		int k = heap.top().second;
		heap.pop();

		if(st[k]) continue;
		st[k] = true;

		for(auto i : E[k]) {
			if(id[i.first] != id[k] && --bin[id[i.first]] == 0) {
				q.push(id[i.first]);
			} 
			if(dist[i.first] > dist[k] + i.second) {
				dist[i.first] = dist[k] + i.second;
				if(id[i.first] == id[k]) {
					heap.push({dist[i.first], i.first});
				}
			}
		}
	}
}

void topsort() {
	memset(dist, 0x3f, sizeof dist);
	dist[s] = 0;

	for(int i = 1; i <= bcnt; i++) {
		if(!bin[i]) {
			q.push(i);
		}
	}	

	while(!q.empty()) {
		int k = q.front();
		q.pop();
		dijkstra(k);
	}
}

int main() {
	scanf("%d%d%d%d", &t, &mr, &mp, &s);
	for(int i = 1; i <= mr; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		E[u].push_back({v, w});
		E[v].push_back({u, w});
	}

	for(int i = 1; i <= t; i++) {
		if(!id[i]) {
			dfs(i, ++bcnt);
		}
	}

	for(int i = 1; i <= mp; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		E[u].push_back({v, w});
		bin[id[v]]++;
	}	
	
	topsort();
	
	for(int i = 1; i <= t; i++) {
		if(dist[i] >= INF / 2) puts("NO PATH");
		else printf("%d\n", dist[i]);
	}
	return 0;
} 
