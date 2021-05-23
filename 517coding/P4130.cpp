#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, a[N][N], dp[N];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for(int k = 1; k <= n; k++) {
		for(int i = m; i >= 0; i--) {
			for(int j = 1; j <= m; j++) {
				if(i >= j)
					dp[i] = max(dp[i], dp[i - j] + a[k][j]);
			}
		}
	}

	printf("%d", dp[m]);
	return 0;
}