#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], R[N], L[N];
long long ret;

void checkmax(long long &x, long long y) {
	if(x < y) x = y;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	for(int i = 1; i <= n; i++) {
		L[i] = i;
		while(L[i] - 1 >= 1 && a[L[i] - 1] >= a[i]) {
			L[i] = L[L[i] - 1];
		}
	}

	for(int i = n; i >= 1; i--) {
		R[i] = i;
		while(R[i] + 1 <= n && a[R[i] + 1] >= a[i]) {
			R[i] = R[R[i] + 1];
		}
	}

	for(int i = 1; i <= n; i++) {
		checkmax(ret, 1LL * (R[i] - L[i] + 1) * a[i]);
	}

	printf("%lld\n", ret);
	return 0;
}