#include<bits/stdc++.h>
using namespace std;
int n;
long long ret = 0;
stack <pair<int, int>> stk;

void checkmax(long long &x, long long y) {
	if(x < y) {
		x = y;
	}
}

int main() {
	scanf("%d", &n);
	stk.push(make_pair(0, -1));
	int x;
	for(int i = 0; i <= n; i++) {
		if(i < n) {
			scanf("%d", &x);
		} else {
			x = 0;
		}
		int right = i - 1, left = -1;
		while(!stk.empty() && stk.top().first > x) {
			pair<int, int> top = stk.top();
			stk.pop();
			left = stk.top().second + 1;
			checkmax(ret, (1LL * top.first * (right - left + 1)));
		}
		stk.push(make_pair(x, i));
	}
	printf("%lld\n", ret);
	return 0;
}

