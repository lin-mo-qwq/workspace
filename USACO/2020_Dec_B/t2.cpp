#include<bits/stdc++.h>
using namespace std;
int n, sum[105], ret[105];
int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>ret[i], sum[i] = sum[i - 1] + ret[i];
	
	int cnt = 0;

	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++)
		{
			double p = (double)(sum[j] - sum[i - 1]) / (j - i + 1);
			for(int k = i; k <= j; k++)
				if((double)ret[k] == p) 
				{
					cnt++; 
					break;
				}
		}
	
	cout<<cnt<<endl;
	return 0;
}