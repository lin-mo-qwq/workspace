#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
const double mus = 1e-11;
const int N = 505, M = N * N;
typedef pair<int, int> PII;
PII p[N];
int n, m, k;
int dad[N];
bool st[N];
struct edge {
    int u, v;
    double w;
    bool operator < (const edge x) const {
        return w < x.w;
    }
} e[M];

double getDist(PII u, PII v) {
    double dx = (u.x - v.x), dy = (u.y - v.y);
    return sqrt(dx * dx + dy * dy);
}

int find(int x) {
    if(x != dad[x]) return dad[x] = find(dad[x]);
    else return x;
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &p[i].x, &p[i].y); 
    }

    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j <= n; j++) 
            e[++m] = {i, j, getDist(p[i], p[j])};
    }

    sort(e + 1, e + 1 + m);
    int cnt = n; 

    for(int i = 1; i <= n; i++) 
        dad[i] = i;  
    
    for(int i = 1; i <= m; i++) {
        int u = e[i].u, v = e[i].v;
        u = find(u), v = find(v);
        if(u != v) {
            dad[u] = v;
            cnt--;
            if(k >= cnt) {
                printf("%.2lf\n", e[i].w); 
                break;
            }
        } 
    }  

    return 0;
}