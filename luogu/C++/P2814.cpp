#include<bits/stdc++.h>
using namespace std;
map<string, string> dad;

string anc(string x)
{
	if(x != dad[x] && dad[x] != "") return dad[x] = anc(dad[x]);
	return x;
}

void uni(string x, string y)
{
	x = anc(x), y = anc(y);
	if(x != y)	dad[x] = y;
}

int main()
{
	char opt; 
	string tmp, father;
	while(cin>>opt>>tmp)
	{
		if(opt == '#') father = tmp;
		else if(opt == '+') uni(tmp, father);
		else cout<<tmp<<' '<<anc(tmp)<<endl;	
	}
	return 0;
}