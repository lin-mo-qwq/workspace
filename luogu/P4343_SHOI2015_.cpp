#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const ll INF = 1e18;
typedef long long ll;
ll n, k;
ll a[N];

ll check(ll x) {
	ll sum = 0, cnt = 0;
	for(int i = 1; i <= n; i++) {
		sum = max(sum + a[i], 0ll);
		if(sum >= x) sum = 0, cnt++;
	}
	return cnt;
}

int main() {
	scanf("%lld%lld", &n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}

	ll l = 1, r = INF, mi = -1, mx = -1;

	while(l <= r) {
		ll mid = (l + r) / 2, ret = check(mid);
		if(ret <= k) {
			if(ret == k) mi = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	l = 1, r = INF;

	while(l <= r) {	
		ll mid = (l + r) / 2, ret = check(mid);
		if(ret >= k) {
			if(ret == k) mx = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}	
	}

	if(mi == -1) printf("-1\n");
	else printf("%lld %lld\n", mi, mx);

	return 0;
}