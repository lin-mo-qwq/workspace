#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll phi(ll x)
{
	ll ret = x;
	for(ll i = 2; i * i <= x; i++)
		if(x % i == 0)
		{
			while(x % i == 0) x /= i;
			ret = ret / i * (i - 1);
		}
	if(x > 1) ret = ret / x * (x - 1);
	return ret; 
}

ll sum_gcd(ll x)
{
	ll ret = 0;
	for(ll i = 1; i * i <= x; i++)	
		if(x % i == 0)
		{
			ret += i * phi(x / i);
			if(i * i != x) ret += x / i *  phi(i);
		}
	return ret;
}

int main()
{
	ll n;
	cin >> n;
	cout << sum_gcd(n) << endl;
	return 0;
}

/*git config --global user.email "2823696074@qq.com"
  git config --global user.name "lin-mo-qwq"*/