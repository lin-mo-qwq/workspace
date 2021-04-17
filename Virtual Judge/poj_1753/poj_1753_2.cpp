#include<cstdio>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int ret = INF;
int dx[] = {0, 1, 0, -1, 0};
int dy[] = {0, 0, 1, 0, -1};
char mp[10][10];

void change(int dep)
{
	int x = dep / 4, y = dep % 4;
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



int main()
{
	for(int i = 0; i < 4; i++) scanf("%s", mp[i]);
	
	for(int mask = 0; mask < (1 << 16); mask++)
	{
		int used = 0;
		for(int i = 0; i < 16; i++)
			if(mask & (1 << i)) change(i), used++;	

		if(check()) ret = min(ret, used);

		for(int i = 0; i < 16; i++)
			if(mask & (1 << i)) change(i);
	}

	if(ret == INF) printf("Impossible\n");
	else printf("%d\n", ret);
	return 0;
}