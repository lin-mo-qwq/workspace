#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
struct point {
	double x, y, z;
	void ins() {
		scanf("%lf%lf%lf", &x, &y, &z);
	}
} A, B, P;

double dist(point a, point b) {
	double tmp = pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
	return sqrt(tmp + pow(a.z - b.z, 2));
}

double get(double k) {
	point s;
	s.x = A.x + (B.x - A.x) * k;
	s.y = A.y + (B.y - A.y) * k;
	s.z = A.z + (B.z - A.z) * k;
	return dist(s, P);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		A.ins(), B.ins(), P.ins();
		double l = 0, r = 1, best = -1;
		while(fabs(l - r) > eps) {
			double mid1 = l + (r - l) / 3;
			double mid2 = r - (r - l) / 3;
			best = get(mid1);
			if(get(mid1) - get(mid2) < -eps) { 
				r = mid2;
			} else {
				l = mid1;
			}
		}
		printf("%lf\n", best);
	}
	return 0;
}