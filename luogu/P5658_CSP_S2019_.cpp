#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5 * 1e5 + 5;
int n, fa[N];
ll block[N], cnt[N];
char a[N];
vector<int> g[N];
stack<int> stk;

void push(int x) {
	if(!stk.empty() && a[x] == ')' && a[stk.top()] == '(') {
		block[x] = block[fa[stk.top()]] + 1;
		stk.pop();
		cnt[x] += block[x];
	} else {
		block[x] = 0;
		stk.push(x);
	}
}


void dfs(int cur, int pre) {
	stack<int> tmp = stk;
	fa[cur] = pre;
	cnt[cur] = cnt[pre];
	push(cur);
	for(auto i : g[cur]) {
		if(i == pre) continue;
		dfs(i, cur);
	}
	stk = tmp;
}

int main() {
	scanf("%d", &n);
	scanf("%s", &a[1]);
	for(int i = 1; i < n; i++) {
		int pre;
		scanf("%d", &pre);
		g[pre].push_back(i + 1);
		g[i + 1].push_back(pre);
	}
	
	dfs(1, 1);

	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = (i * cnt[i]) ^ ans;
	}

	printf("%lld\n", ans);
	return 0;
}