#include<bits/stdc++.h>
using namespace std;
const int M = 100000 + 5;
const int INF = 0x3f3f3f3f;
int n, a[M], d[M], g[M], ans[M];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	int tmp = 0, mx = INF, len = 0;
	memset(g, 0x3f, sizeof(g)); 
	for(int i = 1; i <= n; i++) {
		int j = lower_bound(g + 1, g + n, a[i]) - g;
		d[i] = j;
		g[j] = a[i];
		len = max(len, d[i]);
	}

	tmp = len, mx = INF;
	for(int i = n; i >= 1; i--) {
		if(!tmp) break;
		if(d[i] == tmp && a[i] < mx) {
			mx = a[i];
			ans[tmp--] = a[i];
		}
	}

	if(len == 0) {
		printf("orz\n");
	}

	for(int i = 1; i <= len; i++) {
		printf("%d ", ans[i]);
	}
	puts("");
	return 0;
}