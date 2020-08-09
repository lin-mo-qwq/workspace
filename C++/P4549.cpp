#include<bits/stdc++.h>
using namespace std;

int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}

int main()
{
	int n,ans=0;
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin>>x;

		if(x<0)
			x=0-x;
			
		ans=gcd(ans,x);
	}
	cout<<ans<<endl;
	return 0;
}