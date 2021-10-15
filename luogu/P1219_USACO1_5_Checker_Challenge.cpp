#include<bits/stdc++.h>
using namespace std;
const int N = 500;
int cnt;
int n, f[N], vis[N], dia1[N], dia2[N];

void dfs(int x) {
	if(x > n) {
		++cnt;
		if(cnt <= 3) {
			for(int i = 1; i <= n; i++)
				printf("%d ", f[i]);
			puts("");
		}
	}

	for(int i = 1; i <= n; i++) {
		int tmp1 = x + i, tmp2 = x - i + n;
		if(!dia1[tmp1] && !dia2[tmp2] && !vis[i]) {
			vis[i] = dia1[tmp1] = dia2[tmp2] = 1;
			f[x] = i;
			dfs(x + 1);
			vis[i] = dia1[tmp1] = dia2[tmp2] = 0;
		} 
	}
}

int main() {
	scanf("%d", &n);
	dfs(1);
	printf("%d\n", cnt);
	return 0;
}