#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
vector<int> E[N];
int n, m, cnt;
int dad[N], g[N], w[N], degree[N], ans[N], vis[N];

int anc(int x) {
    if(dad[x] != x) return dad[x] = anc(dad[x]);
    return x;
}

void dfs(int x) {
    vis[x] = 1;
    for(auto i : E[x]) {
        if(!vis[i]) {
            ans[i] = ans[x] + w[i];
            dfs(i); 
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    cnt = n;
    for(int i = 1; i <= n + m; i++) dad[i] = g[i] = i;
    for(int i = 1; i <= m; i++) {
        int opt, x, y;
        scanf("%d%d%d", &opt, &x, &y);
        if(opt == 1) {
            int fx = anc(x), fy = anc(y);
            g[fx] = dad[fx] = ++cnt, g[fy] = dad[fy] = cnt;
        } else {
            int fx = anc(x);
            w[fx] += y;
        }
    }
    for(int i = 1; i <= n + m; i++) {
        if(i != g[i]) {
            E[i].push_back(g[i]);
            E[g[i]].push_back(i);
            degree[i]++; 
        }
    }

    for(int i = 1; i <= n + m; i++) {   
        if(!degree[i] && !vis[i]) {
            ans[i] = w[i], dfs(i);
        }
    }

    for(int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }

    puts("");
    return 0;
}