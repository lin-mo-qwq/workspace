#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int year, month, day;

ll pastDay(int x){
	ll day=1ll * (x + 4712) * 365;
	if(x > 1582) day -= 10;
	day += 1ll * (x + 4712 + 3) / 4;
	if(x >= 1600) {
		x -= 1601;
		day -= (ll)x / 100ll;
		day += (ll)x / 400ll;
	}
	return day;
}
bool getLeat(int year) {
	if(year < 0) return (year + 1) % 4 == 0;
	else if(year <= 1582) return year % 4 == 0;
	else return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

void getMonthAndDay(ll n) {
	if(n == 0) {
		year--;
		month = 12;
		day = 31;
		return ;
	}
	int Month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 99};
	int cnt = 1;
	if(getLeat(year)) Month[2]++;
	while(n >= Month[cnt]) {
		n -= Month[cnt];
		if(cnt == 10 && year == 1582) n += 10;
		cnt++;
	}

	if(year == 1582 && cnt == 10 && n >= 5) {
		n += 10;
	}

	if(n <= 0) month = --cnt, day = Month[cnt];
	else month = cnt, day = n;
}

void getAns(ll n) {
	int l = -4713, r = 1e9 + 5, best;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(n >= pastDay(mid)) {
			best = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	year = best;
	if(year < 0) year--;
	getMonthAndDay(n - pastDay(best));
}

int main() {
	int q;
	// freopen("P7075_6.in", "r", stdin);
	// freopen("P7075_6(1).out", "w", stdout);
	scanf("%d", &q);
	ll x;
	for(int i = 1; i <= q; i++) {
		scanf("%lld", &x);
		getAns(x + 1);
		printf("%d %d ", day, month);
		if(year < 0) printf("%d BC\n", -year);
		else if(year == 0) printf("%d BC\n", 1);
		else printf("%d\n", year);
	}
	return 0;
}