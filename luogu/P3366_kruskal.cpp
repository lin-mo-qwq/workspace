#include<bits/stdc++.h>
using namespace std;

struct edge
{
	int from;
	int to;
	int key;
	friend bool operator < (edge a,edge b)
	{
		return a.key<b.key;
	}
};

vector<edge> E;
int dad[10000];
int n,m,ans,cnt;

int anc(int x)
{
	if(x!=dad[x]) return dad[x]=anc(dad[x]);
	return x;
}

void uni(int x,int y)
{
	x=anc(x),y=anc(y);
	if(x!=y)
		dad[x]=y;
}

bool ask(int x,int y)
{
	return anc(x)==anc(y);
}

void inp()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		E.push_back((edge){x,y,z});
	}
}

void memset()
{
	for(int i=1;i<=n;i++)
		dad[i]=i;
}

void kruskal()
{
	sort(E.begin(),E.end());
	for(int i=0;i<m;i++)
	{
		if(ask(E[i].from,E[i].to)) continue;
		uni(E[i].from,E[i].to);
		ans+=E[i].key,cnt++;
		if(cnt==n-1)
			break;
	}
}

int main()
{
	inp();
	memset();
	kruskal();
	if(cnt==n-1)
		cout<<ans<<endl;
	else
		puts("orz");
	return 0;
}