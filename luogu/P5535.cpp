#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isprime(ll x)
{
	for(ll i = 2; i <= sqrt(x); i++)
		if(x % i == 0) return false;
	return true;
}

int main()
{
	ll n, k;
	cin >> n >> k;

	if(isprime(k + 1) && 2 * k >= n)
		cout << 1 << endl;
	else
		cout << 2 << endl;
	return 0;
}