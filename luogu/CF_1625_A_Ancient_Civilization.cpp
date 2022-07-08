#include<bits/stdc++.h>
using namespace std;
int bit[32];
void solve() {
	memset(bit, 0, sizeof bit);
	int n, t, x;
	scanf("%d%d", &n, &t);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &x);
		for(int i = 0; i <= t; i++) 
			if((1 << i)  & x) bit[i] ++;
	}

	int ans = 0;
	for(int i = 0; i <= t; i++) {
		if(bit[i] * 2 >= n) ans |= (1 << i);
	}
	printf("%d\n", ans);
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) solve();
	return 0;
}