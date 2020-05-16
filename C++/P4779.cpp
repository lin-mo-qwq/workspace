#include<bits/stdc++.h>
using namespace std;

long n,m,s;
priority_queue<pair<long,long>, vector<pair<long,long> >, greater<pair<long,long> > >Q; 
bool vis[1000000];
long f[1000000];
vector<pair<long,long> > e[2000000];

void inp()
{
	long a,b,w;
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++)
		cin>>a>>b>>w,e[a].push_back(make_pair(b,w));
}

void memset()
{
	for(int i=1;i<=n;i++)
		f[i]=2147483647;
}

void dij(int s)
{
	f[s]=0;
	Q.push(make_pair(0,s));
	while(!Q.empty())
	{
		long x=Q.top().second;
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
			}
		}
	}
}

void work()
{
	memset();
	dij(s);
	for(int i=1;i<=n;i++)
		cout<<f[i]<<' ';
}

int main()
{
	inp();
	work();
	return 0;
}
