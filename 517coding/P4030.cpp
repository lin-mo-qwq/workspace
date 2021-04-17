#include<bits/stdc++.h>
using namespace std;
const int M = 1e3  + 50;
long long n, m, k, p, ret[M][M], sum[2], ans;
struct Node
{
	long long sum;
	bool line;

	long long cnt() {
		if(line) return sum - p * n;
		else return sum - p * m;
	}

	friend bool operator < (Node x, Node ret) {
		return x.sum < ret.sum || (x.sum == ret.sum && x.cnt() < ret.cnt());
	}
} ;
priority_queue<Node> q;

int main() {
	scanf("%lld%lld%lld%lld", &n, &m, &k, &p);
	for(int i = 1, tmp = 0; i <= n; i++, tmp = 0) {
		for(int j = 1; j <= m; j++)
			scanf("%lld", &ret[i][j]), tmp += ret[i][j]; 
		q.push({tmp, 0});
	}

	for(int i = 1, tmp = 0; i <= m; i++, tmp = 0) {
		for(int j = 1; j <= n; j++)
			tmp += ret[j][i];
		q.push({tmp, 1});
	}

	while(k--) {
		Node tmp = q.top(); q.pop(); 	
		ans += tmp.sum - sum[tmp.line ^ 1];
		sum[tmp.line] += p;
		if(tmp.line) q.push({tmp.cnt(), 1});
		else q.push({tmp.cnt(), 0});
	}
	
	printf("%lld\n", ans);
	return 0; 
}