#include<bits\stdc++.h>
using namespace std;

bool flag=0;

void bing_bao(int x)
{
	if(x==1)
	{
		cout<<1<<' ',flag=1;
		return ;
	}
	if(x&1)
		bing_bao(x*3+1);
	else
		bing_bao(x/2);
	if(flag)
		cout<<x<<' ';
}

int main()
{
	int x;
	cin>>x;

	bing_bao(x);
	puts("");
	return 0;
}