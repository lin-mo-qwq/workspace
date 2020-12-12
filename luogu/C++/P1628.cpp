#include<bits/stdc++.h>
using namespace std;
#define Min lower_bound(strmap.begin(), strmap.end(), t)
int n; string t;
vector<string> strmap;
int main()
{
	cin>>n; string tmp, now;
	for(int i = 1; i <= n; i++) 
		cin>>tmp, strmap.push_back(tmp);
	cin>>t;
	sort(strmap.begin(), strmap.end());
	for(auto i = Min; (i == Min) || (now.find(t) == 0); i++, now = *i)
	{
		cout<<*i<<endl;
		if(i == strmap.end()) break;
	}
	return 0;
}