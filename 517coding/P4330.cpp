#include<bits/stdc++.h>
using namespace std;
#define M 30005 
int n, cnt[M];
vector<pair<int, int>> E[M];

void bfs(int x) {
	queue<int> q;
	q.push(x);
	memset(cnt, -1, sizeof cnt);
	cnt[x] = 0;
	while(!q.empty()){
		int fr = q.front();
		q.pop();
		for(auto i : E[fr]) {
			if(cnt[i.first] == -1) {
				q.push(i.first);
				cnt[i.first] = cnt[fr] + i.second;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	int u, v, w;
	for(int i = 1; i < n; i++) {
		scanf("%d%d%d", &u, &v, &w);
		E[u].push_back({v, w});
		E[v].push_back({u, w});
	}
	bfs(0);
	
	int t = 0, ret = 0;
	for(int i = 0; i < n; i++) 
		if(ret < cnt[i]) ret = cnt[i], t = i;
	
	bfs(t);

	ret = 0;
	for(int i = 0; i < n; i++) {
		ret = max(ret, cnt[i]);
	}

	printf("%d\n", ret);
	return 0;
}