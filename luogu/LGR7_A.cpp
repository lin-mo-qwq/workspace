#include<bits/stdc++.h>
using namespace std;
int main()
{
	int ans=0;
	double n,m;
	cin>>n>>m;
	for(int i=1;pow(i,m)<=n;i++)
		ans++;
	cout<<ans;
	return 0;
}