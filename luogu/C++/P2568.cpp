#include<bits/stdc++.h>
using namespace std;
#define clr(x) memset(x, true, sizeof(x))
#define M 10000005

typedef long long ll;
int tot, phi[M], pri[M], p;
ll sum[M], ans;
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
	for(int i = 1; i <= x; i++) sum[i] = sum[i - 1] + phi[i];
}

int main()
{
	int n;
	cin >> n;
	work(n);
	for(int i = 1; i <= tot; i++)	ans += 2 * sum[n / pri[i]] - 1;
	cout << ans << endl;
	return 0;
}