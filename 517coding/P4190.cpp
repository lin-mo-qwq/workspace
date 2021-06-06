#include<bits/stdc++.h>
using namespace std;
const int M = 16;
string s;
int n, dp[1 << M];
bool a[1 << M];
bool judge(int mask) {
	string x = "", tmp = "";
	for(int i = 0; i < n; i++) {
		if(mask & (1 << i)) {
			tmp += s[i];
		}
	}
	x = tmp;
	reverse(tmp.begin(), tmp.end());
	return x == tmp;
}

int main() {
	cin>>s;
	n = s.size();
	for(int mask = 1; mask < (1 << n); mask++) {
		dp[mask] = 17;
		a[mask] = judge(mask);
	}
	dp[0] = 0;
	for(int mask = 0; mask < (1 << n); mask++) {
		for(int sub = mask; sub > 0; sub = mask & (sub - 1)) {
			if(a[sub]) {
				dp[mask] = min(dp[mask], dp[mask - sub] + 1);
			}
		}
	}

	printf("%d\n", dp[(1 << n) - 1]);
	return 0;
}