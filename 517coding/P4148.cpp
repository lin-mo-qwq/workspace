#include<bits/stdc++.h>
using namespace std;
#define clr(x) memset(x, 0, sizeof(x))
const int N = 105, INF = 1e9;
int n, a[N][N], ans = -INF, ret[N];

void ChangeArray(int x) {
	for(int i = 1; i <= n; i++) {
		ret[i] += a[x][i];
	}
}

int maxSubArray()  {
	int sum = -INF, ans = -INF;
	for(int i = 1; i <= n; i++) {
		sum = max(sum, 0) + ret[i];
		ans = max(sum, ans);
	}	
	return ans;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for(int i = 1; i <= n; i++) {
		clr(ret);
		for(int j = i; j <= n; j++) {
			ChangeArray(j);
			ans = max(ans, maxSubArray());
		}
	}	

	printf("%d", ans);
	return 0;
}