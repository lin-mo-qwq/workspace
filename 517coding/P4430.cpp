#include<bits/stdc++.h>
using namespace std; 
const int N = 2 * 1e5 + 5;
int n, m, dad[N];
long long sum[N];

int anc(int x) {
	if(dad[x] != x) {
		int root = anc(dad[x]);
		sum[x] += sum[dad[x]];
		return dad[x] = root;
	} else {
		return x;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		dad[i] = i;
	}
	
	int x, y, v, ans = 0;
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &v);
		x--;
		long long tx = anc(x), ty = anc(y);
		if(tx == ty && sum[y] - sum[x] != v) {
			ans++;
		} else if(tx != ty) {
			dad[ty] = tx;
			sum[ty] = sum[x] - sum[y] + v;
		}
	}

	printf("%d\n", ans);
	return 0;
}