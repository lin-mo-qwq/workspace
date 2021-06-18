#include<bits/stdc++.h>
using namespace std;
const int M = 1e5 + 5;
int n, m, ret[M], mx;

bool check(int x) {
	int tmp = ret[1], cnt = 1;
	for(int i = 2; i <= n; i++) {
		if(ret[i] - tmp >= x) {
			tmp = ret[i];
			cnt++;
		}
	} 
	return cnt >= m;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &ret[i]);
	}
	
	sort(ret + 1, ret + 1 + n);
	
	int l = 0, best = -1, r = ret[n] - ret[1];
	
	while(l <= r) {
		int mid = (l + r) >> 1;
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