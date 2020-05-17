#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 9e13;

int n,m;
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >Q; 
bool vis[2000000];
int f[2000000],road[2000000];
vector<pair<int,int> > e[2000000];
 
void inp()
{
	int a,b,w;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>a>>b>>w,e[a].push_back(make_pair(b,w)),e[b].push_back(make_pair(a,w));
}
 
void memset()
{
	for(int i=1;i<=n;i++)
		f[i]=INF;
}
 
void dij(int s)
{
	f[s]=0;
	Q.push(make_pair(0,s));
	while(!Q.empty())
	{
		int x=Q.top().second;
		Q.pop(); 
		if(vis[x])
			continue;
		vis[x]=true;
		for(size_t i=0;i<e[x].size();i++)
		{
			int v=e[x][i].first;
			if(f[v]>f[x]+e[x][i].second)
			{
				f[v]=f[x]+e[x][i].second;
				Q.push(make_pair(f[v],v));
				road[v]=x;
			}
		}
	}
}
 
void work()
{
	memset();
	dij(1);
	if(f[n]==INF)
		cout<<~0<<' ';
	else
	{
		e[1].clear();
		e[1].push_back(make_pair(0,n));
		while(road[n] != 1) 
		{
			n = road[n];
			e[1].push_back(make_pair(0,n));
		}
		cout<<1<<' ';
		for(int i=e[1].size()-1;i>=0;i--)
			cout<<e[1][i].second<<' ';
	}
	puts("");
}
 
int main()
{
	inp();
	work();
	return 0;
}