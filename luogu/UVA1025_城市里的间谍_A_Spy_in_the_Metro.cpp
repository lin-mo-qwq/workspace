#include<bits/stdc++.h>
using namespace std;
const int N = 55, M = 1005, INF = 0x3f3f3f3f;
int n, m, m1, m2;
int t[N], a[N], b[N], f[M][N], h[M][N][2];
int Case = 0;
void work() {
	memset(h, 0, sizeof h);
	scanf("%d", &n);
	if(n == 0) exit(0);
	scanf("%d", &m);
	for(int i = 1; i < n; i++) scanf("%d", &t[i]);
	scanf("%d", &m1);
	for(int i = 1; i <= m1; i++) scanf("%d", &a[i]);
	scanf("%d", &m2);
	for(int i = 1; i <= m2; i++) scanf("%d", &b[i]);
	
	for(int i = 1; i <= m1; i++) {
		int cnt = a[i];
		h[a[i]][1][0] = 1;
		for(int j = 1; j < n; j++) {
			cnt += t[j];
			h[cnt][j + 1][0] = 1;
		} 
	}
	
	for(int i = 1; i <= m2; i++) {
		int cnt = b[i];
		h[b[i]][n][1] = 1;
		for(int j = n; j >= 1; j--) {
			cnt += t[j - 1];
			h[cnt][j - 1][1] = 1;
		}
	}

	memset(f, 0x3f, sizeof f);
	f[0][1] = 0;
	for(int i = 0; i < m; i++) {
		for(int j = 1; j <= n; j++) {
			f[i + 1][j] = min(f[i + 1][j], f[i][j] + 1);
			if(j < n && h[i][j][0] && i + t[j] <= m) {
				f[i + t[j]][j + 1] = min(f[i + t[j]][j + 1], f[i][j]);
			}
			if(j > 1 && h[i][j][1] && i + t[j - 1] <= m) {
				f[i + t[j - 1]][j - 1] = min(f[i + t[j - 1]][j - 1], f[i][j]);
			}
		}
	} 

	printf("Case Number %d: ", Case);
	if(f[m][n] == INF) printf("impossible\n");
	else printf("%d\n", f[m][n]);
}
int main() {
	while(++Case) {
		work();
	}
	return 0;
}