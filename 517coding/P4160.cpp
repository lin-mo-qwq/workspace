#include<bits/stdc++.h>
using namespace std;
const int M = 18;
const int INF = 15 * 1e8;
int dp[1 << M][M];
int n, a[M], p[M], b[M];

void checkmax(int &x, int y) {
	if(x < y) {
		x = y;
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &a[i], &p[i]);
		if(p[i] != -1) {
			b[p[i]] = 1;
		}
	}

	for(int i = 0; i < (1 << n); i++) {
		for(int j = 0; j < n; j++) {
			dp[i][j] = -INF;
		}
	}

	if(b[0]) {
		for(int i = 0; i < n; i++) {
			if(p[i] == 0) {
				dp[(1 << i)][i] = 0;
			}
		}
	} else {
		for(int i = 0; i < n; i++) {
			if(p[i] == -1) {
				dp[(1 << i)][i] = 0;
			}
		}
	}

	for(int mask = 0; mask < (1 << n); mask++) {
		int pos = 0;
		for(int i = 0; i < n; i++) {
			if((1 << i) & mask) {
				pos++;
			}
		}

		for(int end = 0; end < n; end++) if(dp[mask][end] != -INF) {
			for(int nxt = 0; nxt < n; nxt++) if(!((1 << nxt) & mask)){
				if(p[nxt] == pos || (b[pos] == 0 && p[nxt] == -1)) {
					checkmax(dp[mask | (1 << nxt)][nxt], dp[mask][end] + a[end] * a[nxt]);
				}
			}
		}
	}

	int ret = -INF;
	for(int i = 0; i < n; i++) {
		checkmax(ret, dp[(1 << n) - 1][i]);
	}

	printf("%d\n", ret);
	return 0;
}