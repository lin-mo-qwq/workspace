#include<bits/stdc++.h>
using namespace std;
const int N = 19;
const int INF = 0x3f3f3f3f;
struct point {
	int x, y;
	friend bool operator == (point a, point b) {
		return a.x == b.x && a.y == b.y;
	}
} a[N];
int n, line[N][N], f[(1 << N)];

int solve(int mask) {
	if (f[mask] != -1) {
		return f[mask];
	}

	if(mask == (1 << n) - 1) {
		return f[mask] = 0;
	}

	f[mask] = INF;

	for(int i = 0; i < n; i++) {
		if(!(mask & (1 << i))) {
			for(int j = 0; j < n; j++) {
				f[mask] = min(f[mask], solve(mask | line[i][j]) + 1);
			}
			break;
		}
	}

	return f[mask];
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d%d", &a[i].x, &a[i].y);
		}

		memset(f, -1, sizeof(f));
		memset(line, 0, sizeof line);
		for(int i = 0; i < n; i++){
			line[i][i] = 1 << i;
			for(int j = 0; j < n; j++){
				if(i == j) continue;
				int r = (1 << i) | (1 << j);
				line[i][j] = line[j][i] = r;
				if(a[i] == a[j]) continue;
				for(int k = 0; k < n; k++){
					if((a[j].x - a[i].x) * (a[k].y - a[i].y) - (a[j].y - a[i].y) * (a[k].x - a[i].x) == 0)
						r |= (1 << k);
				}
				line[i][j] = line[j][i] = r;
			}
		}

		printf("%d\n", solve(0));
	}
	return 0;
}