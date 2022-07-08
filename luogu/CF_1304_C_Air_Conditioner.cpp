#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	int p = 0, pl = m, pr = m, flag = 1;
	for(int i = 1; i <= n; i++) {
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		if(pl - (t - p) > r) flag = 0;
		else if(pr + (t - p) < l) flag = 0;
		else pl = max(l, pl - (t - p)), pr = min(r, pr + (t - p));
		p = t;
	}
	if(flag) puts("YES");
	else puts("NO");
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--) {
		solve();
	} 
	return 0;
}