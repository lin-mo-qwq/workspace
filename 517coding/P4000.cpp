#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 +10;

int n, m, cnt;
struct Node {
	int x, y;
	bool operator < (const Node &ret) {
		return x > ret.x || (x == ret.x && y > ret.y); 
	}
} a[N], b[N];

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) 
		scanf("%d%d", &a[i].x, &a[i].y);
	for(int i = 1; i <= m; i++)
		scanf("%d%d", &b[i].x, &b[i].y);
	
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);	

	int ret[N];
	long long ans = 0;
	memset(ret, 0, sizeof(ret));

	for(int i = 1, j = 1; i <= m; i++) {
		while(j <= n && a[j].x >= b[i].x) {
			ret[a[j].y]++;
			j++;
		}
		for(int k = b[i].y; k <= 100; k++) 
			if(ret[k]) {
				cnt++, ans += 500 * b[i].x + 2 * b[i].y;
				ret[k]--;
				break;
			} 
	}

	printf("%d %lld\n", cnt, ans);
	return 0;
}