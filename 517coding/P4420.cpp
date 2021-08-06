#include<cstdio>
using namespace std;
const int N = 2 * 1e5 + 5;
int n, dadOne[N], dadZero[N];
int szOne[N], szZero[N];
int anc(int a, int set[]) {
	if(set[a] != a)  return set[a] = anc(set[a], set);
	return a;
}

void uni(int a, int b, int set[], int sz[]) {
	a = anc(a,set);
	b = anc(b, set);
	set[a] = b;
	sz[b] += sz[a];
}

int main() {
	scanf("%d", &n);
	int u, v, w;
	for(int i = 1; i <= n; i++) {
		dadOne[i] = dadZero[i] = i;
		szOne[i] = szZero[i] = 1;
	}

	for(int i = 1; i < n; i++) {
		scanf("%d%d%d", &u, &v, &w);
		if(w == 1) {
			uni(u, v, dadOne, szOne);
		} else {
			uni(u, v, dadZero, szZero);
		}
	}

	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		int q = anc(i, dadOne), p = anc(i, dadZero);
		ans = ans + szOne[q] * 1ll * szZero[p] - 1;
	}

	printf("%lld\n", ans);
	return 0;
}