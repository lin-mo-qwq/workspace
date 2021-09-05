#include<bits/stdc++.h>
using namespace std;

#define M 100005
typedef long long ll;

ll a[M], n, m, p, t;

ll qpow(ll a, ll b, ll m) 
{
  	a %= m;
  	ll res = 1;
  	while (b > 0) 
	{
    	if (b & 1) res = res * a % m;
    	a = a * a % m;
    	b >>= 1;
  	}
  	return res;
}

ll C(ll n, ll m)
{
    if(m > n)	return 0;
    return (a[n] * qpow(a[m], p-2, p) % p * qpow(a[n - m], p - 2, p) % p);
}

ll Lucas(ll n, ll m)
{
	if(!m)	
		return 1;
	return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}

int main()
{
	cin>>t;
	while (t--)
	{
		cin>>n>>m>>p;
		a[0] = 1;
		for(int i = 1; i <= p; i++)	a[i] = (a[i - 1] * i) % p;
		cout<< Lucas(n + m, n) <<endl;
	}	
	return 0;
}