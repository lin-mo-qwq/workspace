#include<bits/stdc++.h>
using namespace std;

int n,a[200000];

void inp()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
}

void work()
{
	int average=0,ans=0;

	for(int i=1;i<=n;i++)
		average+=a[i];

	average/=n;

	for(int i=1;i<=n;i++)
		a[i]-=average;

	for(int i=1;i<n;i++)
	{
		if(a[i])
		{
			a[i+1]+=a[i];
			a[i]=0;
			ans++;
		}
	}

	printf("%d\n",ans);
}

int main()
{
	inp();
	work();
	return 0;
}