#include <iostream>
using namespace std;
#define MAXN 1001
 
int N;
bool A[MAXN][MAXN];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
 
bool valid_position(int x,int y)
{
	return x>=0 && x<=N && y>=0 && y<=N;
}
 
bool comfortable(int x,int y)
{
	if(A[x][y] == 0) return 0;
	int neighbors = 0;
	for(int d=0;d<4;d++)
		if(valid_position(x+dx[d],y+dy[d]))
			if(A[x+dx[d]][y+dy[d]])
				neighbors++;
	return neighbors == 3;
}
 
int main()
{
	int x,y;
	cin >> N;
	int nComfortable = 0;
	for(int i=0;i<N;i++)
	{
		cin >> x >> y;
		for(int d=0;d<4;d++)
			if(valid_position(x+dx[d],y+dy[d]))
				nComfortable -= comfortable(x+dx[d],y+dy[d]);
		A[x][y] = 1;
		for(int d=0;d<4;d++)
			if(valid_position(x+dx[d],y+dy[d]))
				nComfortable += comfortable(x+dx[d],y+dy[d]);
		nComfortable += comfortable(x,y);
		cout << nComfortable << '\n';
	}
}