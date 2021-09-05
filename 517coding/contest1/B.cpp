#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, m;
long long diff[N], pre[N], pre1[N];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		long long l, r, s, e;
		scanf("%lld%lld%lld%lld", &l, &r, &s, &e);
		long long d = (e - s) / (r - l);
		diff[l] += s, diff[l + 1] += d - s, diff[r + 1] += -e - d, diff[r + 2] += e;
	}

	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + diff[i];
		pre1[i] = pre1[i - 1] + pre[i];
		ans = ans ^ pre1[i];
	}

	printf("%lld\n", ans);
	return 0;
}