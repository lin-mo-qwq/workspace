#include<bits/stdc++.h>
using namespace std;
int k, n, f[105], a[105], ans;
int main()
{
	cin>>k;
	while(k--)
	{
		ans = 0; 
		cin>>n;
		for(int i = 1; i <= n; i++)	cin>>a[i], f[i] = 1;
		
		for(int i = 1; i <= n; i++)
			for(int j = 1; j < i; j++)
				if(a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
		for(int i = 1; i <= n; i++)	ans = max(ans, f[i]);
		
		for(int i = n; i >= 1; i--)
		{
			f[i] = 1;
			for(int j = n; j > i; j--)
				if(a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
		}
		for(int i = 1; i <= n; i++)	ans = max(ans, f[i]);
		
		cout<<ans<<endl;
	}
	return 0;
}