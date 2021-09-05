#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}

	ll q = a / b, r = a % b;
	ll d = exgcd(b, r, x, y);

	ll t = x;
	x = y;
	y = t - q * y;

	return d;
}

int main()
{
	ll t;

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		ll a, b, c, x, y, g, dx, dy, up, down, xmax, ymax, xmin, ymin;

		cin >> a >> b >> c;

		g = exgcd(a, b, x, y);

		if (c % g != 0)
		{
			cout<< -1 <<endl;
			continue;
		}

		x = x * c / g;
		y = y * c / g;

		dx = b / g, dy = a / g;

		down = ceil((1.0 - x) / dx), up = floor((y - 1.0) / dy);

		if (down > up)
		{
			x += down * dx, y -= up * dy;
			cout << x << ' ' << y << endl;
		}

		else
		{
			cout << (up - down) + 1 << ' ';
			xmax = x + up * dx, ymin = y - up * dy;
			xmin = x + down * dx, ymax = y - down * dy;
			cout << xmin << ' ' << ymin << ' ' << xmax << ' ' << ymax << endl;
		}
	}
	return 0;
}