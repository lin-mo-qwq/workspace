#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
int n, a[N];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

	long long j = 0, sum_a = 0;
	long long sum_b = 0, ret = 0;

	for(int i = 1; i <= n; i++)
	{
		while(j <= n && sum_a == sum_b)
			j++, sum_a ^= a[j], sum_b += a[j];
		
		ret += j - i;
		sum_a ^= a[i];
		sum_b -= a[i];
	}

	printf("%lld\n", ret);
	return 0;
}