#include<bits/stdc++.h>
using namespace std;
const int N = 20;
typedef long long ll;
int len;
int a[N], cnt[N];
long long f[22][1025][1025];
int check(int mask) {
	int newMask = 0;
	for(int i = 0; i <= 9; i++) {
		if((1 << i) & mask) {
			if((i % 2) != (cnt[i] % 2)) {
				newMask |= (1 << i);
			}
		}
	}
	return newMask;
}

int dfs(int now, int mask, bool lim, bool preIsZero)  {
	if(now == 0) {
		if(preIsZero) return 0;
		else return check(mask) == mask;
	}
	int nowMask = check(mask);
	if(!lim && !preIsZero && f[now][mask][nowMask] != -1) {
		return f[now][mask][nowMask];
	}
	int mx = lim ? a[now] : 9;
	long long ret = 0;
	for(int i = 0; i <= mx; i++) {
		if(preIsZero) {
			if(i) cnt[i]++;
			ret += dfs(now - 1, (i == 0)?0:(1 << i), lim && (i == mx), i == 0);
			if(i) cnt[i]--;
		} else {
			cnt[i]++;
			ret += dfs(now - 1, mask | (1 << i), lim && (i == mx), false);
			cnt[i]--;
		}
	}
	if(!lim && !preIsZero) {
		f[now][mask][nowMask] = ret;
	}
	return ret;
}

long long solve(long long n) {
	len = 0;
	while(n) {
		a[++len] = n % 10;
		n /= 10;
	}
	return dfs(len, 0, true, true);
}

int main() {
	memset(f, -1, sizeof f);
	ll n, m;
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%lld%lld", &n, &m);
		printf("%lld\n", solve(m) - solve(n - 1));
	}
	return 0;
}