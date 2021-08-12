#include<bits/stdc++.h>
using namespace std;
const int N = 1005;

struct number {
	int ret, sub; 
	friend bool operator < (number x, number y) {
		if(x.sub == y.sub) {
			return x.ret > y.ret;
		} 
		return x.sub <= y.sub;
	}
} a[N];

void solve() {
	for(int i = 1; i < N; i++) {
		a[i].sub++;
		a[i].ret = i;
		for(int j = 2 * i; j < N; j += i) {
			a[j].sub++;
		}
	}
}

int main() {
	solve();
	sort(a + 1, a + 1001);
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) {
		int n;
		scanf("%d", &n);
		printf("Case %d: %d\n", i, a[n].ret);
	}	
	return 0;
}