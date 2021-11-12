#include<bits/stdc++.h>
using namespace std; 
const int N = 1e4 + 5;
int n;
int st[N];
bool cnt[N];
double dist[N];
vector<pair<int, int>> g[N];

bool check(double mid) {
	memset(st, 0, sizeof st);
	memset(cnt, 0, sizeof cnt);
	queue<int> q;
	for(int i = 0; i < N; i++)
		q.push(i), st[i] = true;
	int count = 0;
	while(!q.empty()) {
		int t = q.front(); q.pop();
		st[t] = false;
		for(auto i : g[t]) {
			if(dist[i.first] < dist[t] + (double)i.second - mid) {
				dist[i.first] = dist[t] + (double)i.second - mid;
				cnt[i.first] = cnt[t] + 1;
				if(++count > N) return true;
				if(cnt[i.first] >= n) return true;
				if(!st[i.first]) {
					q.push(i.first);
					st[i.first] = true;
				}
			}
		}
	} 
	return false;
}

int main() {
	char str[N];
	while(scanf("%d", &n), n) {
		for(int i = 0; i <= N; i++) g[i].clear();
		for(int i = 1; i <= n; i++) {
			scanf("%s", str);
			int len = strlen(str);
			if(len >= 2) {
				int left = (str[0] - 'a') * 26 + str[1] - 'a';
				int right = (str[len - 2] - 'a') * 26 + str[len - 1] - 'a';
				g[left].push_back({right, len});
			}
		}
		double l = 0, r = 1e4 + 5, best = -1;
		while(r - l > 1e-11) {
			double mid = (l + r) / 2;
			if(check(mid)) l = best = mid;
			else r = mid;
		}
		if(best == -1) puts("No solution");
		else printf("%lf\n", best);
	}
	return 0;
}