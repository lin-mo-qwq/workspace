#include<bits/stdc++.h>
using namespace std;
int w,x,h,q,x1,g1,x2,y2,z1,z2,ans;
int cft[21][21][21];
int main()
{
	cin>>w>>x>>h;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>x1>>g1>>z1>>x2>>y2>>z2;
		for(int i=x1;i<=x2;i++)
			for(int j=g1;j<=y2;j++)
				for(int k=z1;k<=z2;k++)
					cft[i][j][k]=1;
	}
	for(int i=1;i<=w;i++)
		for(int j=1;j<=x;j++)
			for(int k=1;k<=h;k++)
				if(!cft[i][j][k])
					ans++;
	cout<<ans<<endl;
	return 0;
}
