#include<bits/stdc++.h>
using namespace std;
const int M = 1e3  + 50;
typedef pair<int, int> PII;
int n, m, k, p, ret[M][M], sum[2];
priority_queue<PII> q;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &ret[i][j]);
		

	return 0;
}