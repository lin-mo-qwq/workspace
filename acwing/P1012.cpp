#include<bits/stdc++.h>
using namespace std;

int n, f[5010], ans;
vector <pair<int, int> > ret;

int main()
{
	cin>>n;

	for(int i = 1, a, b; i <= n; i++) 
		cin>>a>>b, ret.push_back(make_pair(a, b)), f[i] = 1;

	sort(ret.begin(), ret.end());

	for(int i = 0; i < n; i++)
		for(int j = 1; j < i; j++)
			if(ret[i].second > ret[j].second)
				f[i] = max(f[i], f[j] + 1);
	
	for(int i = 0; i < n; i++)	ans = max(ans, f[i]);	
	
	cout<<ans<<endl;
	return 0;
}