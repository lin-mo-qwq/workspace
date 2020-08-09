#include<bits/stdc++.h>
using namespace std;

int n;
priority_queue < int > big;
priority_queue <int, vector<int>, greater<int> > small;

int main()
{
	cin>>n;
	for(int i=1,x;i<=n;i++)
		cin>>x,big.push(x),small.push(x);
	
	int cnt = 0;

	while(cnt<n)
	{
		cout<<big.top()<<endl,big.pop(),cnt++;
		if(cnt==n)
			break;
		cout<<small.top()<<endl,small.pop(),cnt++;
	}
	return 0;
}