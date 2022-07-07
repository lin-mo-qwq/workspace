#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
const int INF = 1e9;
int n;
float f[N][N];
struct point {
	int x, y;
} p[N];

float dist(int i, int j) {
	int dx = p[i].x - p[j].x, dy = p[i].y - p[j].y;
	return sqrt(dx * dx + dy * dy);
}

int main() {
	while(~scanf("%d", &n)) {
		for(int i = 1; i <= n; i++) {
			scanf("%d%d", &p[i].x, &p[i].y);
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				f[i][j] = INF;
			}
		}
		f[1][1] = 0;
		for(int i = 1; i < n; i++) {
			for(int j = 1; j <= i; j++) {
				if(f[i][j] == INF) continue;
				f[i + 1][j] = min(f[i][j] + dist(i, i + 1), f[i + 1][j]);
				f[i + 1][i] = min(f[i][j] + dist(j, i + 1), f[i + 1][i]);
			}
		}	
		float ans = INF;
		for(int i = 1; i <= n; i++) {
			ans = min(ans, f[n][i] + dist(i, n));
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}