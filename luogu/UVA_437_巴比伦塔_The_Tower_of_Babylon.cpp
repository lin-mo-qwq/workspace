#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n;
int ret[N][N];
struct blocks {
	int l[4], s[4];
	void inp() {
		for(int i = 0; i < 3; i++) scanf("%d", &l[i]);
		sort(l, l + 3);
	}
	bool operator < (blocks a) {
		return l[0] * l[1] < a.l[1] * a.l[0];
	}
} a[50];

bool check(int idx1, int h1, int idx2, int h2) {
	vector <int> l1, l2;
	for(int i = 0; i < 3; i++) 
		if(i != h1) l1.push_back(a[idx1].l[i]);
	for(int i = 0; i < 3; i++) if(i != h2) 
		l2.push_back(a[idx2].l[i]);
	if(l1[0] < l2[0] && l1[1] < l2[1]) {
		return true;
	}
	return false;
}

int f(int idx, int h) {
	if(ret[idx][h]) return ret[idx][h];
	ret[idx][h] = a[idx].l[h];
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 3; j++) 
			if(check(idx, h, i, j))	{
				ret[idx][h] = max(ret[idx][h], a[idx].l[h] + f(i, j));
			}
	}
	return ret[idx][h];
}

void ans(int idx, int h) {
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 3; j++) 
			if(check(idx, h, i, j) && ret[idx][h] == a[idx].l[h] + ret[i][j]) {
				ans(i, j);
			}
	}
}

int main() {
	int Case = 0;
	while(scanf("%d", &n), n) {
		memset(a, 0, sizeof a);
		memset(ret, 0, sizeof ret);
		for(int i = 1; i <= n; i++) a[i].inp();
		sort(a + 1, a + 1 + n);
		int ans = 0;
		for(int i = 1; i <= n; i++) 
			for(int j = 0; j < 3; j++) ans = max(ans, f(i, j));
		printf("Case %d: maximum height = %d\n", ++Case, ans);
	}
	return 0;
}