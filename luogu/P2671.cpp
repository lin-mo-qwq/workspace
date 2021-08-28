#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define M 10007
typedef long long ll;
ll n, m, color[N], cnt[2][N], sum[2][N], num[N], ans;
int main()
{
	cin>>n>>m;
	for(int i = 1; i <= n; i++) cin>>num[i];
	for(int i = 1; i <= n; i++) cin>>color[i];
	for(int i = 1; i <= n; i++)
	{
		int col = color[i];
		int g = i & 1;
		cnt[g][col]++; sum[g][col] += num[i];
		sum[g][col] %= M;
	}
	for(int i = 1; i <= n; i++)
	{
		int col = color[i];
		int g = i & 1;
        ans += i % M * ((sum[g][col] + (cnt[g][col] - 2) % M * num[i] + M) % M);	
		ans %= M;
	}
	cout<<ans<<endl;
	return 0;
}
