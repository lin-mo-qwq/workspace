#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m, w[N];
int dmax[N], dmin[N];
int st[N];
vector<int> es[N], et[N];

void spfa(vector<int> e[], int dist[], int type) {
	queue<int> q;
	if(type == 0) {
		memset(dist, 0x3f, sizeof dmin);
		dist[1] = w[1];
		q.push(1);
	} else {
		memset(dist, -0x3f, sizeof dmax);
		dist[n] = w[n];
		q.push(n);
	}

	while(!q.empty()) {
		int k = q.front();
		q.pop();
		st[k] = false;
		for(auto i : e[k]) {
			if(type == 0 && dist[i] > min(dist[k], w[i]) 
				|| type == 1 && dist[i] < max(dist[k], w[i])) {
				if(type == 0) dist[i] = min(dist[k], w[i]);
				else dist[i] = max(dist[k], w[i]);
				
				if(!st[i]) {
					q.push(i);
					st[i] = true;
				}
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}

	for(int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		es[u].push_back(v), et[v].push_back(u);
		if(w == 2)
			es[v].push_back(u), et[u].push_back(v);
	}
	
	spfa(es, dmin, 0);
	spfa(et, dmax, 1);

	int res = 0;
	for(int i = 1; i <= n; i++) {
		res = max(dmax[i] - dmin[i], res);
	}

	printf("%d\n", res);
	return 0;
}