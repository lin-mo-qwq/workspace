#include<bits/stdc++.h>
using namespace std;
struct coin {
	int m, v;
} a[110];
bool cmp(coin x, coin y) {
	return x.v * y.m > y.v * x.m;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i].m, &a[i].v);
	}
	sort(a + 1, a + 1 + n, cmp);
	float ans;
	for(int i = 1; i <= n; i++) {
		if(a[i].m > m) {
			if(m) ans += 1.0 * m * a[i].v / a[i].m;
			break;
 		} 
		ans += a[i].v;
		m -= a[i].m;
	}
	printf("%.2lf\n", ans);
	return 0;
}