#include<bits/stdc++.h>
using namespace std;
const int N = 75;
int a[N];
long long f[N][N];
long long dfs(int len, int left, int right, bool leftLim, int rightLim) {
	if(left < right) return (!leftLim) || (leftLim && rightLim != 2);
	if(!leftLim && f[left][len] != -1) return f[left][len];	
	long long ret = 0;
	int mx = leftLim ? a[left] : 9;
	for(int i = 0; i <= mx; i++) {
		if(i != 0 && i != 1 && i != 8) continue;
		if(left == len - 1 && i == 0 && len != 1) continue;
		int rm = rightLim;
		if(i > a[right]) rm = 2;
		if(i < a[right]) rm = 1;
		ret += dfs(len, left - 1, right + 1, leftLim && i == mx, rm);
	}
	if(!leftLim) f[left][len] = ret;
	return ret;
}

long long solve(string n) {
	int len = n.size();
	for(int i = 0; i < len; i++) {
		a[len - i - 1] = n[i] - '0';
	}
	long long ret = 0;
	for(int i = 1; i <= len; i++) {
		ret += dfs(i, i - 1, 0, i == len, 0);
	}
	return ret;
}

int main() {
	memset(f, -1, sizeof f);
	string n, m;
	cin>>n>>m;

	int len = n.size();
	bool flag = 0;
	for(int i = 0; i < len; i++) {
		flag = false;
		if(n[i] == n[len - 1 - i] && (n[i] == '8' || n[i] == '1' || n[i] == '0')) {
			flag = true;
		}
		if(!flag) break;
	}
	printf("%lld\n", solve(m) - solve(n) + flag);
	return 0;
}