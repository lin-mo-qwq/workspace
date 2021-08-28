#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e4 + 5;
int n, m, a[N];

bool check(int x) {
	int past = 0, cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] - past < x) {
			cnt++;
		} else {
			past = a[i];
		}
	}
	return cnt <= m;
}

int main() {
	int dis;
	scanf("%d%d%d", &dis, &n, &m);
	for(int i = 1; i <= n + 1; i++) {
		if(i > n) a[i] = dis;
		else scanf("%d", &a[i]);
	}
	++n;
	int l = 1, r = a[n], best = -1;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(check(mid)) {
			best = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	printf("%d\n", best);
	return 0;
}