#include<iostream>
using namespace std;

typedef long long ll;
ll x, y, m, n, l, x0, y0, a, b, gcd;

ll exgcd(ll a, ll b, ll &x,ll &y)
{
	if(b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	ll q = a / b, r = a % b;
	ll gcd = exgcd(b, r, y, x);
	y -= q * x;
	return gcd;
}

int main()
{
	cin >> x >> y >> m >> n >> l;
	a = n - m, b = x - y;
	if(a < 0) a = -a, b = -b;
	gcd = exgcd(a, l, x0, y0);
	if(b % gcd) cout<<"Impossible"<<endl;
	else cout<<((x0 * b / gcd) % (l / gcd) + (l/gcd)) % (l/gcd)<<endl;
	return 0;
}