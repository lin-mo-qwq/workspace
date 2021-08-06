#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
int n, a[N];
long long dis[N], sz[N], ans;
vector<pair<int, int>> E[N];

void dfs(int cur, int fa) {
	sz[cur] = 1; 
	for(auto i : E[cur]) {
		if(i.first != fa) {
			dis[i.first] = dis[cur] + i.second;
			dfs(i.first, cur);
			sz[cur] += sz[i.first];
		}
	}
}

void dfs2(int cur, int fa, int mi) {
	if(dis[mi] > dis[cur]) {
		mi = cur;
	}
	for(auto i : E[cur]) {
		if(i.first != fa) {
			if(dis[i.first] - a[i.first] > dis[mi]) {
				ans += sz[i.first];
			} else {
				dfs2(i.first, cur, mi);
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int v, w;
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &v, &w);
		E[i + 1].push_back(make_pair(v, w));
		E[v].push_back(make_pair(i + 1, w));
	}
	dfs(1, 1);
	dfs2(1, 1, 1);
	printf("%lld\n", ans);
	return 0;
}