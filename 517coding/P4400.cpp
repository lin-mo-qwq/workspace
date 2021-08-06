#include<bits/stdc++.h>
using namespace std;
#define mp(a, b) make_pair(a, b)
const int N = 2 * 1e5 + 5;
int n, fa[22][N];
long long dis[N], a[N];
int ans[N];
vector<pair<int, int>> E[N];
void dfs(int cur, int dad) {
	fa[0][cur] = dad;
	for(auto i : E[cur]) {
		if(i.first != dad) {
			dis[i.first] = dis[cur] + i.second;
			dfs(i.first, cur);
			ans[cur] += ans[i.first];
		}
	}
}

void init() {
	for(int i = 1; i < 21; i++) {
		for(int j = 1; j <= n; j++) {
			fa[i][j] = fa[i - 1][fa[i - 1][j]];
		}
	}
}

void find(int x) {
	long long tmp = dis[x] - a[x];
	int j = x;
	for(int i = 20; i >= 0; i--) {
		if(tmp <= dis[fa[i][j]] && fa[i][j]) {
			j = fa[i][j];
		}
	}
	if(j != x) {
		ans[fa[0][j]]--;
		ans[fa[0][x]]++;
	} 
} 

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	int v, p;
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &v, &p);
		E[(i + 1)].push_back(mp(v, p));
		E[v].push_back(mp((i + 1), p));
	}
	dfs(1, 1);
	init();
	fa[0][1] = 0;
	for(int i = 1; i <= n; i++) find(i);
	dfs(1, 1);
	for(int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	puts("");
	return 0;
}