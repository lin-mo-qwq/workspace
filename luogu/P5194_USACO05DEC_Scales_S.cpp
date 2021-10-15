#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
typedef long long ll;
ll n, k;
ll a[N], sum[N], ans;

void dfs(ll x, int ord) {
	if(x > k) return ;
	if(sum[ord - 1] + x <= k) {
		ans = max(sum[ord - 1] + x, ans);
		return;
	}
	ans = max(ans, x);
	for(int i = 1; i <= ord - 1; i++) {
		dfs(x + a[i], i);
	}
}

int main() {
	scanf("%lld%lld", &n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	dfs(0, n + 1);
	printf("%lld\n", ans);
	return 0;
}