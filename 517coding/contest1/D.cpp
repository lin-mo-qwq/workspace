#include<bits/stdc++.h>
using namespace std;
const int N = 41, mod = 1e9 + 7;
int n, a[N];
int f[N][N * N][N][2];

int go(int x, int sum, int lst, int flag) {
	if(x == n) return 1;

	int &ret = f[x][sum][lst][flag];
	if(ret != -1) return ret;
	ret = 0;
	if(a[x] == -1) {
		for(int i = 0; i <= 40; i++) {	
			if(((i * x <= sum) || (x == 0)) && (!flag || i >= lst)) {
				ret += go(x + 1, sum + i, i, i < lst);
				if(ret >= mod) ret -= mod;
			}
		}
	} else {
		if ((x == 0) || ((a[x] * x <= sum) && (!flag || a[x] >= lst))) {
			ret += go(x + 1, sum + a[x], a[x], a[x] < lst);
			if (ret >= mod) ret -= mod;
		}
	}
	return ret;
}

int findCnt() {
	memset(f, -1, sizeof f);
	return go(0, 0, 0, 0);
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	printf("%d\n", findCnt());
	return 0;
}