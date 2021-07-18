#include<bits/stdc++.h>
using namespace std; 
const int N = 2005, M = 1e9 + 7;
char s[N];
long long n, f[N][N], sum[N][N];
int main() {
	scanf("%s", s + 2);
	n = strlen(s + 2) + 1;
	f[1][1] = 1;
	for(int i = 1; i <= n; i++) {
		if(s[i]	== 'I' || s[i] == '?') {
			for(int j = 1; j <= i; j++) {
				f[i][j] = (f[i][j] + sum[i - 1][j - 1]) % M;
			}
		}
		if(s[i] == 'D' || s[i] == '?'){
			for(int j = i; j >= 1; j--) {
				f[i][j] = (f[i][j] + sum[i - 1][i] - sum[i - 1][j - 1] + M) % M; 
			}
		}
		for(int j = 1; j <= n; j++) {
			sum[i][j] = (sum[i][j - 1] + f[i][j]) % M;
		}
	}

	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = (ans + f[n][i]) % M;
	}

	if(ans == 0) {
		printf("%lld\n", n);
	}

	printf("%lld\n", ans);
	return 0; 
}