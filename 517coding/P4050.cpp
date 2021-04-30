#include<bits/stdc++.h>
using namespace std;
bitset <1010> b[10005];
int n, m;
int main() {
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++) {
		int tmp;
		scanf("%d", &tmp);
		for(int j = 1; j <= tmp; j++) {
			int x;
			scanf("%d", &x);
			b[x].set(i);
		}
	}

	scanf("%d", &m);

	for(int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if((b[x] & b[y]).count())
			printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}
