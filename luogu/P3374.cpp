#include<bits/stdc++.h>
using namespace std;

#define lowbit(i) (i & -i)

int t[500005],n,m;

void modty(int x,int y)
{
	for(int i=x;i<=n;i+=lowbit(i))
		t[i]+=y;
}

int find(int x,int y)
{
	int ans=0;
	for(int i=y;i;i-=lowbit(i))
		ans+=t[i];


	for(int i=x-1;i;i-=lowbit(i))
		ans-=t[i];

	return ans;
}


int main()
{
	cin>>n>>m;

	for(int i=1,x;i<=n;i++)
		cin>>x,modty(i,x);

	while(m--)
	{
		int p,x,y;

		cin>>p>>x>>y;

		if(p==1)
			modty(x,y);
		else
			cout<<find(x,y)<<endl;
	}

	return 0;
}