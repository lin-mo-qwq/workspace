#include<bits/stdc++.h>
using namespace std;

int ans,n,k,a[100005];
vector <int> f;

int main()
{
	cin>>n>>k;
	
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	sort(a+1,a+1+n);
	
	for(int i=1;i<n;i++)
		f.push_back(a[i+1]-a[i]);

	sort(f.begin(),f.end());

	for(int i=0;i<k;i++)
		ans+=f[i];

	cout<<ans<<endl;

	return 0;
}