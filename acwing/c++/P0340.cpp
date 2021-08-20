#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, p, k, dist[N];
typedef pair<int, int> PII;
vector<pair<int, int>> E[N];

bool check(int x) {
	priority_queue<PII, vector<PII>, greater<PII>> q;
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	q.push({0, 1});
	while(!q.empty()) {
		int k = q.top().second;
		q.pop();
		for(auto i : E[k]) {
			int w = i.second > x;
			if(dist[i.first] > dist[k] + w) {
				dist[i.first] = dist[k] + w;
				q.push({dist[i.first], i.first});
			}
		}
	}
	return dist[n] <= k;	
}

int main() {
	scanf("%d%d%d", &n, &p, &k);
	for(int i = 1; i <= p; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		E[u].push_back({v, w});
		E[v].push_back({u, w});
	}

	int l = 0, r = 1e6, best = -1; 
	while(l <= r) {
		int mid = (l + r) / 2;
		if(check(mid)) {
			best = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}		
	}	

	printf("%d\n", best);
	return 0;
}