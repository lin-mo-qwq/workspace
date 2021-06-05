#include<bits/stdc++.h>
using namespace std;
const int M = 15;
int n, mp[M][M], dp[(1 << M)][M];

void checkmin(int &x, int y) {
	if(x < 0 || y < x) {
		x = y;
	}
}

int main() {
	scanf("%d", &n);
	n++;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &mp[i][j]);
		}
	}

	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
			}
		}
	}

	memset(dp, -1, sizeof(dp));
	dp[1][0] = 0;

	for(int mask = 0; mask < (1 << n); mask++) {
		for(int end = 0; end < n; end++) if(dp[mask][end] != -1) {
			for(int nxt = 0; nxt < n; nxt++) if(!(mask & (1 << nxt))) {
				checkmin(dp[mask | (1 << nxt)][nxt], dp[mask][end] + mp[end][nxt]);
			}
		}
	}

	int ret = 1e9;
	for(int i = 0; i < n; i++) {
		if(dp[(1 << n) - 1][i] > 0) {
			ret = min(ret, dp[(1 << n) - 1][i] + mp[i][0]);
		}
	}

	printf("%d\n", ret);
	return 0;
}