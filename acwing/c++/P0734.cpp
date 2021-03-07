#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, f[N];
struct Stone 
{
	int s, e, l;
	bool operator < (const Stone &w) const
	{
		return s * w.l < l * w.s;
	}
} stone[N];

int main(void)
{
	int T;
	scanf("%d", &T);

	for(int C = 1; C <= T; C++)
	{
		int m = 0;
		scanf("%d", &n);

		for(int i = 1; i <= n; i++)
		{
			int s, e, l;
			scanf("%d%d%d", &s, &e, &l);
			stone[i] = {s, e, l}, m += s;
		}	

		sort(stone + 1, stone + 1 + n);
		memset(f, -0x3f, sizeof(f));
		f[0] = 0;

		for(int i = 1; i <= n; i++)
		{
			int s = stone[i].s, e = stone[i].e, l = stone[i].l;	
			for(int j = m; j >= s; j--) 
				f[j] = max(f[j], f[j - s] + e - (j - s) * l);
		}

		int res = 0;
		for(int i = 0; i <= m; i++) res = max(res, f[i]);

		printf("Case #%d: %d\n", C, res);
	}		
	return 0;
}
