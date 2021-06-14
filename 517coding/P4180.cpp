#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
#define N 21
#define lowbit(x) x & (-x)
long long n, m, e[N][N], f[(1 << N)][N], ans;

void checkmax(long long &x, long long y) {
	if(x < y) x = y;
}

int main() {
	scanf("%lld%lld", &n, &m);
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		v--, u--;
		e[v][u] = e[u][v] = 1;
	}

	for(int i = 0; i < n; i++) {
		f[(1 << i)][i] = 1;
	}

	for(int mask = 0; mask < (1 << n); mask++) {
		int pos = lowbit(mask);

		for(int i = 0; i <= n; i++) {
			if(pos & (1 << i)) {
				pos = i;
				break;
			}
		}

		for(int end = pos; end < n; end++) {
			for(int nxt = pos; nxt < n; nxt++) if(e[end][nxt]) {
				if(mask & (1 << nxt)) {
					if(pos == nxt) {
						ans += f[mask][end];
					}
				} else {
					f[mask | (1 << nxt)][nxt] += f[mask][end];		
				}
			}			
		}
	} 

	printf("%lld", (ans - m) / 2);
	return 0;
}