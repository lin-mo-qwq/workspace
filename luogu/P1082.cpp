#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void exgcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return;
	}

	ll q = a / b, r = a % b;
	exgcd(b, r, y, x);
	y -= q * x;
}

int main()
{
	ll a, b, x, y;

	cin >> a >> b;

	exgcd(a, b, x, y);

	cout << (x + b) % b;
	return 0;
}