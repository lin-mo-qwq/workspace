#include<bits/stdc++.h>
using namespace std;
#define chan(x) x += 2
int ctrl[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
unsigned long long  hx, hy, bx, by, f[30][30], vis[30][30];
int main()
{
	f[2][2] = 1;
	cin>>bx>>by>>hx>>hy;
	chan(bx), chan(by), chan(hx), chan(hy);
	for(int i = 0; i < 8; i++)
		vis[hx + ctrl[i][0]][hy + ctrl[i][1]] = 1;
	vis[hx][hy] = 1;
	for(int i = 2; i <= bx; i++)
		for(int j = 2; j <= by; j++)
			if(!vis[i][j])
				f[i][j] = max(f[i][j], f[i - 1][j] + f[i][j - 1]);
	cout<<f[bx][by]<<endl;
	return 0;
}