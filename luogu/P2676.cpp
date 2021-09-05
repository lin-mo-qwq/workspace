#include<bits/stdc++.h>
using namespace std;

int n,b;
int h[50000];

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int ans=0,cnt=0;
	cin>>n>>b;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	sort(h+1,h+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		cnt+=h[i],ans++;
		if(cnt>=b)
			cout<<ans<<endl,exit(0);
	}
	return 0;
}