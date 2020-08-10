#include<iostream>
#include<cstring>
using namespace std;                         

int a, b, dp[15][15][2], ns[20];


int windy(int n)
{                         
	// if(n<=1)
	// 	return 0;
	int ans=0;

	memset(ns, 0, sizeof(ns));
	int len=1;
	while (n)
		ns[len++] = (n % 10), n/=10;
	len--;
	dp[len][ns[len]][0]=1;

	for (int i=0;i<=ns[len]-1;i++)
		dp[len][i][1]=1;

	for (int i=0;i<=len-1;i++)
		for (int j = 1;j <= 9; j++)
			dp[i][j][1] =1;

	for (int i = len; i >= 1; i--)
		for (int j = 1; j <= ns[i]; j++)
		{

			if (ns[i]==j)
			{
				if (abs(ns[i - 1]-j)>=2)
					dp[i - 1][ns[i - 1]][0] += dp[i][j][0];

				for (int k=0;k<=9;k++)
					if (abs(k-j)>=2&&k<ns[i-1])
						dp[i-1][k][1] += dp[i][j][0];

				continue;
			}

			for (int k = 0;k<=9;k++)
				if (abs(k-j)>=2)
					dp[i-1][k][1] += dp[i][j][1];
		}

	for (int i=len-1;i>=1;i--)
	{
		for (int j=0;j<=9;j++)
			ans+=dp[i][j][1];
		ans+=dp[i][ns[i]][0];
	}

	ans += dp[len][ns[len]][0];

	for(int i=0;i<ns[len];i++)
		ans += dp[len][i][1];

	return ans;
}

int main()
{
	cin>>a>>b;                         

	cout<<windy(b) - windy(a - 1)<<endl;                         
	return 0;
}