#include<bits/stdc++.h>
using namespace std;
#define M 100
int h, n, d[M], t[M], ans = -1;
struct fish
{
	int num, key;
	friend bool operator < (fish a, fish b)
	{
		return a.key < b.key;
	}
} lake[M]; 
priority_queue <fish> q;
int main()
{
	cin>>n>>h; h *= 12;
	for(int i = 1; i <= n; i++) 
		cin>>lake[i].key, lake[i].num = i;
	for(int i = 1; i <= n; i++) cin>>d[i];
	for(int i = 1; i < n; i++) cin>>t[i];
	for(int i = 1, tmp; i <= n; i++)
	{
		h -= t[i - 1]; tmp = 0;
		while(!q.empty()) q.pop();
		for(int j = 1; j <= i; j++) q.push(lake[j]);
		for(int j = 1; j <= h; j++)
		{
			fish s = q.top();
			if(s.key > 0) tmp += s.key;
			s.key -= d[s.num];
			q.pop(); q.push(s);
		}
		ans = max(ans, tmp);	
	}
	cout<<ans<<endl;
	return 0;
}