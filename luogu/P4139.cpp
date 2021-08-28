#include<bits/stdc++.h>
using namespace std;
#define clr(x) memset(x, true, sizeof(x))
#define M 10000005

typedef long long ll;
int tot, phi[M], pri[M], p;
bool is_pri[M];

void work(int x)
{
	clr(is_pri);
	phi[1] = 1;
	for(int i = 2; i <= x; i++)
	{
		
		if(is_pri[i]) pri[++tot] = i, phi[i] = i - 1;
		for(int j = 1; j <= tot && i * pri[j] <= x; j++)
		{
			is_pri[i * pri[j]] = false;
			if(i % pri[j] == 0)
			{
				phi[i * pri[j]] = phi[i] * pri[j];
				break;
			}
			else
				phi[i * pri[j]] = phi[i] * phi[pri[j]];
		}
	}
}

ll q_pow(ll a, ll b, ll m) 
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

ll pow(ll x)
{
	if(x == 1) return 0;
	return q_pow(2, pow(phi[x])+  phi[x], x);
}

int main()
{
	work(M);
	int t;
	cin >> t;
	while (t -- )
	{
		cin >> p;
		cout << pow(p) <<endl;
	}
	return 0;
}