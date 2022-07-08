#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int n, m, ans;
int p[N], d[N];
unordered_map<int, int> S;

int get(int x) {
	if(S.count(x) == 0) return S[x] = ++n;
	return S[x];
}

int anc(int x) {
	if(p[x] != x) {
		int root = anc(p[x]);
		d[x] ^= d[p[x]];
		p[x] = root;
	}
	return p[x];
}

int main() {
	scanf("%d%d", &n, &m);
	n = 0, ans = m;
	for(int i = 1; i < N; i++) p[i] = i;
	for(int i = 1; i <= m; i++) {
		int a, b;
		char opt[N];
		scanf("%d%d%s", &a, &b, opt);
		a = get(a - 1), b = get(b);		
		int type = 0;
		if(opt[0] == 'o') type = 1;

		int fa = anc(a), fb = anc(b);
		if(fa == fb) {
			if(d[a] ^ d[b] != type) {
				ans = i - 1;
				break;
			}
		} else {
			p[fa] = fb;
			d[fa] = d[a] ^ d[b] ^ type;
		}
	}

	cout<<ans<<endl;
	return 0;
}