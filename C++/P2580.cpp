#include<bits/stdc++.h>
using namespace std;

map<string,int> name;

void inp()
{
	int n;
	string x;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>x,name[x]=1;	
}

void work()
{
	int n;
	string x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(name[x]==1)
		{
			cout<<"OK";name[x]=114514;
		}
		else if(name[x]==114514)
			cout<<"REPEAT";
		else
			cout<<"WRONG";
		puts("");
	}

}

int main()
{
	inp();
	work();
	return 0;
}