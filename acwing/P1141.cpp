#include<bits/stdc++.h>
using namespace std;
const int M = 210, N = 110;
struct edge {
    int u, v, w;
    bool operator < (const edge a) const {
        return w < a.w;
    }
} e[M];
int n, k;
int dad[N];

int find(int x) {
    if(dad[x] != x) return dad[x] = find(dad[x]);
    else return x;
}

int main() {
    scanf("%d%d", &n, &k);

    for(int i = 1; i <= n; i++) 
        dad[i] = i;

    for(int i = 1; i <= k; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[i] = {u, v, w};
    }

    int res = 0;

    sort(e + 1, e + 1 + k);

    for(int i = 1; i <= k; i++) {
        int u = find(e[i].u), v = find(e[i].v);
        if(u != v) dad[u] = v;
        else res += e[i].w;
    }

    printf("%d\n", res);
    return 0;
}