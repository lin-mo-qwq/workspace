#include<bits/stdc++.h>
using namespace std;
#define M 25
int n, a[M], b[M], f[M][M][M][M], sum1[M], sum2[M];

int dp(int x, int y, int a, int b) {
	int sum = sum1[y] - sum1[x - 1] + sum2[b] - sum2[a - 1]; 
	if(f[x][y][a][b]) {
		return f[x][y][a][b];
	}
	int ans = 0;
	if(x <= y) {
		ans = max(ans, sum - dp(x + 1, y, a, b));
		if(x != y) {	
			ans = max(ans, sum - dp(x, y - 1, a, b));
		}
	}
	if(a <= b) {
		ans = max(ans, sum - dp(x, y, a + 1, b));
		if(x != y) {
			ans = max(ans, sum - dp(x, y, a, b - 1));
		} 
	}

	return f[x][y][a][b] = ans;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum1[i] = sum1[i - 1] + a[i];
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		sum2[i] = sum2[i - 1] + b[i];
	}

	printf("%d\n", dp(1, n, 1, n));
	return 0;
}