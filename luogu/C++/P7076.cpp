#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int n, m, c, k;
int vis[70], cntAns, cnt;
int main() {
	scanf("%d%d%d%d", &n, &m, &c, &k);
	ull mask = 0;
	for(int i = 1; i <= n; i++) {
		ull id;
		cin>>id;
		mask |= id;
	}

	if(n == 0) {
		printf("18446744073709551616\n");
		exit(0);
	}

	int q, r;
	for(int i = 1; i <= m; i++) {
		scanf("%d%d", &q, &r);
		if((1ull << q) & mask && !vis[q]) {
			cntAns++;
		} if(!vis[q]) {
			cnt++;
			vis[q] = true;
		}
	}

	ull ans = pow(2, max(k - cnt, 0)) * pow(2, cntAns);
	cout<<ans - n<<' '<<endl;
	return 0;
}