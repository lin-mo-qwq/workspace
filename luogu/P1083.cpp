#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, room[N];
struct Need {
	int ret, l, r;
} need[N];

bool judge(int x) {
	int diff[N];
	memset(diff, 0, sizeof diff);
	for(int i = 1; i <= x; i++) {
		diff[need[i].l] += need[i].ret;
		diff[need[i].r + 1] -= need[i].ret;
	}
	for(int i = 1; i <= n; i++) {
		diff[i] += diff[i - 1];
		if(diff[i] > room[i]) return false;
	}
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &room[i]);
	}
	for(int i = 1; i <= m; i++) {
		int ret, l, r;
		scanf("%d%d%d", &ret, &l, &r);
		need[i] = {ret, l, r};
	}

	if(judge(m)) {
		printf("0\n");
		return 0;
	} 

	int l = 1, r = m;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(judge(mid)) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	printf("-1\n%d\n", l);
	return 0;
}