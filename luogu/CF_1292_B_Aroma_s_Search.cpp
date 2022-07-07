#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll posx[100], posy[100];
int len;
ll x, y, ax, ay, bx, by;
ll xs, ys, t;

ll dis(int i) {
	return abs(posx[i] - x) + abs(posy[i] - y);
}

int solve(int i) {
	ll cnt = 0, tt = t;
	x = xs, y = ys;
	tt -= dis(i);
	if(tt < 0) return cnt;
	cnt++;
	x = posx[i], y = posy[i];
	for(int j = i - 1; j >= 0; j--) {
		tt -= dis(j);
		if(tt < 0) return cnt;
		x = posx[j], y = posy[j], cnt++;
	}

	for(int j = i + 1; j <= len; j++) {
		tt -= dis(j);
		if(tt < 0) return cnt;
		x = posx[j], y = posy[j], cnt++;
	}
	return cnt;
}

int main() {
	cin >> x >> y >> ax >> ay >> bx >> by;
	cin >> xs >> ys >> t;
	posx[0] = x, posy[0] = y;
	for(int i = 1; i <= 90; i++) {
		posx[i] = posx[i - 1] * ax + bx;
		posy[i] = posy[i - 1] * ay + by;
		if(posx[i] > 5e16) {
			len = i - 1;
			break;
		}
	}	

	int ans = 0;
	for(int i = 0; i <= len; i++) {
		ans = max(ans, solve(i));
	}

	cout<<ans<<endl;
	return 0;
}