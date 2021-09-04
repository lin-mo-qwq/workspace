#include<bits/stdc++.h>
using namespace std;
const int N = 75;
typedef long long ll;
ll f[N][N];
int a[N];
ll dfs(int now, ll cnt, bool lim, bool preIsZero) {
	if(now == 0) {
		if(preIsZero) return 1;
		else return cnt;
	}
	if(!lim && f[now][cnt] != -1 && !preIsZero) {
		return f[now][cnt];
	}
	int mx = lim ? a[now] : 9;
	ll ret = 0;
	for(int i = 0; i <= mx; i++) {
		if(preIsZero) ret += dfs(now - 1, 0, lim && (i == mx), i == 0);
		else ret += dfs(now - 1, cnt + (i == 0), lim && (i == mx), false);
	}
	if(!lim && !preIsZero) {
		f[now][cnt] = ret;
	}
	return ret;
}

ll solve(ll n) {
	int len = 0;
	while(n) {
		a[++len] = n % 10;
		n /= 10;
	}	
	return dfs(len, 0, true, true);
}

int main() {
	memset(f, -1, sizeof f);
	long long l, r;
	scanf("%lld%lld", &l, &r);
	printf("%lld\n", solve(r) - solve(l - 1));
	return 0;
}