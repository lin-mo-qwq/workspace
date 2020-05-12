#include<bits/stdc++.h>
using namespace std;

int n;
int a[100000];

void ins()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
}

int tx()
{
	int ans=0;
	for(int i=1;i<n;i++)
		if(a[i]>a[i-1])
			ans+=a[i]-a[i-1];
	return ans+a[0];
}

void work()
{
	ins();
	cout<<tx()<<endl;
}

int main()
{
	work();
	return 0;
}