#include<bits/stdc++.h>
using namespace std;
const int N = 10, M = 105;
const int INF = 0x3f3f3f3f;

struct point {
	int x, y;
} ;

point a[N], sol[M][N];
int cnt, col[M], dig[2][M];
int n, f[N][1024], ans = INF;
void dfs(int x) {
	if(x == n) {
		++cnt;
		for(int i = 0; i < n; i++) {
			sol[cnt][col[i] - 1] = (point){col[i] - 1, i};
		}
		return ;
	}

	for(int y = 0; y < n; y++) {
		if(col[y] || dig[1][x + y] || dig[0][y - x + 10]) {
			continue;
		}
		col[y] = dig[1][x + y] = dig[0][y - x + 10] = x + 1;
		dfs(x + 1);
		col[y] = dig[1][x + y] = dig[0][y - x + 10] = 0;
	}
}

int move_cnt(point _a, point _b) {
	int t1 = abs(_a.x - _b.x);
	int t2 = abs(_a.y - _b.y);
	int step = 0;
	if(min(t1, t2)) step++;
	if(abs(t1 - t2)) step++;
	return step;
}

int find_min(int k) {
	for(int i = 1; i <= n; i++) {
		for(int mask = 0; mask < (1 << n); mask++) {
			for(int end = 0; end < n; end++) if(mask & (1 << end)) {
				f[i][mask] = min(f[i][mask], f[i - 1][mask - (1 << end)] +
					move_cnt(sol[k][i - 1], a[end]));
			}
		}
	}
	return f[8][255];
}

int main() {
	n = 8;
	char c[100][100];
	for(int i = 0; i < n; i++) {
		scanf("%s", &c[i]);
		for(int j = 0; j < n; j++) {
			if(c[i][j] == 'q') {
				a[cnt++] = {i, j};
			}
		}
	}

	cnt = 0;
	dfs(0);


	for(int i = 1; i <= cnt; i++){
		memset(f, 0x3f, sizeof f);
		f[0][0] = 0;
		ans = min(ans, find_min(i));
	}

	printf("%d\n", ans);
	return 0;
}