#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
int n;
int a[N], tr[N];
ll g[N], l[N];

int lowbit(int x) {
	return x & (-x);
}

void add(int x, int c) {
	for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

int sum(int x) {
	int res = 0;
	for(int i = x; i; i -= lowbit(i)) res += tr[i];
	return res; 
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	for(int i = 1; i <= n; i++) {
		g[i] = sum(n) - sum(a[i]);
		l[i] = sum(a[i] - 1); 
		add(a[i], 1);
	}

	memset(tr, 0, sizeof tr);
	ll res1 = 0, res2 = 0;
	for(int i = n; i; i--) {
		res1 += g[i] * (sum(n) - sum(a[i]));
		res2 += l[i] * sum(a[i] - 1);
		add(a[i], 1);
	}

	printf("%lld %lld", res1, res2);
	return 0;
}