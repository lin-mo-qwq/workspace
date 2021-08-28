#include<bits/stdc++.h>
using namespace std;
const int N = 2005, M = 10005;
int n, m, dad[N];
struct edge {
    int u, v, w;
    bool operator < (const edge x) const {
        return w < x.w;
    }
} e[M];

int find(int x) {
    if(x != dad[x]) return dad[x] = find(dad[x]);
    return x;
}

int main() {
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++) dad[i] = i;

    int res = 0, k = 0;
        
    for(int i = 1; i <= m; i++) {
        int p, u, v, w;
        scanf("%d%d%d%d", &p, &u, &v, &w);
        if(p == 1) {
            res += w;
            dad[find(u)] = find(v);  
        } else {
            e[++k] = {u, v, w};
        }     
    }

    sort(e + 1, e + 1 + k);

    for(int i = 1; i <= k; i++) {
        int u = find(e[i].u), v = find(e[i].v);
        if(u != v) {
            dad[u] = v;
            res += e[i].w;
        }
    }

    printf("%d\n", res);
    return 0;
}