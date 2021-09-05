#include<bits/stdc++.h>
using namespace std;

struct toy
{
	bool direction;
	string name;
} Man[100005];

int n,m;
int ans=0;

void inp()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>Man[i].direction>>Man[i].name;
}


void work()
{
	bool direction;
	int next;
	for(int i=1;i<=m;i++)
	{
		cin>>direction>>next;
		if(direction xor Man[ans].direction)
			ans=(ans+next)%n;
		else
			ans=(ans+n-next)%n;
	}
}

int main()
{
	inp();
	work();
	cout<<Man[ans].name<<endl;
	return 0;
}