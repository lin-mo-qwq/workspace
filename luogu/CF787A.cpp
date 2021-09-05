#include<bits/stdc++.h>
using namespace std;

int a,b,c,d;

int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}

int main()
{
	cin>>a>>b>>c>>d;
 
	if((d-b)%gcd(a,c))
		puts("-1"),exit(0);

	while(b!=d)
	{
		if(b<d)
			b+=a;
		if(b>d)
			d+=c;
	}

	cout<<b<<endl;
	return 0;
}