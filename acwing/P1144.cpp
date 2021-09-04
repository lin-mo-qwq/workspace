#include<bits/stdc++.h>
using namespace std;
const int N = 1005, M = N * N, K = 2 * N * N;
int n, m, k;
int ids[N][N], dad[M], ans;
struct edge {
    int u, v, w;
} ;
deque<edge> q;

int find(int x) {
    if(x != dad[x]) return dad[x] = find(dad[x]);
    else return x;
}

void getEdges() {
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            int u = ids[i][j], v1 = ids[i][j + 1], v2 = ids[i + 1][j];
            u = find(u), v1 = find(v1), v2 = find(v2);
            if(u != v1) q.push_back({u, v1, 2});
            if(u != v2) q.push_front({u, v2, 1});  
        }
    }

    for(int i = 1; i < n; i++) {
        int u = ids[i][m], v = ids[i + 1][m];
        u = find(u), v = find(v);
        if(u != v) {
            q.push_front({u, v, 1});
        }
    }

    for(int i = 1; i < m; i++) {
        int u = ids[n][i], v = ids[n][i + 1];
        u = find(u), v = find(v);
        if(u != v) {
            q.push_back({u, v, 2});
        }
    } 
}

int main() {
    scanf("%d%d", &n, &m);
    
    for(int i = 1; i < M; i++) 
        dad[i] = i;

    for(int i = 1, t = 0; i <= n; i++) {
        for(int j = 1; j <= m; j++) 
            ids[i][j] = ++t;
    }
    
    int x1, y1, x2, y2;

    while(~scanf("%d%d%d%d", &x1, &y1, &x2, &y2)) {
        int u = ids[x1][y1], v = ids[x2][y2];
        dad[find(u)] = find(v);
    }

    getEdges();

    while(!q.empty()) {
        edge e = q.front();
        int u = find(e.u), v = find(e.v), w = e.w;
        if(u != v) dad[u] = v, ans += w;
        q.pop_front();
    }

    printf("%d\n", ans);
    return 0;
}