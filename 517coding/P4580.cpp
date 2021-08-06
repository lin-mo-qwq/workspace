#include<bits/stdc++.h>
using namespace std;
const int N = 3 * 1e5 + 5;
#define clr(x) memset(x, 0, sizeof x)
bool vis[N];
long long sum[N], sum1[N];
int n, fa[N], dep[N], nxt[N];
vector<pair<int, int>> E[N];

int dfs(int cur, int res, int pre) {
	fa[cur] = pre;
	for(auto i : E[cur]) {
		if(i.first != pre) {
			sum[i.first] = sum[cur] + i.second;
			if(sum[res] < sum[i.first]) 
				res = i.first;
			res = dfs(i.first, res, cur);
		}
	}
	return res;
}

int findMax(int cur, int res, int pre) {
	for(auto i : E[cur]) {
		if(i.first != pre && !vis[i.first]) {
			sum1[i.first] = sum1[cur] + i.second;
			if(sum1[res] < sum1[i.first]) 
				res = i.first;
			res = findMax(i.first, res, cur);
		}
	}
	return res;
}

int main() {
	scanf("%d", &n);
	int u, v, w;
	for(int i = 1; i < n; i++) {
		scanf("%d%d%d", &u, &v, &w);
		E[u].push_back(make_pair(v, w));
		E[v].push_back(make_pair(u, w));
	}
	
	int s = dfs(1, 0, 0);
	clr(fa), clr(sum);
	int t = dfs(s, 0, 0);
	printf("%lld\n", sum[t]);

	for(int i = fa[t], j = t; i != 0; i = fa[i]) {
		nxt[i] = j;
		j = i;
	}

	for(int i = s; i != 0; i = nxt[i]) {
		vis[i] = true;
	}

	int i = s, ans = 0;
	for(; i != 0; i = nxt[i]) {
		int tmp = sum[t] - sum[i];
		if(tmp == sum1[findMax(i, 0, 0)]) break;
	}

	for(; i != 0; i = fa[i]) {
		int tmp = sum[i];
		if(tmp == sum1[findMax(i, 0, 0)]) break;
		ans++;
	}

	printf("%d\n", ans); 
	return 0;
}