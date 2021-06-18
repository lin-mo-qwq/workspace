#include<bits/stdc++.h>
using namespace std;
const int M = 40005;
int n, a[M], d[M], g[M]; 
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	int len = 0;
	memset(g, 0x3f, sizeof(g));
	for(int i = 1; i <= n; i++) {
		int j = lower_bound(g + 1, g + n, a[i]) - g;
		d[i] = j;
		g[j] = a[i];
		len = max(len, d[i]);
	}

	printf("%d\n", len);
	return 0;
}