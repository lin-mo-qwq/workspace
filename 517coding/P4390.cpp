#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 +5;
int n, leaf;
int cnt[N];

int main() {
	scanf("%d", &n); 
	int u, v;	
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		cnt[u]++;
		cnt[v]++;
	}
	int mx = 0;
	
	for(int i = 1; i <= n; i++) {
		mx = max(mx, cnt[i]);
	}
	printf("%d", mx + 1);
	return 0;
}