#include<bits/stdc++.h>
using namespace std;

int ans,n;
int p[9];
map<int,int> num;

void inp()
{
	cin>>n;
	for(int i=0,x;i<7;i++)
			cin>>x,num[x]=1;
	for(int j=0;j<n;j++)
	{
		ans=0;
		for(int i=0,rss=0,x;i<7;i++)
			cin>>x,num.count(x)?rss++:rss=rss,ans=max(ans,rss);
		p[ans]++;
	}
}

void print()
{
	for(int i=7;i>=1;i--)
		cout<<p[i]<<" ";		 
}	

int main()
{
	inp();
	print();
	return 0;
}