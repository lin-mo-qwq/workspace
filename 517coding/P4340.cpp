#include<bits/stdc++.h>
using namespace std;
const int M = 10005;
int n, vis[M];
int sz[M], mx[M];
vector<int> E[M];
void dfs(int x) {
	vis[x] = 1;
	sz[x] = 1;
	mx[x] = 0;
	for(auto i : E[x]) {
		if(!vis[i]) {
			dfs(i);
			sz[x] += sz[i];
			mx[x] = max(mx[x], sz[i]);
		}
	}
	mx[x] = max(mx[x], n - sz[x]);
}

int main() {
	int u, v;
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs(1);
	int ret = 0x3f3f3f3f;
	for(int i = 1; i <= n; i++) {
		ret = min(ret, mx[i]);
	}

	for(int i = 1; i <= n; i++) {
		if(mx[i] == ret) {
			printf("%d\n", i);
		}
	}

	return 0;
}