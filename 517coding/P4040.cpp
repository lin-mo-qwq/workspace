#include<bits/stdc++.h>
using namespace std;
int m;
map <string, map<string, int> > a;
int main()
{
	cin>>m;
	for(int i = 1, tmp; i <= m; i++) {
		string x, y;
		cin>>x>>y>>tmp;
		a[y][x] += tmp;
	}
	auto i = a.begin();
	for(auto i : a) {
		cout<<i.first<<endl;
		for(auto j : a[i.first])
			cout<<"   |----"<<j.first<<"("<<j.second<<")"<<endl;
	}
	return 0;
}  