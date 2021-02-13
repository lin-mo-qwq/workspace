#include<bits/stdc++.h>
using namespace std;
#define M 105
double sum[M], a[M], n, ans;
int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i], sum[i] = sum[i - 1] + a[i];
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
			double p = (sum[j] - sum[i - 1]) / (j - i + 1);
			for(int k = i; k <= j; k++)
				if(a[k] == p) 
				{
					ans++;
					break;
				}
		}
	}
	cout<<ans<<endl;
	return 0;
}