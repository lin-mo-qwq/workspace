#include<bits/stdc++.h>
using namespace std;

#define M 10000005
typedef long long ll;
#define clr(x) memset(x, true, sizeof(x))

ll n, r, inv[M], f[M], g[M], tot, p[M], ans[M];
bool isp[M];

void work(ll x)
{
	clr(isp);
	f[1] = 1, inv[0] = inv[1] = 1, g[1] = 1;  
	
	for(int i = 2; i <= x; i++)
	{
		f[i] = i * f[i - 1] % r, inv[i] = (r - r / i) * inv[r % i] % r;
		if(isp[i]) p[++tot] = i;
		for(int j = 1; i * p[j] <= x; j++)
		{
			isp[i * p[j]]=0;
			if(i % p[j]==0)
				break;
		}
 	}

	for(int i = 2; i <= x; i++)
	{
		g[i] = g[i - 1];
		if(isp[i]) g[i] = g[i] * (i - 1) % r * inv[i] % r;
	}
}

int main(void)
{
	int t;
	ios::sync_with_stdio(false);
	cin >> t >> r;
	work(M - 5);
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		printf("%d\n", f[n] * g[m] * r);	
	}
	return 0;
}