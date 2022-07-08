#include<bits/stdc++.h>
using namespace std;
const int N = 150010;
int cnt[N];
void solve() {
	memset(cnt, 0, sizeof cnt);
	int ans = -1, n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		if(cnt[x]) {
			ans = max(ans, cnt[x] + n - i);
		}
		cnt[x] = i;
	}
	cout<<ans<<endl;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) solve();
	return 0;
}