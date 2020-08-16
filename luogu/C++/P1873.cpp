#include<bits/stdc++.h>
using namespace std;

long long n,m,mx;
long long a[10000000];

void inp()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i],mx=max(mx,a[i]);
}

bool check(long long rss)
{
	long long ans=0;
	for(int i=0;i<n;i++)
		if(a[i]>rss)
			ans+=(a[i]-rss);
	if(ans>=m)
		return true;
	else
		return false;
}

void Binary(long long l,long long r)
{
	long long mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	cout<<r<<endl;
}

int main()
{
	inp();
	Binary(0,10000001);
	return 0;
}