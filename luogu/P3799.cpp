#include<bits/stdc++.h>
using namespace std;
#define mod (int)(1e9 + 7)
typedef long long ll;

ll n, a[100005], edge[100005], ans, len = -1;

ll C(ll n, ll m)
{
	return(m == 1 ? n: n * (n - 1) / 2ll) % mod; 
}

int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>a[i], len = max(len, a[i]), edge[a[i]]++;

	for(int i = 2; i <= len; i++)
	{
		if(edge[i] >= 2)
		{		
			int tmp = C(edge[i], 2) % mod;

			for(int j = 1; j <= i / 2; j++)
			{
				if(j != i - j && edge[j] && edge[i - j])
					ans = (ans + (tmp * C(edge[j], 1) * C(edge[i - j], 1)) % mod) % mod;
				if(j == i - j && edge[j] >= 2)
					ans = (ans + (tmp * C(edge[j], 2) % mod)) % mod;
			}	
		}
	}

	cout<<ans<<endl;
	return 0;
}