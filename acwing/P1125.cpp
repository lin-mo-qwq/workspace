#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int, int> PII;
const int N = 205;
const double INF = 1e20;
PII p[N];
int n;
char g[N][N];
double d[N][N], maxd[N];

double getDist(PII a, PII b) {
	double dx = a.x - b.x, dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &p[i].x, &p[i].y);
	}

	for(int i = 1; i <= n; i++) {
		scanf("%s", &(g[i][1]));
	}	

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) d[i][j] = 0;
			else if(g[i][j] == '1') d[i][j] = getDist(p[i], p[j]);
			else d[i][j] = INF;
		}
	}

	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(d[i][j] < INF) {
				maxd[i] = max(maxd[i], d[i][j]);
			}
		}
	}

	double res1 = 0, res2 = INF;
	for(int i = 1; i <= n; i++) res1 = max(res1, maxd[i]);

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(d[i][j] >= INF) {
				res2 = min(res2, getDist(p[i], p[j]) + maxd[i] + maxd[j]);
			}
		}
	}

	printf("%.6lf\n", max(res1, res2));
	return 0;
}