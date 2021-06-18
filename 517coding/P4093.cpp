#include<bits/stdc++.h>
using namespace std;
int T;

int get(int x) {
	int ans = 0;
	while(x > 0) {
		ans += x / 5; 
		x /= 5;
	} 
	return ans;
}

int main() {
	scanf("%d", &T);
	
	for(int i = 1; i <= T; i++) {
		int Q;
		scanf("%d", &Q);
		
		int l = 1, r = 1e9, ret = -1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(get(mid) >= Q) {
				ret = mid;
				r = mid - 1;
			} 
			else l = mid + 1;
		}

		printf("Case %d: ", i);
		if(get(ret) == Q) {	
			printf("%d\n", ret);
		}
		else 
			printf("impossible\n");
	}
	return 0;
}