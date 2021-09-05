#include<bits/stdc++.h>
using namespace std;
const int N = 75;
int a[N];
long long f[3][N];

long long dfs(int now, int mask, bool lim) {
	if(now == 0) {
		return (mask == 2);
	}
	if(!lim && f[mask][now] != -1) {
		return f[mask][now];
	}
	int mx = lim ? a[now] : 9;
	long long ret = 0;
	for(int i = 0; i <= mx; i++) {
		int newMask = mask;
		if(mask == 0 && i == 4) newMask = 1;
		else if(mask == 1 && i != 4 && i != 9) newMask = 0;
		else if(mask == 1 && i == 9) newMask = 2;
		ret += dfs(now - 1, newMask, lim && i == mx);
	}
	if(!lim) {
		f[mask][now] = ret;
	}
	return ret;
}

void solve(long long n) {
	int len = 0;
	while(n) {
		a[++len] = n % 10;
		n /= 10;
	}
	printf("%lld", dfs(len, 0, true));	
}

int main() {
	long long n;
	memset(f, -1, sizeof f);
	scanf("%lld\n", &n);
	solve(n);
	return 0;
}