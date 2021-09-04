#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n;
int g[N][N], dist[N];
bool st[N];

int prim() {
    int ans = 0;
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int i = 0; i < n; i++) {
        int t = -1;
        
        for(int j = 1; j <= n; j++) {
            if(!st[j] && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }

        st[t] = true;
        ans += dist[t];

        for(int j = 1; j <= n; j++)  
            dist[j] = min(dist[j], g[t][j]);
    }

    return ans;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) 
            scanf("%d", &g[i][j]);

    printf("%d\n", prim());
    return 0;
}