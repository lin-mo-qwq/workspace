#include<bits/stdc++.h>
using namespace std;
#define N 2005
int n, m, mx, sum;
int ret[2005][2005];

#define PII pair<int, int>

priority_queue<PII, vector<PII>, greater<PII>> q;

void uni(int a[], int b[], int n) {
	int tmp[N], cnt = 0, nxt[N];
	for(int i = 1; i <= n; i++)
		nxt[i] = 1, q.push({a[i] + b[1], i});
	
	while (n--)
	{
		auto tmp1 = q.top(); q.pop();
		auto i = tmp1.second;
		tmp[++cnt] = tmp1.first;
		q.push({a[i] + b[++nxt[i]], i});
	}

	for(int i = 1; i <= cnt; i++)
		b[i] = tmp[i];
	priority_queue<PII, vector<PII>, greater<PII>> tmp1 = {};
	q = tmp1;
}


int main() {
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++)
			scanf("%d", &ret[i][j]);
		sort(ret[i] + 1, ret[i] + 1 + n);
	}


	for(int i = 1; i <= m - 1; i++)
		uni(ret[i], ret[i + 1], n);

	for(int j = 1; j <= n; j++)
		cout<<ret[m][j]<<' ';	 

	puts("");
	return 0;
}