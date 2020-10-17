#include <bits/stdc++.h>
using namespace std;
#define M (int)(2*1e6+5)

int n, m, a[M];
priority_queue < pair <int, int>, vector < pair <int , int> >, greater < pair<int, int> > > q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>a[1];
	printf("%d\n", 0);
	q.push(make_pair(a[1], 1));
	for(int i = 2; i <= n; i++)
	{	
		cin>>a[i];
		int x = q.top().second;
		while(i - m> x)
			q.pop(), x = q.top().second;
		printf("%d\n", q.top().first);
		q.push(make_pair(a[i], i));
	}
	return 0;
}