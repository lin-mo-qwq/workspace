#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, m;
int a[N][N];
int vis[N][N];
int xMove[] = {0, 0, 1, -1};
int yMove[] = {1, -1, 0, 0};

bool bfs(int x, int y, int mx) {
	memset(vis, 0, sizeof vis);
	queue<pair<int, int>> q;
	vis[x][y] = 1;
	q.push({x, y});
	while(!q.empty()) {
		pair<int, int> fnt = q.front();
		q.pop();
		int nowX = fnt.first, nowY = fnt.second;
		for(int i = 0; i < 4; i++) {
			int nxtX = nowX + xMove[i];
			int nxtY = nowY + yMove[i];
			if(nxtX < 1 || nxtX > n || nxtY < 1 
			  || nxtY > m || vis[nxtX][nxtY] || a[nxtX][nxtY] > mx) continue;
			vis[nxtX][nxtY] = 1;
			if(nxtX == n) return true; 
			else q.push({nxtX, nxtY});
		}
	}	
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	int l = 1, r = 1e4 + 5, best = -1;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(bfs(1, 1, mid)) {
			best = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	printf("%d\n", best);
	return 0;
}