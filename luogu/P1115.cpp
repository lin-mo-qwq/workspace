#include<bits/stdc++.h>
using namespace std;

int a[300000],dp[300000];
int main()
{
	int n,ans=-114514;
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>> a[i];
	for(int i=1; i<=n ;i++)
		dp[i] = max( dp[i - 1] + a[i], a[i]), ans = max(ans, dp[i]);
	cout<<ans<<endl;
	return 0;
}
