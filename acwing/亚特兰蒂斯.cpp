#include<bits/stdc++.h>
#define lson u << 1
#define rson u << 1 | 1
using namespace std;

const int N = 100005;

struct Segment {
	double x, y1, y2;
	int d;
	bool operator < (const Segment &t) const {
		return x < t.x;
	}
} seg[N * 2];
struct Node {
	int l, r, cnt;
	double len;
} tr[N * 8];

vector<double> ys;

int find(double y) {
	return lower_bound(ys.begin(), ys.end(), y) - ys.begin();
}

void pushup(int u) {
	if(tr[u].cnt) {
		// cerr<<tr[u].l<<' '<<tr[u].r<<endl;
		tr[u].len = ys[tr[u].r + 1] - ys[tr[u].l];
	}
	else if(tr[u].l != tr[u].r) 
		tr[u].len = tr[lson].len + tr[rson].len;
	else tr[u].len = 0;
}

void build(int u, int l, int r) {
	tr[u] = {l, r, 0, 0};
	if(l != r) {
		int mid = l + r >> 1;
		build(lson, l, mid), build(rson, mid + 1, r);
	}
}

void modify(int u, int l, int r, int k) {
	if(l <= tr[u].l && tr[u].r <= r) {
		tr[u].cnt += k;
		pushup(u);
	} else {
		int mid = tr[u].l + tr[u].r >> 1;
		if(l <= mid) modify(lson, l, r, k);
		if(r > mid) modify(rson, l, r, k);
		pushup(u);
	}
}

int n;
int main() {
	int kase = 0;
	while(scanf("%d", &n), n) {
		double ans = 0;
		ys.clear();
		for(int i = 0, j = 0; i < n; i++) {
			double x1, x2, y1, y2;
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			seg[j++] = {x1, y1, y2, 1};
			seg[j++] = {x2, y1, y2, -1};
			ys.push_back(y1), ys.push_back(y2);
		}

		sort(ys.begin(), ys.end());
		ys.erase(unique(ys.begin(), ys.end()), ys.end());

		build(1, 0, ys.size() - 2);
	
		sort(seg, seg + 2 * n);

		for(int i = 0; i < 2 * n; i++) {
			if(i > 0) ans += (seg[i].x - seg[i - 1].x) * tr[1].len;
			modify(1, find(seg[i].y1), find(seg[i].y2) - 1, seg[i].d);
		}
 		printf("Test case #%d\n", ++kase);
		printf("Total explored area: %.2lf\n\n", ans);
	}
	return 0;
}