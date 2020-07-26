#include<bits/stdc++.h>
using namespace std;

#define mod 998244353

int ans;
int n,a[200005];
int vis[200005];

int work(int x)
{
	if(x==1)
		return 1;
	return (x+1)*x/2;
}	


int main()
{
	cin>>n;

	for(int i=1;i<=n;i++)
		cin>>a[i],vis[a[i]]++;

	sort(a+1,a+1+n);

	int len=unique(a+1,a+1+n)-a-1;

	if(len==1)
	{
		for(int i=n-2;i>=1;i--)
			ans+=work(i);
	}

	for(int i=1;i<len;i++)
		for(int j=1;j<=len;j++)
		{
			if(i==j)
				continue;
			
			if(vis[a[i]]>=2&&a[i]*2<=a[j])
				continue;

			
			ans+=vis[a[i]]/2*vis[a[j]];

			if(vis[a[i]]&1&&vis[a[i]]!=1)
				ans+=vis[a[i]]/2*vis[a[j]];
		}

	cout<<ans<<endl;
	return 0;
}