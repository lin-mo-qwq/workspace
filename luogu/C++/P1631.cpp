#include<bits/stdc++.h>
using namespace std;
#define M (int)(1e5 * 2 + 5)
int n, m, a[M];
priority_queue<int> qmax;
priority_queue<int, vector<int>, greater<int> > qmin;
int main()
{
	cin>>n>>m;

	for(int i = 1; i <= n; i++) cin>>a[i];
	for(int i = 1, tmp, j = 1; i <= m; i++)
	{
		cin>>tmp; 
		while (j <= tmp)
		{
			qmax.push(a[j]);
			if(qmax.size() == i) 
				qmin.push(qmax.top()), qmax.pop();
			j++;
		}
		cout<<qmin.top()<<endl;
		qmax.push(qmin.top()), qmin.pop();
	}
	return 0;
}