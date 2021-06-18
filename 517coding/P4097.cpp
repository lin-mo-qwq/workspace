#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f;
ll mx = INF, mi = -INF;
ll T, n, m;

ll calc(ll x, ll y) {
	return x * x + 100000 * x + y * y - 100000 * y + x * y; 
}

bool check(ll ret) { // 二分编号
	ll tmp = 0;
	for(int i = 1; i <= n; i++) {
		ll l = 1, r = n, best = 0;
		while(l <= r) {
			ll mid = (l + r) / 2;
			if(calc(mid, i) <= ret) {
				l = mid + 1, best = mid;
			} else {
				r = mid - 1; 
			}
		}
		tmp += best;
	} 	
	return tmp >= m; 
}

int main() {
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld%lld", &n, &m);
		ll l = mi, r = mx, best = -1;
		while(l <= r) { // 二分答案
			ll mid = (l + r) / 2;
			if(check(mid)) {
				r = mid - 1;
				best = mid;
			} else {
				l = mid + 1;
			}
		}
		printf("%lld\n", best);
	}
	return 0;
}