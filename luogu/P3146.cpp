#include<bits/stdc++.h>
using namespace std;

int a[255],dp[255][255],ans;

int main()
{
	int n;
	cin>>n;


	for (int i = 1; i <= n; i++)
		cin>>a[i], dp[i][i] = a[i], ans = max(ans, dp[i][i]);

	for (int i = n-1; i >= 1; i--)
		for (int j = i + 1; j <= n; j++)
		{
			for(int k = i ; k < j; k++)
				if(dp[i][k] == dp[k+1][j])
					dp[i][j] = max(dp[i][j], dp[i][k] + 1);

			ans = max(ans, dp[i][j]);
		}

	cout<<ans<<endl;
	return 0;
}