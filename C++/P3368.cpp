#include<bits/stdc++.h>
using namespace std;

#define lowbit(i) (i & -i)

int t[10005],n,m;

void add(int l,int y)
{
	for(int i=l;i<=n;i+=lowbit(i))
		t[i]+=y;
}

int search(int x)
{
	static int ans=0;


	for(int i=x;i;i-=lowbit(i))
		ans+=t[i];

	return ans;
}	

int main()
{
	cin>>n>>m;

	for(int i=1,x,past=0;i<=n;i++)
		cin>>x,add(i,x-past),past=x;

	for(int i=1,op;i<=m;i++)
	{
		cin>>op;

		if(op==1)
		{
			static int x,y,k;

			cin>>x>>y>>k;

			add(y+1,-k),add(x,k);
		}

		else
		{
			static int x;
			
			cin>>x;

			cout<<search(x)<<endl;
		}
	}

	return 0;
}
