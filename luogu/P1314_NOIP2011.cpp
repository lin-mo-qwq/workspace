#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 2e5 + 5;
ll n, m, s;
ll w[N], v[N], l[N], r[N];
ll pre1[N], pre2[N];
ll check(int x) {
	memset(pre1, 0, sizeof pre1);
	memset(pre2, 0, sizeof pre2);	
	for(int i = 1; i <= n; i++) {
		pre1[i] = pre1[i - 1] + (ll)(w[i] >= x);
		pre2[i] = pre2[i - 1] + (ll)(w[i] >= x) * v[i];
	}
	
	ll cnt = 0;
	for(int i = 1; i <= m; i++) {
		cnt += (pre1[r[i]] - pre1[l[i] - 1]) * (pre2[r[i]] - pre2[l[i] - 1]);
	}

	return cnt;
}

int main() {
	scanf("%lld%lld%lld", &n, &m, &s);
	for(int i = 1; i <= n; i++) {
		scanf("%lld%lld", &w[i], &v[i]);
	}
	for(int i = 1; i <= m; i++) {
		scanf("%lld%lld", &l[i], &r[i]);
	}

	int l = 0, r = 1e6 + 5;
	ll best = 1e9 + 5;
	while(l <= r) {
		int mid = (l + r) / 2;
		ll tmp = check(mid);
		if(tmp <= s) {
			best = abs(tmp - s);
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	l = 0, r = 1e6 + 5;
	while(l <= r) {
		int mid = (l + r) / 2;
		ll tmp = check(mid);
		if(tmp > s) {
			best = min(best, abs(tmp - s));
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	printf("%lld\n", best);
	return 0;
}