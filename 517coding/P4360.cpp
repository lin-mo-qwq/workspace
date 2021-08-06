#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
int n;
int dep[N];
int a[N], cnt[N], ans[N];
vector<int> E[N];

void dfs(int cur, int fa) {
	int mx = 0;
	dep[cur] = dep[fa] + 1;
	for(int i = 1; i * i <= a[cur]; i++) {
		if(!(a[cur] % i)) {
			cnt[i]++;
			if(cnt[i] >= dep[cur] - 1) {
				ans[cur] = max(ans[cur], i);
				if(cnt[i] == dep[cur]) {
					mx = max(mx, i);
				}
			}
			if((a[cur] / i) != i) {
				cnt[a[cur] / i]++;
				if(cnt[a[cur] / i] >= dep[cur] - 1) {
					ans[cur] = max(ans[cur], a[cur] / i);
					if(cnt[a[cur] / i] == dep[cur]) {
						mx = max(mx, a[cur] / i);
					}
				}
			}
		}
	}

	for(auto i : E[cur]) {
		if(i != fa) {
			ans[i] = max(ans[i], mx);
			dfs(i, cur);
		}
	}

	for(int i = 1; i * i <= a[cur]; i++) {
		if(!(a[cur] % i)) {
			cnt[i]--;
			if((a[cur] / i) != i) {
				cnt[a[cur] / i] --;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int u, v;
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs(1, 1);
	for(int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	puts("");
	return 0;  
} 