#include<bits/stdc++.h>
using namespace std;

#define MAXN 15
typedef long long ll;

ll n, a[MAXN], m[MAXN];
ll binpow(ll a, ll b, ll m) 
{
	a %= m;
	ll res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

inline void exgcd(ll a, ll b, ll &x, ll &y)
{
	if(b == 0)
	{
		x = 1, y = 0;
		return ;
	}
	ll q = a / b, r = a % b;
	exgcd(b, r, y, x);
	y -= q * x;
}

inline ll inv(ll a, ll b) 
{
	ll x, y;
	exgcd(a, b, x, y);
	return x;
}

ll CRT(const ll a[], const ll m[], ll n)
{
	ll M = 1, ret = 0;
	for(int i = 1; i <= n; i++)	M *= m[i];
	for(int i = 1; i <= n; i++)
	{
		ll Mi = M / m[i], ti = inv(Mi, m[i]);
		if(ti < 0) ti+=m[i];
		ret = (ret + binpow(ti, binpow(Mi, (a[i] + M) % M, M), M) + M) % M;
	}
	if(ret < 0) ret += M;
	return ret;
}

int main()
{
	cin>>n;

	for(int i = 1; i <= n; i++)	cin>>a[i];
	for(int i = 1; i <= n; i++)	cin>>m[i];
	cout<<CRT(a, m, n)<<endl;
	return 0;
}