#include<bits/stdc++.h>
using namespace std;
int r, c, ret[105][105], len[105][105], ans;

int max_len(int i, int j)
{
	if(len[i][j] > 1) return len[i][j]; 
	if(ret[i][j + 1] < ret[i][j]) 
		len[i][j] = max(len[i][j], max_len(i, j + 1) + 1);
	if(ret[i][j - 1] < ret[i][j]) 
		len[i][j] = max(len[i][j], max_len(i, j - 1) + 1);
	if(ret[i + 1][j] < ret[i][j]) 
		len[i][j] = max(len[i][j], max_len(i + 1, j) + 1);
	if(ret[i - 1][j] < ret[i][j]) 
		len[i][j] = max(len[i][j], max_len(i - 1, j) + 1);
	return len[i][j];
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