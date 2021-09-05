#include<bits/stdc++.h>
using namespace std;

struct NODE
{
	int wss[105];
	int name[105];
	int ans;

	void print()
	{
		cout<<ans<<' ';
		
		for(int i=1;i<=ans;i++)
			cout<<name[i]<<' ';
	
		puts("");
	}

} nod;

queue <NODE> q;
int v,g,cv[35],sv[30][30];

void inp()
{
	cin>>v;

	for (int i=1;i<=v;i++)
		cin>>cv[i];

	cin>>g;

	for (int i=1;i<=g;i++)
		for (int j=1;j<=v;j++)
			cin>>sv[i][j];
}

bool check(NODE x)
{
	for (int i=1;i<=v;i++)
		if(x.wss[i]<cv[i])
			return false;

	return true;
}

void memset()
{
	for (int i=1;i<=g;i++)
	{	
		for (int j=1; j<=v; j++)
			nod.wss[j]=sv[i][j];

		nod.ans=1;
		nod.name[nod.ans]=i;
		q.push(nod);
	}
}


void BFS()
{

	memset();

	while (!q.empty())
	{
		NODE t=q.front(),s=t;
		q.pop();

		if (check(s))
			s.print(),exit(0);
		
		else
			for(int i=s.name[s.ans]+1;i<=g;i++)
			{

				for(int j=1;j<=v;j++)
					t.wss[j]=s.wss[j]+sv[i][j];

				t.ans=s.ans+1;
				t.name[t.ans]=i;

				q.push(t);			
			}			
	
	}
}

int main()
{
	inp();
	BFS();
	return 0;
}