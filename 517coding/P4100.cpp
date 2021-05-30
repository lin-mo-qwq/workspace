#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, dp[N][N][3], ret[N][N];
int main() {	
	scanf("%d", &n);
	int pos = -1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int tmp;
			scanf("%d", &ret[i][j]);

			if(ret[i][j] == 0) {
				pos = i;
				dp[i][j][0] = dp[i][j][1] = 1;
				continue;
			} 
			
			tmp = ret[i][j];
			while(tmp % 2 == 0) {
				dp[i][j][0]++;
				tmp /= 2;
			}

			tmp = ret[i][j];
			while(tmp % 5 == 0) {
				dp[i][j][1]++;
				tmp /= 5;
			}
		}
	}

	for(int i = 2; i <= n; i++) {
		dp[1][i][0] += dp[1][i - 1][0];
		dp[1][i][1] += dp[1][i - 1][1];
		dp[i][1][0] += dp[i - 1][1][0];
		dp[i][1][1] += dp[i - 1][1][1];
	}

	for(int i = 2; i <= n; i++) {
		for(int j = 2; j <= n; j++) {
			dp[i][j][0] += min(dp[i][j - 1][0], dp[i - 1][j][0]);
			dp[i][j][1] += min(dp[i][j - 1][1], dp[i - 1][j][1]);
		}
	}

	string ans;
	int k = 0;
	if(dp[n][n][1] < dp[n][n][0]) {
		k = 1;
	}

	if(pos != -1 && dp[n][n][k] > 0) {
		printf("1\n");
		for(int i = 1; i < pos; i++) {
			printf("D");
		} 

		for(int i = 1; i < n; i++) {
			printf("R");
		}

		for(int i = pos; i < n; i++) {
			printf("D");
		}
		return 0;
	}

	int i = n, j = n, flag = 0; 

	while(true) {
		if(i == 1) {
			for(int x = 1; x < j; x++) {
				ans += "R";
			}
			for(int x = 1; x <= j; x++) {
				if(ret[x][j] == 0) {
					flag = 1;	
				}
			}
			break;
		}

		if(j == 1) {
			for(int x = 1; x < i; x++) {
				ans += "D";
			}
			for(int x = 1; x <= i; x++) {
				if(ret[x][j] == 0) {
					flag = 1;	
				}
			}
			break;
		}

		if(ret[i][j] == 0) flag = 1; 

		if(dp[i - 1][j][k] < dp[i][j - 1][k]) {
			ans += "D";
			i--;
		} else {
			ans += "R";
			j--;
		}
	}

	printf("%d\n", dp[n][n][k]);
 	
	for(int i = (int)ans.length() - 1; i >= 0; i--) {
		printf("%c", ans[i]);
	}
	printf("\n");
	return 0;
}