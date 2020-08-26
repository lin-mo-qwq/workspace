#include<bits/stdc++.h>
using namespace std;

typedef long long ll; 

ll exgcd(ll a, ll b, ll &x, ll &y)
{
	if(b == 0)
	{
		x = 1, y = 0;
		return a;
	}

	ll q = a / b, r = a % b;
	ll d = exgcd(b, r, x, y);
	
	y -= q * x;

	return d;
}

int main()
{
	ll t;

	cin >> t;

	while(t--)
	{
		ll a, b, c, x, y, g, dx, dy, up, down, xmax, ymax, xmin, ymin;
	
		cin >> a >> b >> c;

		g = exgcd(a, b, x, y);

		if(c % g != 0)
		{
			puts("-1");
			continue;
		}

		x = (x + b) % b;
		y = (y + a) % a;

		x = x * c / g;
		y = y * c / g;

		dx = b / g, dy = a / g;

		down = ceil((1.0-x) / dx), up = floor((y - 1) / dy);

		if(down > up)
		{
			x += down*dx, y -= up * dy;
			cout<<x<<' '<<y<<endl;
		}

		else
		{
			cout<<up-down<<' ';
			xmax = x + up*dx, ymin = y - up*dx;
			xmin = x + down*dx, ymax = y - down*dx;
			cout<<xmin<<' '<<ymin<<' '<<xmax<<' '<<ymax<<endl;
		}
	}
	return 0;
}