#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
typedef pair<int, int> PII;
int n, m;
char a[N][N];
int h[N][N];

void checkMax(int &x, int y) {
	if(x < y) x = y;
}

int findMax(int k) {
	int L[N], R[N], ret = 0;
	for(int i = 1; i <= m; i++) {
		L[i] = i;
		while(L[i] - 1 >= 1 && h[k][L[i] - 1] >= h[k][i]) {
			L[i] = L[L[i] - 1];
		}
	}

	for(int i = m; i >= 1; i--) {
		R[i] = i;
		while(R[i] + 1 <= n && h[k][R[i] + 1] >= h[k][i]) {
			R[i] = R[R[i] + 1];
		}
	}

	for(int i = 1; i <= m; i++) {
		checkMax(ret, (R[i] - L[i] + 1) * h[k][i]);
	}
}

int main() {
	memset(a, -1, sizeof(a));
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%s", a[i]);
		for(int j = 0; j < m; j++) {
			if(a[i][j] == '0' && a[i][j] == a[i - 1][j]) {
				h[i][j + 1] = h[i - 1][j + 1];
			}
			if(a[i][j] == '0') h[i][j + 1]++;
		}
	}

	for(int i = 1; i <= n; i++) {
	}
	return 0;
}