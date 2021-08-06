#include<bits/stdc++.h>
using namespace std;
const int N = 50005;
int n, sz;
int value[N], key[N], ls[N], rs[N],
	stk[N], id[N], dad[N];

bool cmp(int a, int b) {
	return key[a] < key[b];
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &key[i], &value[i]);
		id[i] = i;
	}

	sort(id + 1, id + 1 + n, cmp);

	for(int i = 1; i <= n; i++) {
		int s = id[i], k = sz;
		while(k > 0 && value[stk[k]] > value[s]) k--;
		if(k) rs[stk[k]] = s, dad[s] = stk[k];
		if(k < sz) ls[s] = stk[k + 1], dad[stk[k + 1]] = s;
		stk[++k] = s;
		sz = k;
	}

	puts("YES");

	for(int i = 1; i <= n; i++) {
		printf("%d %d %d\n", dad[i], ls[i], rs[i]);
	}

	return 0;
}

