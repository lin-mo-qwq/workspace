#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define INF 2147483647

struct edge
{
	int to;
	long long key;
	friend bool operator >(edge a, edge b)
	{
		if(a.key!=b.key)
			return a.key>b.key;
		return a.to > b.to;
	}
		
};

long long n, m, ans;
long long ris[M], vis[M];
vector <edge> e[M], f[M];
priority_queue <edge, vector <edge>, greater <edge> > Q;

void inp()
{
	int u, v, w;
	cin>>n>>m;
	for(int i = 1; i <= m; i++)
		cin>>u>>v>>w, e[u].push_back((edge){v, w}), f[v].push_back((edge){u, w});
}

void memset()
{
	for(int i = 1; i <= n; ++i) 
		ris[i] = INF;
}

void dij(int s)
{
	memset(), ris[s] = 0;
	Q.push((edge){s, 0});
	while (!Q.empty())
	{
		int x = Q.top().to;	Q.pop();
		if(vis[x])
			continue;
		vis[x] = 1;
		for(int i = 0; i < e[x].size(); i++)
		{
			int v = e[x][i].to;
			if(ris[v] > ris[x] + e[x][i].key)
				ris[v] = ris[x] + e[x][i].key, Q.push((edge){v, ris[v]});
		}
	}
}

void fdij(int s)
{
	memset(vis, 0, sizeof(vis));
	memset(), ris[s] = 0;
	Q.push((edge){s, 0});
	while (!Q.empty())
	{
		int x = Q.top().to;	Q.pop();
		if(vis[x])
			continue;
		vis[x] = 1;
		for(int i = 0; i < f[x].size(); i++)
		{
			int v = f[x][i].to;
			if(ris[v] > ris[x] + f[x][i].key)
				ris[v] = ris[x] + f[x][i].key, Q.push((edge){v, ris[v]});
		}
	}
}

int main()
{
	inp();
	dij(1);
	for(int i = 2; i <= n; i++) ans += ris[i];
	fdij(1);
	for(int i = 2; i <= n; i++) ans += ris[i];
	cout<<ans<<endl;
	return 0;
} 