#include<bits/stdc++.h>
using namespace std;
#define M 1005
int n, m, ret[M], f[M];
int main()
{
	int hh, mm;
	scanf("%d:%d", &hh, &mm);
	m = hh * 60 + mm;	
	scanf("%d:%d", &hh, &mm);
	m = hh * 60 + mm - m;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int v, w, s;

		scanf("%d %d %d", &v, &w, &s);

		if(s == 0)
			for(int j = v; j <= m; j++)
				f[j] = max(f[j], f[j - v] + w);

		else
		{
			for(int k = 1; k <= s; k *= 2)
			{
				for(int j = m; j >= k * v; j--)
					f[j] = max(f[j], f[j - k * v] + k * w);
				s -= k;
			}
			
			if(s)
			{
				for(int j = m; j >= s * v; j--)
					f[j] = max(f[j], f[j - s * v] + s * w);
			}
		}
	}
	printf("%d\n", f[m]);	
	return 0;
}