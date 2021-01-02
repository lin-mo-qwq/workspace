#include<bits/stdc++.h>
using namespace std;
const int M = 100005;
#define _mp(a, b) make_pair((a), (b))
int n, a[M], b[M], cnt = 1, i, nxt[M];
priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int,int> > > q;
int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i];
	for(int i = 1; i <= n; i++) cin>>b[i], nxt[i] = 1, q.push(_mp(a[1] + b[i], i));
	while(n--)
	{
		cout<<q.top().first<<' ';
		i = q.top().second, q.pop();
		q.push(_mp(b[i] + a[++nxt[i]], i));
	}
	return 0;
}