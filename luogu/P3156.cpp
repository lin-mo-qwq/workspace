#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> student; 

void inp()
{
	student.push_back(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		student.push_back(x);
	}
}

void work()
{
	for(int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		cout<<student[x]<<endl;
	}
}

int main()
{
	inp();
	work();
	return 0;
}