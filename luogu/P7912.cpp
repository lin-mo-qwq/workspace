#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
int a[N], used[N];
struct block {
	int fnt, til;
} ;
queue<block> q, q2;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	a[n + 1] = -1;
	for(int i = 2, fnt = 1; i <= n + 1; i++) {
		if(a[i] != a[i - 1]) q.push({fnt, i - 1}), fnt = i; 
	}

	int cnt = n;
	while(cnt) {
		while(q.size()) {
			auto t = q.front(); q.pop();
			while(used[t.fnt] && t.fnt <= t.til) t.fnt++;
			if(t.fnt > t.til) continue;
			printf("%d ", t.fnt); cnt --;
			used[t.fnt] = 1;
			if(t.fnt == t.til) continue;
			t.fnt++, q2.push(t);
		}
		puts("");
		while(q2.size()) {
			auto add = q2.front(); q2.pop();
			while(q2.size()) {
				auto x = q2.front(); 
				if(a[x.til] == a[add.til]) {
					add.til = x.til;
					q2.pop();
				} else break;
			}
			q.push(add);
		}
	}
	return 0;
}