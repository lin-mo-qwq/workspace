#include<bits/stdc++.h>
using namespace std;
const int N = 105;
typedef __int128 ll;
int n, m;
int a[N][N];
ll f[N][N][N], base[N];

void checkMax(ll &x, ll y) {
	if(x < y) x = y;
}

void print(ll x) {
	if(!x) return ;
	print(x / 10);
	printf("%d", x % 10);
}

void findMax(ll f[][N], int ret[]) {
	for(int l = m; l >= 1; l--) {
		for(int r = 1; r <= m; r++) {
			if(l == r) {
				f[l][r] = ret[l] * base[m];
				continue;
			}

			checkMax(f[l][r], f[l][r - 1] + ret[r] * base[(m - r + l)]);
			checkMax(f[l][r], f[l + 1][r] + ret[l] * base[(m - r + l)]);
		}
	}
}

int main() {
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= m; j++)
			scanf("%lld", &a[i][j]);

	base[0] = 1;
	for(int i = 1; i <= m; i++) base[i] = base[i - 1] * 2;

	ll ans = 0;

	for(int i = 1; i <= n; i++) {
		findMax(f[i], a[i]);
		ans += f[i][1][m];
	}

	if(ans == 0) puts("0");
	else print(ans), puts("");
	return 0;
}