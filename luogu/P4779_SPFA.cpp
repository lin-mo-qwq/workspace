#include<bits/stdc++.h>
using namespace std;

int n,m,s;

struct edge 
{
	int to;
	int key;
};

int R[1000000];
bool vis[1000000];
const int INF=2147483647;
vector<edge> e[1000000]; 
struct cmp
{
	bool operator ()(int a,int b)
	{
		return R[a]>R[b];
	}
};

priority_queue<int,vector<int>,cmp> Q;

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

void SPFA(int s)
{
	R[s]=0;
	Q.push(s);
	while(!Q.empty())
	{
		int x=Q.top();
		Q.pop();
		vis[x]=0;
		for(int i=0;i<e[x].size();i++)
		{
			int v=e[x][i].to;
			if(R[v]>R[x]+e[x][i].key)
			{
				R[v]=R[x]+e[x][i].key;
				if(!vis[v])
					Q.push(v),vis[v]=1;
			}
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
	SPFA(s);
	print();
	return 0;
}