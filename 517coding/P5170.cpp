#include<bits/stdc++.h>
using namespace std;
const int N = 75;
long long f[3][N];
long long x;

void init() {
	f[0][0] = 1;
	f[0][1] = f[0][2] = 0;
	for(int i = 1; i < N; i++) {
		f[0][i] = f[0][i - 1] * 10 - f[1][i - 1];
		f[1][i] = f[0][i - 1];
		f[2][i] = f[2][i - 1] * 10 + f[1][i - 1];
	}
}

long long solve(long long x) {
	vector<int> a;
	while(x) {
		a.push_back(x % 10);
		x /= 10;
	}
	int len = a.size();
	a.push_back(0);
	long long ret = 0;
	int flag = 0;
	for(int i = len - 1; i >= 0; i--) {
		ret += a[i] * f[2][i];
		if(flag) {
			ret += f[0][i] * a[i];
		}
		if(!flag && a[i] > 4) {
			ret += f[1][i];
		}
		if(a[i + 1] == 4 && a[i] == 9) {
			flag = 1;
		}
	}
	if(flag == 1) ret++;
	return ret;
}

int main() {
	scanf("%lld", &x);
	init();
	printf("%lld\n", solve(x));
	return 0;
}