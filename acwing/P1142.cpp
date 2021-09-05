#include<bits/stdc++.h>
using namespace std;
const int N = 310, M = 8010;
int n, m, p[N];
struct edge {
    int u, v, w;
    bool operator < (const edge x) const {
        return w < x.w;
    }
} e[M];

int find(int x) {
    if(p[x] != x) return p[x] = find(p[x]);
    else return x;
}

int main() {
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++) p[i] = i;

    for(int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[i] = {u, v, w};
    }

    int res = 0;
    sort(e + 1, e + 1 + m);

    for(int i = 1; i <= m; i++) {
        int u = find(e[i].u), v = find(e[i].v);
        if(u != v) {
            p[u] = v;
            res = e[i].w;
        }
    }

    printf("%d %d\n", n - 1, res);
    return 0;
}