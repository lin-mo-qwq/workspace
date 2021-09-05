#include<bits/stdc++.h>
using namespace std;

const int M = (1<<18)+5;
const int INF = 1145148989 ;

int n, w;
int a[M];
int bin[M], dp[M], sum[M];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>w;


	for (int i = 0; i < n; i++)	cin>>a[i],bin[1 << i]=i;

	// for (int i = 1;i < (1 << n); i++)
	// 	sum[i] = a[bin[i & -i]] + sum[i ^ (i & -i)],dp[i]=INF;	

	for (int i = 1; i < (1 << n); i++)
	{
		sum[i] = a[bin[i & -i]] + sum[i ^ (i & -i)],dp[i]=INF;	
		for (int j = i; j; j = (j - 1) & i)
			if (sum[j] <= w)
				dp[i] = min(dp[i], dp[i ^ j] + 1);
	}
	cout<< dp[(1 << n)-1]<<endl;
	return 0;
}