#include<bits/stdc++.h>
using namespace std;

int n,m,p[1005],ansm,ansn;

// bool cmp(int x,int y)
// {
// 	return x>y;
// }

int main()
{
	cin>>n>>m;

	for(int i=1;i<=m;i++)
		cin>>p[i];

	sort(p+1,p+1+m);

	for(int i=m;i>=1;i--)
		if(p[i]*(m-i+1)>ansm)
			ansm=p[i]*(m-i+1),ansn=p[i];

	cout<<ansn<<' '<<ansm<<endl;
	return 0;
}
