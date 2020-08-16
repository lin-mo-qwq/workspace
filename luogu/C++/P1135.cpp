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
int giao[400];

void inp()
{
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
		cin>>giao[i];
	q.push((data){a,0}),ff[a]=0,vis[a]=true;
}

void bfs()
{
	while(!q.empty())
	{
		data tf=q.front();
		q.pop();		
		if(tf.louceng-giao[tf.louceng]>=0&&!vis[tf.louceng-giao[tf.louceng]])
			q.push((data){tf.louceng-giao[tf.louceng],tf.frequency+1}),ff[tf.louceng-giao[tf.louceng]]=tf.frequency+1,vis[tf.louceng-giao[tf.louceng]]=true;
		if(tf.louceng+giao[tf.louceng]<=n&&!vis[tf.louceng+giao[tf.louceng]])
			q.push((data){tf.louceng+giao[tf.louceng],tf.frequency+1}),ff[tf.louceng+giao[tf.louceng]]=tf.frequency+1,vis[tf.louceng+giao[tf.louceng]]=true;
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