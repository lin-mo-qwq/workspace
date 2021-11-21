#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
int cnt, cntRoot, root[N], isok[N], ok[N], id[N];

bool check(int x) {
	while(x != 0) {
		if(x % 10 == 7) return true;
		x /= 10;
	}
	return false;
}

void cnting() {
	for(int i = 1; i < N; i++) {
		isok[i] = check(i);
		if(isok[i]) root[++cntRoot] = i;
	}
	for(int i = 1; i <= cntRoot; i++) {
		for(int j = 1; j * root[i] < N; j++) {
			isok[j * root[i]] = true;
		}
	}
	for(int i = 1; i < N; i++) {
		if(!isok[i]) ok[++cnt] = i, id[i] = cnt;
	}
}

int main() {
	cnting();
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i ++) {
		int x;
		scanf("%d", &x);
		if(isok[x]) printf("-1\n");
		else printf("%d\n", ok[id[x] + 1]);
	}
	return 0;
}