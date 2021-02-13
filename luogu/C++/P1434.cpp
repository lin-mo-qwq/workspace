#include<bits/stdc++.h>
using namespace std;
int r, c, ret[105][105], len[105][105], ans;

int max_len(int x, int y)
{
	if(len[x][y] > 1) return len[x][y]; 
	if(ret[x][y + 1] < ret[x][y]) 
		len[x][y] = max(len[x][y], max_len(x, y + 1) + 1);
	if(ret[x][y - 1] < ret[x][y]) 
		len[x][y] = max(len[x][y], max_len(x, y - 1) + 1);
	if(ret[x + 1][y] < ret[x][y]) 
		len[x][y] = max(len[x][y], max_len(x + 1, y) + 1);
	if(ret[x - 1][y] < ret[x][y]) 
		len[x][y] = max(len[x][y], max_len(x - 1, y) + 1);
	return len[x][y];
}

int main()
{
	cin>>r>>c;
	memset(ret, 0x7f, sizeof(ret));
	for(int i = 1, tmp = 0; i <= r; i++)
		for(int j = 1; j <= c; j++)
			cin>>ret[i][j], len[i][j] = 1;
	for(int i = 1; i <= r; i++)
		for(int j = 1; j <= c; j++)
			ans = max(ans, max_len(i, j));
	cout<<ans<<endl;
	return 0;
}