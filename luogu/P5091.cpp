#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool flag;
ll a, m, b, p;

inline ll read()
{
	register ll ret = 0, c = getchar(), b = 1;
	while (!isdigit(c))
		b = c == '-' ? -1 : 1, c = getchar();
	while (isdigit(c))
	{
		ret = ret * 10 + c - '0', c = getchar();
		if (ret >= p)
			flag = true, ret %= p;
	}
	return (ret * b) % m;
}

ll phi(ll x)
{
	ll ret = x;
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0)
		{
			while (x % i == 0)
				x /= i;
			ret = ret / i * (i - 1);
		}
	if (x > 1)
		ret = ret / x * (x - 1);
	return ret;
}

ll binpow(ll a, ll b)
{
	ll res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = (res * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}

int main()
{
	cin >> a >> m;
	p = phi(m);
	b = read();
	if (flag)
		b += p;
	cout << binpow(a, b);
	return 0;
}