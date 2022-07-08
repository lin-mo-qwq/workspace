#include<bits/stdc++.h>
using namespace std;
const int N = 505, M = 1e5 + 5;
int p[N], v[N], f[N][N];

int dis(int x, int y) {
	return (p[y] - p[x]) * v[x];
} 

int main() {
	int n, t, K;
	scanf("%d%d%d", &n, &t, &K);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}
	n++, p[n] = t;

	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	for(int i = 1; i <= n; i++) {
		f[i][0] = f[i - 1][0] + dis(i - 1, i);
	}

	for(int i = 1; i <= n; i++) {
		for(int j = i - 1; j >= 1; j--) {
			for(int k = K; k >= (i - j) - 1; k--) {
				f[i][k] = min(f[i][k], f[j][k - (i - j) + 1] + dis(j, i));
			}
		}
	}
	
	int ans = f[0][1];
	for(int i = 0; i <= K; i++) ans = min(ans, f[n][i]);
	cout<<ans<<endl;
	return 0;
}