#include<bits/stdc++.h>
using namespace std;

int num,n;

void print(int x,int rss)
{
	for(int i=0;i<x;i++)
		cout<<rss,num++,(num==n)?cout<<endl,num=0:num=num;
}

void work()
{
	cin>>n;
	for(int i=0,x;cin>>x;i++)
		print(x,i%2);
}

int main()
{
	work();
	return 0;
}