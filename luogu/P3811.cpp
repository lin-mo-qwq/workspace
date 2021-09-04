#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define M 3000005
int n, inv[M], p;

void Inv(int n)
{
	int i;
	cout << 1 << endl;
	for(inv[1] = 1, i = 2; i <= n; ++i)
		inv[i] = (ll)(p - p / i) * inv[p % i] % p, printf("%d\n",inv[i]);
}

int main()
{
	ios :: sync_with_stdio(false);
	cin >> n >> p;
	Inv(n);
	return 0;
}