#include<bits/stdc++.h>
using namespace std;
const int M = 1e5 + 5;
int n, m;
struct seg
{
	int l, r;
	friend bool operator < (seg a, seg b)
	{
		return a.l < b.l;	
	}
} a[M];

int main()
{
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].l, &a[i].r);

	sort(a + 1, a + 1 + n);

	int R = 0, j = 0, ret = 0;

	for(int i = 1; i <= n; i = j)
	{
		j = i;
		int mx = 0;
		while(j <= n && a[j].l <= R + 1)
			mx = max(mx, a[j].r), j++;
		if(R >= mx) break;
		ret++, R = mx;
		if(R >= m) break;
	}

	if(R < m) printf("-1\n");
 	else printf("%d\n", ret);
	
	return 0;
}