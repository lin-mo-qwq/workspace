#include<bits/stdc++.h>
using namespace std;

int n, ret[1005], dp[1005], ans, dp1[1005];

int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++)	cin>>ret[i], dp[i] = 1;
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j < i; j++)
			if(ret[i] > ret[j])	dp[i] = max(dp[i], dp[j] + 1);
	for(int i = n; i >= 1; i--)
		for(int j = n; j > i; j--)
			if(ret[i] > ret[j])	dp1[i] = max(dp1[i], dp1[j] + 1);
	for(int i = 1; i <= n; i++)	ans = max(ans, dp[i] + dp1[i]);

	cout<<ans<<endl;
	return 0;
}