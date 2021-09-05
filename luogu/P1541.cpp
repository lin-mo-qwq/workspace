#include<bits/stdc++.h>
using namespace std;

int n,m,direction[1000];
int p[5],card[45][45][45][45];
bool vis[45][45][45][45];

void inp()
{
	int n,m;
	
	cin>>n>>m;

	for(int i=1; i<=n ; i++)
		cin>>direction[i];
	for(int i=1,x; i<=m;i++)
		cin>>x,p[x]++;

}


int dp(int a,int b,int c,int d)
{
	if(a==0&&b==0&&c==0&&d==0) return direction[1];
	
	if(vis[a][b][c][d]) return card[a][b][c][d];

	int nowdirection=a+2*b+3*c+4*d;

	if(a)
		card[a][b][c][d]=max(dp(a-1,b,c,d),card[a][b][c][d]);
	if(b)
		card[a][b][c][d]=max(dp(a,b-1,c,d),card[a][b][c][d]);
	if(c)
		card[a][b][c][d]=max(dp(a,b,c-1,d),card[a][b][c][d]);
	if(d)
		card[a][b][c][d]=max(dp(a,b,c,d-1),card[a][b][c][d]);

	card[a][b][c][d]+=direction[1+nowdirection];
	vis[a][b][c][d]=1;
	return card[a][b][c][d];
}

int main()
{
	inp();
	cout<<dp(p[1],p[2],p[3],p[4])<<endl;
	return 0;
}