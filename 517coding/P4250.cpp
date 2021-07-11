#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, R[N], f[25][N];
int main() {
	scanf("%d%d", &n, &m);
	int l, r;
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &l, &r);
		R[l] = max(R[l], r);
	}

	for(int i = 1; i < N; i++) {
		R[i] = max(R[i - 1], R[i]);
		f[0][i] = R[i];
	}
	f[0][0] = R[0];

	for(int i = 1; i <= 20; i++) {
		for(int j = 0; j < N; j++) {
			f[i][j] = f[i - 1][f[i - 1][j]];
		}
	}

	while(m--) {
		scanf("%d%d", &l, &r);
		int ret = 0;
		for(int i = 20; i >= 0; i--) {
			if(f[i][l] < r) {
				ret += (1 << i);
				l = f[i][l];
			}
		}
		if(f[0][l] < r) {
			printf("-1\n");
			continue;
		}
		ret++;
		printf("%d\n", ret);
	}
	return 0;
}