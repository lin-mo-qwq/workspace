#include<bits/stdc++.h>
using namespace std;

int n,a,b;
struct data
{
	int louceng;
	int frequency;
};
queue<data> q;
int ff[400];
bool vis[400];
int ret[400];

void inp()
{
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
		cin>>ret[i];
	q.push((data){a,0}),ff[a]=0,vis[a]=true;
}

void bfs()
{
	while(!q.empty())
	{
		data tf=q.front();
		q.pop();		
		if(tf.louceng-ret[tf.louceng]>=0&&!vis[tf.louceng-ret[tf.louceng]])
			q.push((data){tf.louceng-ret[tf.louceng],tf.frequency+1}),ff[tf.louceng-ret[tf.louceng]]=tf.frequency+1,vis[tf.louceng-ret[tf.louceng]]=true;
		if(tf.louceng+ret[tf.louceng]<=n&&!vis[tf.louceng+ret[tf.louceng]])
			q.push((data){tf.louceng+ret[tf.louceng],tf.frequency+1}),ff[tf.louceng+ret[tf.louceng]]=tf.frequency+1,vis[tf.louceng+ret[tf.louceng]]=true;
	}
}

int main()
{
	inp();
	bfs();	
	if(vis[b])
		cout<<ff[b]<<endl;
	else
		puts("-1");
	floor(10);
	return 0;
}