#include<cstdio>
#include<cstring>
const int N = 20, INF = 0x3f3f3f3f;
int n, f[(1 << N)][N], time[(1 << N)], ans[N];
struct tasks {
	char name[105];
	int ddl, need;
} a[N];

void checkMin(int &x, int y) {
	if(x > y) {
		x = y;
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s%d%d", &a[i].name, &a[i].ddl, &a[i].need);
	}

	memset(f, 0x3f, sizeof(f));	
	for(int mask = 0; mask < (1 << n); mask++) {
		for(int i = 0; i < n; i++) {
			if(mask & (1 << i)) {
				time[mask] += a[i].need;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		if(a[i].need - a[i].ddl > 0) {
			f[(1 << i)][i] = a[i].need - a[i].ddl;
		} else {
			f[(1 << i)][i] = 0;
		}
	}

	for(int mask = 0; mask < (1 << n); mask++) {
		for(int end = 0; end < n; end++) if(f[mask][end] != -INF) {
			for(int nxt = 0; nxt < n; nxt++) if(!(mask & (1 << nxt))) {
				int cnt = (time[mask | (1 << nxt)] - a[nxt].ddl);
				if(cnt < 0) cnt = 0;
				checkMin(f[mask | (1 << nxt)][nxt], f[mask][end] + cnt);
			}
 		}
	}

	int ret = INF, mask = (1 << n) - 1, end, len = n;
	for(int i = 0; i < n; i++) {
		if(ret >= f[(1 << n) - 1][i]) {
			ret = f[(1 << n) - 1][i];
			end = i;
		}
	}
	
	printf("%d\n", ret);
	while(mask > 0) {
		int cnt = (time[mask] - a[end].ddl);
		if(cnt < 0) cnt = 0;
		ans[--len] = end;
		int tmp = f[mask][end] - cnt;
		mask -= (1 << end);
		for(int i = 0; i < n; i++) {
			if(f[mask][i] == tmp) {
				end = i;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		printf("%s\n", 	a[ans[i]].name);
	}
	return 0;
}