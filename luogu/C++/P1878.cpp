#include<bits/stdc++.h>
using namespace std;
#define mp(x, y) make_pair(x, y)
#define M 1000001
bool vis[M];
int a[M], f[M], n;
struct ground
{
	int x, y, key;
	friend bool operator > (ground x, ground y)
	{	
		if(x.key == y.key) return x.x > y.x;
		else return x.key > y.key;
	}
};
vector <pair<int, int>> ans;
priority_queue <ground, vector<ground>, greater<ground>> q;
void work()
{
	while(!q.empty())
	{
		int x = q.top().x, y = q.top().y;
		q.pop();
		if(vis[x] || vis[y]) continue; 
		vis[x] = vis[y] = true;
		ans.push_back(mp(x, y));
		while(x > 0 && vis[x]) x--;
		while(y <= n && vis[y]) y++;
		if(x > 0 && y <= n && f[x] != f[y]) 
			q.push((ground){x, y, abs(a[x] - a[y])});
	}
}
int main()
{
	char tmp;
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>tmp, f[i] = tmp;
	for(int i = 1; i <= n; i++) cin>>a[i];
	for(int i = 1; i < n; i++)
		if(f[i] != f[i + 1]) q.push((ground){i, i + 1, abs(a[i] - a[i + 1])});
	work();
	cout<<ans.size()<<endl;
	for(auto i:ans)
		cout<<i.first<<' '<<i.second<<endl;
	return 0;
}