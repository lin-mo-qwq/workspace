#include<bits/stdc++.h>
using namespace std;

#define lowbit(i) (i & -i)

#define ll long long

ll a[500005],t[500005],n,m;

void add(int l,int y)
{
	for(int i=l;i;i-=lowbit(i))
		t[i]+=y;
}

ll search(int x)
{
	if(x==0)
		return 0;	
	ll ans=0;

	for(int i=x;i<=n;i+=lowbit(i))
		ans+=t[i];

	return ans;
}	

int main()
{
	cin>>n>>m;

	for(int i=1;i<=n;i++)
		cin>>a[i];

	for(int i=1,op;i<=m;i++)
	{
		cin>>op;

		if(op==1)
		{
			int x,y,k;

			cin>>x>>y>>k;

			add(y,k),add(x-1,-k);
		}

		else
		{
			int x;
			
			cin>>x;

			cout<<a[x]+search(x)<<endl;
		}
	}

	return 0;
}
