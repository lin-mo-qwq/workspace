#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int a[N], p[N], ans = 0x3f3f3f3f;
bool vis[N];
void dfs(int cur, int cnt) {
    if(vis[cur]) return ;
    if(p[cur]) ans = min(ans, cnt - p[cur]);
    else {
        p[cur] = cnt;
        dfs(a[cur], cnt + 1);
        vis[cur] = true;
    } 
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) 
        scanf("%d", &a[i]);

    for(int i = 1; i <= n; i++) 
        dfs(i, 0);

    printf("%d\n", ans);
    return 0;
}