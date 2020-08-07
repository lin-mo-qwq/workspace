#include<bits/stdc++.h>
using namespace std;

#define M 205

int n, a[M], s[M], dp[M][M], dp2[M][M];


int min_dp()
{
	for (int i = 1; i <= n * 2; i++) dp[i][i] = 0;
	for (int l = 2; l <= n; l++)
		for (int i = 1, j = l; j <= n*2; i++,j++)
		{
			dp[i][j] = dp[i][i] + dp[i + 1][j] + s[j] - s[i-1];

			for (int k = i+1; k < j; k++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + s[j] - s[i-1]);
		}

	int temp=dp[1][n];

	for (int i=2;i<=n;i++)
		temp = min(temp, dp[i][i + n - 1]);

	return temp;
}

int max_dp()
{

	for (int l = 2; l <= n; l++)
		for(int i = 1, j = l; j <= n*2; i++,j++)
		{
			dp[i][j] = dp[i][i] + dp2[i + 1][j] + s[j] - s[i - 1];
        	for (int k = i + 1; k < j; k++)
            	dp2[i][j] = max(dp2[i][j], dp2[i][k] + dp2[k + 1][j] + s[j] - s[i - 1]);
		}
	
	int temp=dp2[1][n];

	for (int i=2;i<=n;i++)
		temp = max(temp, dp2[i][i + n - 1]);

	return temp;     
}

int main()
{
	cin>>n;

	for (int i = 1; i <= n; i++)
		cin>>a[i], a[i + n]=a[i];
	for (int i = 1; i <= n * 2; i++)
		s[i] = s[i - 1] + a[i];

	
	cout<<min_dp()<<endl<<max_dp()<<endl;


	return 0;
}