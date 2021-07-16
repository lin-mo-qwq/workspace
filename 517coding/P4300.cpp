#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int fr, ed, q[N];
int n, k, t, f[N];

void checkmin(int &x, int y) {
	if(x > y) x = y;
}

bool empty() {
	return fr == ed;
}

int main() {
	scanf("%d%d%d", &n, &k, &t);
	memset(f, 0x3f, sizeof(f));
	f[1] = 0;
	for(int i = 1; i <= n; i++) {
		if(!(i % k))  checkmin(f[i], f[i / k] + 1);
		while(!empty() && f[i] <= f[q[ed - 1]]) {
			ed--;
		}
		q[ed++] = i;
		while(!empty() && i - q[fr] > t) {
			fr++;
		}
		checkmin(f[i], f[q[fr]] + 1);
	}
	printf("%d\n", f[n]);
	return 0;
}