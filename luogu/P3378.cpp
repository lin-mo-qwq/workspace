#include<bits/stdc++.h>
using namespace std;

priority_queue<int ,vector<int> ,greater<int> > Q;

void work()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int op,x;
		cin>>op;
		if(op==1)
			cin>>x,Q.push(x);
		if(op==2)
			cout<<Q.top()<<endl;
		if(op==3)
			Q.pop();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	work();
	return 0;
}