#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, k, a[N];
int q[N], fr, ed;
bool empty() {
	return fr == ed;
}

void clear() {
	fr = ed = 0;
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	for(int i = 1; i <= n; i++) {
		while(!empty() && a[i] <= a[q[ed - 1]]) {
			ed--;
		}
		q[ed++] = i;
		while(!empty() && i - q[fr] >= k) {
			fr++;
		}
		if(i >= k) {
			printf("%d ", a[q[fr]]);
		}
	}
	puts("");
	clear();
	for(int i = 1; i <= n; i++) {
		while(!empty() && a[i] >= a[q[ed - 1]]) {
			ed--;
		}
		q[ed++] = i;
		while(!empty() && i - q[fr] >= k) {
			fr++;
		}
		if(i >= k) {
			printf("%d ", a[q[fr]]);
		}
	}
	return 0;
}