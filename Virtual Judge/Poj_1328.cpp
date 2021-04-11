#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;

const int M = 1e4 + 5;
int n, d, tmp;

struct seg
{
	double l, r;
	friend bool operator < (seg a, seg b)
	{
		return a.r < b.r;
	}
} ln[M];

int main()
{
	while(~scanf("%d%d", &n, &d))
	{
		int flag = 0, cnt = 0, ans = 1;
		if(n == d && !d) break;
		
		for(int i = 1; i <= n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if(abs(y) > d) 
			{
				flag = 1;
				continue;
			}
			double tmp = sqrt(pow((float)d, 2) - pow((float)y, 2));
			ln[++cnt] = {x - tmp, x + tmp};
		}

		if(flag)
		{
			puts("-1"); 
			continue;
		}

		sort(ln + 1, ln + 1 + cnt);
		
		double R = ln[1].r;
		for(int i = 2; i <= cnt; i++)
			if(R < ln[i].l) ans++, R = ln[i].r;

		printf("Case %d: %d\n", ++tmp, ans);
	}
		
	return 0;
}