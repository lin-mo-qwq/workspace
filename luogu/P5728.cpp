#include<bits/stdc++.h>
using namespace std;

struct student
{
	int c;
	int m;
	int e;
	int s;
	
	void calc()
	{
		s=c+m+e;
	}

} s[1005];

int n,ans;

void inp()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].c>>s[i].m>>s[i].e;
		s[i].calc();
	}
}

bool cmp(student a,student b)
{
	if(abs(a.c-b.c)<=5&&abs(a.m-b.m)<=5&&abs(a.e-b.e)<=5&&abs(a.s-b.s)<=10)
		return true;
	return false;
}

void work()
{
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			cmp(s[i],s[j])?ans++:ans+=0;
}

int main()
{
	inp();
	work();
	cout<<ans<<endl;
	return 0;
}