#include<bits/stdc++.h>
using namespace std;
const int N = 55;
int n, m, k, s, p;
int lx[] = {0, 1, -1, 0};
int ly[] = {1, 0, 0, -1};
int d[N][N][N][N], key[N][N], ret[N][N][(1 << 11)];
struct node {
	int x, y;
	int cnt, key;
} ;

void bfs() {
	queue <node> q;
	int Key = 0;
	if(key[1][1]) {
		Key |= key[1][1];
	}
	q.push({1, 1, 0, Key});	
	while(!q.empty()) {
		auto t = q.front();
		q.pop();
		int Key = t.key;
		if(ret[t.x][t.y][t.key] != 0x3f3f3f3f) 
			continue;
		ret[t.x][t.y][t.key] = min(ret[t.x][t.y][t.key], t.cnt);
		if(key[t.x][t.y]) {
			Key |= key[t.x][t.y];
		}
		for(int i = 0; i < 4; i++) {
			int nx = t.x + lx[i], ny = t.y + ly[i];
			int tmp = d[t.x][t.y][nx][ny];
			if(nx > 0 && nx <= n && ny > 0 && ny <= m) {
				if((Key & (1 << tmp)) || tmp == -1) {
					q.push({nx, ny, t.cnt + 1, Key});
				}
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &p);
	scanf("%d", &k);
	memset(d, -1, sizeof(d));
	memset(ret, 0x3f, sizeof(ret));
	for(int i = 0; i < k; i++) {
		int x1, x2, y1, y2, tep;
		scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &tep);
		d[x1][y1][x2][y2] = d[x2][y2][x1][y1] = tep;
	}
	scanf("%d", &s);
	for(int i = 0; i < s; i++) {
		int x, y, tep;
		scanf("%d%d%d", &x, &y, &tep);
		key[x][y] |= (1 << tep);
	}

	bfs();
	
	int ans = 0x3f3f3f3f;
	for(int i = 0; i <= (1 << p); i++) {
		ans = min(ans, ret[n][m][i]);
	}

	if(ans == 0x3f3f3f3f) {
		printf("-1\n");
	} else {
		printf("%d\n", ans);
	}
	return 0;
}