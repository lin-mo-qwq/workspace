#include<bits/stdc++.h>
using namespace std;

int n,m,s;

struct edge 
{
	int to;
	int key;
	friend bool operator >(edge a,edge b)
	{
		if(a.key!=b.key)
			return a.key>b.key;
		return a.to>b.to;
	}
};

int R[1000000];
bool vis[1000000];
const int INF=2147483647;
vector<edge> e[1000000]; 
priority_queue<edge,vector<edge>,greater<edge> > Q;

void inp()
{
	int u,v,w;
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++)
		cin>>u>>v>>w,e[u].push_back((edge){v,w});
}

void memset()
{
	for(int i=1;i<=n;i++)
		R[i]=INF;	
}

void dij(int s)
{
	R[s]=0;
	Q.push((edge){s,0});
	while(!Q.empty())
	{
		int x=Q.top().to;
		Q.pop();
		if(vis[x])
			continue;
		vis[x]=true;
		for(int i=0;i<e[x].size();i++)
		{
			int v=e[x][i].to;
			if(R[v]>R[x]+e[x][i].key)
				R[v]=R[x]+e[x][i].key,Q.push((edge){v,R[v]});
		}
	}
}

void print()
{
	for(int i=1;i<=n;i++)
		cout<<R[i]<<' ';
}

int main()
{
	inp();
	memset();
	dij(s);
	print();
	return 0;
}