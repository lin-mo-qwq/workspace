#include<bits/stdc++.h>
using namespace std;

int n,m,ansl,ansr,qlen=1000005;
map <int,int> master;
int d[1000005];


void assign(int l,int r,int len)
{
	if(qlen>len)
		qlen=len,ansl=l,ansr=r;
}

int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>m;

	for(int i=1;i<=n;i++)
		cin>>d[i];

	master[d[1]]=1;
	int l=1,r=1,ms=1;

	while(l<=r && r<=n)
	{
		if(ms==m)
		{
			assign(l,r,r-l+1),l++;
			master[d[l-1]]--;
			if(master[d[l-1]]==0)
				ms--;
		}
		else
		{
			r++;
			master[d[r]]++;
			if(master[d[r]]==1)
				ms++;
		}
	}
	cout<<ansl<<' '<<ansr;
 	return 0;
}