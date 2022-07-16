#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m;
int p[N], d[N];
struct quest {
	int l, r, v;
} q[N];

int anc(int x) {
	if(x != p[x]) {
		int root = anc(p[x]);
		d[x] ^= d[p[x]];
		p[x] = root;
	}
	return p[x];
}

bool cmp(quest a, quest b) {
	return a.v > b.v;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int l, r, v;
		scanf("%d%d%d", &l, &r, &v);
		q[i] = {l, r, v};	
	}

	for(int i = 1; i <= n; i++) p[i] = i;

	sort(q + 1, q + 1 + m, cmp);

	int res = 0;
	for(int i = 1; i <= m; i++) {
		int a = q[i].l, b = q[i].r;
		int pa = anc(a), pb = anc(b);
		if(pa == pb) {
			if(!(d[a] ^ d[b])) {
				res = q[i].v;
				break;
			}
		}
		p[pa] = pb;
		d[pa] = d[a] ^ d[b] ^ 1;
	}

	printf("%d\n", res);

	return 0;
}