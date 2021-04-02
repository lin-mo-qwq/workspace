#include<bits/stdc++.h>
using namespace std;

const int M = 1e6 + 5;
const int INF = 0x3f3f3f3f;

int a[M], sum[M];

int main()
{
	int n, s;
	while(~scanf("%d%d", &n, &s))
	{	
		int ret = INF;

		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
		
		for(int i = 1; i <= n; i++)
		{
			int l = i, r = n, best = 0;
			while(l <= r)
			{
				int mid = (l + r) / 2;
				if(sum[mid] - sum[i - 1] >= s) best = mid, r = mid - 1;
				else l = mid + 1; 
			}

			if(sum[best] - sum[i - 1] >= s) 
				ret = min(ret, best - i + 1);

		}
		if(ret == INF) printf("0\n");
		else printf("%d\n", ret);
	}
	return 0;
}