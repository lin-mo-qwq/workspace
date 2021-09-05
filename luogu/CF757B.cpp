#include<bits/stdc++.h>
using namespace std;

#define M 100005
int sums[M], maxs;
bool P[M];

int main()
{
	int n, ans = 1;

	cin >> n;

	for(int i = 1, x; i <= n; i++)
		cin >> x, sums[x]++, maxs = max(maxs, x);
	
	memset(P, 1, sizeof(P));

	P[0] = P[1] =false;

	for(int i = 2, t; i <= maxs; i++)
	{
		if(!P[i])	continue;

		t = sums[i];

		for(int j = 2; j <= maxs / i; j++)
			t += sums[i * j], P[i * j] = false;
		
		ans = max(ans, t);
	}

	cout << ans << endl;
	return 0;
}