#include<bits/stdc++.h>
using namespace std;
int n, m;
float tot;
priority_queue<int, vector<int>, greater<int>> q;
int main() {
	int kase = 0;
	while(~scanf("%d%d", &n, &m), n, m) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1, x; j <= m; j++){
				scanf("%d", &x);
				q.push(x);
			}
		}
		cin>>tot;
		tot /= 100;
		float cnt = 0, ans, id = 1;
		while(!q.empty()) {
			cnt += q.top();
			if((cnt + tot) / id<= 1.0 * q.top()) {
				id--, cnt -= q.top();
				break;
			}
			q.pop(), id++;
		}
		if(q.empty()) id--;
		while(!q.empty()) q.pop();
		ans = (cnt + tot) / id;
		printf("Region %d\n", ++kase);
		printf("Water level is %.2lf meters.\n", ans);
		printf("%.2lf percent of the region is under water.\n\n", id / (1.0 * n * m) * 100.0);
	}	
	return 0;
}