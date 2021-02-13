#include<bits/stdc++.h>
using namespace std;
#define M (int)(1e5 * 2 + 5)
int n, m, a[M];
priority_queue<int> q_max;
priority_queue<int, vector<int>, greater<int> > q_min;
int main()
{
	cin>>n>>m;

	for(int i = 1; i <= n; i++) cin>>a[i];
	for(int i = 1, tmp, j = 1; i <= m; i++)
	{
		cin>>tmp; 
		while (j <= tmp)
		{
			q_max.push(a[j]);
			if(q_max.size() == i) 
				q_min.push(q_max.top()), q_max.pop();
			j++;
		}
		cout<<q_min.top()<<endl;
		q_max.push(q_min.top()), q_min.pop();
	}
	return 0;
}