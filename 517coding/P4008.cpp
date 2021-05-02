#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
double ab, ac, bc, k;

double calc(double a, double b, double c) {
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

bool check(double ad) {
	double ae = ac * ad / ab;
	double de = bc * ad / ab;
	double ret = calc(ad, ae, de) / (calc(ab, ac, bc) - calc(ad, ae, de));
	return ret - k > -eps;
}

int main() {
	int T, ca = 0;
	scanf("%d", &T);
	while(T--) {
		scanf("%lf%lf%lf%lf", &ab, &ac, &bc, &k);
		double l = 0, r = ab, best = -1;
		int setp = 100;
		while(setp--) {
			double mid = (l + r) / 2;
			if(check(mid)) {
				best = mid;
				r = mid;
			} 
			else l = mid;
		}
		printf("Case %d: %.2f\n", ++ca, best);
	}
	return 0;
}