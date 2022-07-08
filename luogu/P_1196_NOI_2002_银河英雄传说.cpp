#include<bits/stdc++.h>
using namespace std;
const int N = 3e4 + 5;
int p[N], sz[N], f[N];
int anc(int x) {
	if(x != p[x]) {
		int root = anc(p[x]);
		f[x] += f[p[x]];
		p[x] = root;
	} 
	return p[x];
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= 30000; i++) {
		p[i] = i, sz[i] = 1;
	}
	for(int i = 1; i <= n; i++) {
		char opt[2];
		int a, b;
		scanf("%s%d%d", opt, &a, &b);
		if(opt[0] == 'M') {
			a = anc(a), b = anc(b);
			if(a != b) {
				p[a] = b;
				f[a] += sz[b];
				sz[b] += sz[a];
			}
		} else {
			int fa = anc(a), fb = anc(b);
			if(fa != fb) puts("-1");
			else printf("%d\n", abs(f[a] - f[b]) - 1);
		}
	}
	return 0;
}