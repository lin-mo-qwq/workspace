#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m;
double dist[N];
int w[N], cnt[N], st[N];
vector<pair<int, int>> g[N];

bool check(double mid) {
	memset(st, 0, sizeof st);
	memset(cnt, 0, sizeof cnt);
	queue<int> q;
	for(int i = 1; i <= n; i++) {
		q.push(i);
		st[i] = true;
	}
	while(!q.empty()) {
		int t = q.front(); q.pop();
		st[t] = false;
		for(auto i : g[t]) {
			if(dist[i.first] < dist[t] + w[t] - mid * i.second) {
				dist[i.first] = dist[t] + w[t] - mid * i.second;
				cnt[i.first] = cnt[t] + 1;
				if(cnt[i.first] >= n) return true;
				if(!st[i.first]) q.push(i.first);
			}
		}
	}
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back({v, w});
	}

	double l = 0, r = 1050, best = -1;
	while(r - l > 1e-5) {
		double mid = (l + r) / 2;
		if(check(mid)) l = best = mid;
		else r = mid;
	}

	printf("%.2lf\n", best);
	return 0;
}