#include<bits/stdc++.h>
using namespace std;
const int M = 1e3  + 50, N = 1e6 + 50;
long long n, m, k, p, ret[M][M], ans, f[N], g[N], sum[2][N];
priority_queue<long long> q;

int main() {
	scanf("%lld%lld%lld%lld", &n, &m, &k, &p);

	for(int i = 1, tmp = 0; i <= n; i++, tmp = 0) {
		for(int j = 1; j <= m; j++)
			scanf("%lld", &ret[i][j]), tmp += ret[i][j]; 
		q.push(tmp);
	}

	for(int i = 1; i <= k; i++) {
		long long tmp = q.top();
		q.pop();
		f[i] = f[i - 1] + tmp;
		q.push(tmp - m * p);
	}

	while(!q.empty())
		q.pop();

	for(int i = 1, tmp = 0; i <= m; i++, tmp = 0) {
		for(int j = 1; j <= n; j++)
			tmp += ret[j][i];
		q.push(tmp);
	}

	for(int i = 1; i <= k; i++) {
		long long tmp = q.top();
		q.pop();
		g[i] = g[i - 1] + tmp;
		q.push(tmp - n * p);
	}
	
	ans = g[k];
	for(int i = 0; i <= k; i++) 
		ans = max(f[i] + g[k - i] - (k - i) * i * p, ans);

	printf("%lld\n", ans);
	return 0; 
}