#include<bits/stdc++.h>
using namespace std;
int n, k;
const double eps = 1e-8;
const int M = 1e5 + 5;
struct point {
	int id;
	double v, w, sum;	 
	void cnt(double ret) {
		sum = v - w * ret;
	}
	void ins() {
		scanf("%lf%lf", &v, &w);
	}
	bool operator < (const point a) const {
		return a.sum - sum > -eps;
	}
} ret[M];

bool check(double mid) {
	priority_queue <double> q;
	for(int i = 1; i <= n; i++) {
		ret[i].cnt(mid);
		q.push(ret[i].sum);
	}
	double sum = 0;
	for(int i = 1; i <= k; i++) {
		double tmp = q.top();
		q.pop();
		sum += tmp;
	}	
	return sum > -eps;
}

int main() {
	
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) {
		ret[i].ins();
		ret[i].id = i;
	}	
	
	double l = 0, r = 100, best = -1;

	while(fabs(l - r) > eps) {
		double mid = (l + r) / 2;
		if(check(mid)) {
			best = mid; 
			l = mid;
		} else {
			r = mid;
		}
	}

	priority_queue <point> q;
	for(int i = 1; i <= n; i++) {	
		ret[i].cnt(best);
		q.push(ret[i]);
	}

	for(int i = 1; i <= k; i++) {
		point tmp = q.top();
		q.pop();
		printf("%d ", tmp.id);
	}

	printf("\n");
	return 0;
}