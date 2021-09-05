#include<bits/stdc++.h>
using namespace std;
long long ret;
int main() {
	int T, s;
	scanf("%d", &T);
	for(int i = 1; i <= T; i++) {
		scanf("%lld", &ret);
		long long rt = sqrt(ret);
		
		printf("Case %d: ", i);

		if(ret == rt * rt) {
			if(rt & 1) {
				printf("%lld %lld\n", 1, rt);
			} else {
				printf("%lld %lld\n", rt, 1);
			}
			continue;
		}
		
		if(rt & 1) {
			if(ret - (rt * rt) > (rt + 1)) {
				printf("%lld %lld\n", rt + 1, 2 * (rt + 1) - ret + (rt * rt));
			} else {
				printf("%lld %lld\n", ret - (rt * rt), (rt + 1));
			}
		} else {
			if(ret - (rt * rt) > (rt + 1)) {
				printf("%lld %lld\n", 2 * (rt + 1) - ret + (rt * rt), (rt + 1));
			} else {
				printf("%lld %lld\n", rt + 1, ret - (rt * rt));
			}
		}	
	}
	return 0;
}