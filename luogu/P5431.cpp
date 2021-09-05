#include<bits/stdc++.h>
using namespace std;

const int M = 5000005;
typedef long long ll;

inline ll read()
{
	register ll ret=0,c=getchar(),b=1;
	while(!isdigit(c))b=c=='-'?-1:1,c=getchar();
	while(isdigit(c))ret=ret*10+c-'0',c=getchar();
	return ret*b;
}

ll n, p, k, pre[M], suf[M], a[M]; 

inline ll Inv(const ll ret)
{
    if(ret == 1) return 1;
    return((ll)(p - p / ret) * Inv(p % ret) % p);
}

int main()
{
	n = read(), p = read(), k = read();
	
	ll ans = 0;

	for(register int i = *pre = suf[n + 1] = 1; i <= n; ++i)
		pre[i] = pre[i - 1] * (a[i] = read()) % p;
	for(register int i = n; i; --i)
		suf[i] = suf[i + 1] * a[i] % p;
	for(register ll i = 1, ret = k; i <= n; ++i, ret = ret * k % p)
		ans = (ans + ret * pre[i - 1] % p * suf[i + 1]) % p;
	printf("%lld\n", ans * Inv(pre[n]) % p);
	return 0;
}