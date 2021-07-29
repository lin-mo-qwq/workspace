#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N = 1e5 + 5;
int t, n, m;
int dad[N], map[N];

int anc(int x) {
	if(x != dad[x]) return dad[x] = anc(dad[x]);
	else return x;
}

void uni(int x, int y) {
	x = anc(x), y = anc(y);
	dad[x] = y;
}

bool ask(int x, int y) {
	x = anc(x), y = anc(y);
	return x == y;
}

void check(int x, int y) {	
	if(ask(x, y)) {
		printf("In the same gang.\n");
	} else {
		if(ask(x, map[y])) {
			printf("In different gangs.\n");
		} else {
			printf("Not sure yet.\n");
		}
	}
}

void insert(int x, int y) {
	if(map[x]) {
		uni(y, map[x]);
	} 
	if(map[y]) {
		uni(x, map[y]);
	}
	vis[y] = x;
	vis[x] = y;
}

int main() {
	scanf("%d", &t);
	while(t--) {
		char opt[2];
		int x, y;
		memset(vis, 0, sizeof vis);
		memset(dad, 0, sizeof dad);
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) {
			dad[i] = i;
		}
		for(int i = 1; i <= m; i++) {	
			scanf("%s%d%d", &opt, &x, &y);
			if(opt[0] == 'A') {
				check(x, y);
 			} else {
				insert(x, y);
 			}
		}
	}
	return 0;
}