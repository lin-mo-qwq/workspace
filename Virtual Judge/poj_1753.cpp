#include<cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
int ret = INF;
int dx[] = {0, 1, 0, -1, 0};
int dy[] = {0, 0, 1, 0, -1};
char mp[10][10];

void change(int x, int y)
{
	for(int i = 0; i < 5; i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(tx >= 0 && tx < 4 && ty >= 0 && ty < 4)
		{
			if(mp[tx][ty] == 'w') mp[tx][ty] = 'b';
			else mp[tx][ty] = 'w';
		}
	}
}

bool check()
{
	char x = mp[0][0];
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			if(x != mp[i][j]) return false;
	return true;
}

void dfs(int dep, int used)
{
	if(dep == 16)
	{
		if(check() && used < ret) 
			ret = used;
		return ;
	}

	dfs(dep + 1, used);

	int x = dep / 4, y = dep % 4;	
	change(x, y);
	dfs(dep + 1, used + 1);
	change(x, y);
}

int main()
{
	for(int i = 0; i < 4; i++) 
		scanf("%s", mp[i]);

	dfs(0, 0);

	if(ret == INF) printf("Impossible\n");
	else printf("%d\n", ret);
	return 0;
}