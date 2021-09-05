#include<bits/stdc++.h>
using namespace std;

int n,c,x[100005];

bool check(int y)
{
	int cnt=0,l=x[1];
	for(int i=2;i<=n;i++)
	{
		if(x[i]-l<y) cnt++;
		else l=x[i];
		if(cnt>n-c)
			return 0;
	}
	return 1;
}

void rf()
{	
	int l=1,r=x[n]-x[1];
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(check(mid))
			l=mid;
		else
			r=mid;
	}
	if(check(l))
		cout<<l<<endl;
	else
		cout<<r<<endl;
}

void inp()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++)
		cin>>x[i];
}

int main()
{
	inp();
	sort(x+1,x+1+n);
	rf();
	return 0;
}