#include<bits/stdc++.h>
using namespace std;

long long s,x,rss;

int main()
{
	while(~scanf("%lld",&x))	s+=x,rss++;
	cout<<(long long) (s*pow(2,rss-1));
	return 0;
}