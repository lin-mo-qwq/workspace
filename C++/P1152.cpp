#include<bits/stdc++.h>
using namespace std;

int n;
int a[2000];
int rss[2000];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)	
		rss[i]=abs(a[i+1]-a[i]);
	sort(rss+1,rss+1+n);
	for(int i=1;i<n;i++)
		if(rss[i]!=i)
			puts("Not jolly"),exit(0);
	puts("Jolly");
	return 0;
}