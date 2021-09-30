#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const double INF = 1e9 + 5;
struct Node {
	int x, y;
} p[N];
int n;
Node tmp[N];

double dist(Node x, Node y) {
	double dx = (x.x - y.x), dy = (x.y - y.y);
	return sqrt(dx * dx + dy * dy);
}

bool cmp(Node x, Node y) {
	if(x.x == y.x) return x.y < y.y;
	return x.x < y.x;
}

bool cmps(Node x, Node y) {
	return x.y < y.y;
}

double solve(int l, int r) {
	double d = INF;
	if(l == r) return d;
	if(l + 1 == r) {
		return dist(p[l], p[r]);
	} 
	int mid = (l + r) / 2, k = 0;
	double d1 = solve(l, mid), d2 = solve(mid + 1, r);
	d = min(d1, d2);
	for(int i = l; i <= r; i++) {
		if(fabs(p[i].x - p[mid].x) < d) 
			tmp[++k] = p[i];
	}
	
	sort(tmp + 1, tmp + 1 + k, cmps);

	for(int i = 1; i <= k; i++) {
		for(int j = i + 1; j <= k && (tmp[j].y - tmp[i].y) < d; j++) {
			d = min(d, dist(tmp[i], tmp[j]));
		}	
	}

	return d;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &p[i].x, &p[i].y);
	}
	sort(p + 1, p + 1 + n, cmp);
	printf("%.4lf", solve(1, n));
	return 0;
}