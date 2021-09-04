#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5, INF = 0x3f3f3f3f;  
int n, p, c;
int dist[N];
vector<pair<int, int>> E[N];
int id[N];

int sPath(int x) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    memset(dist, 0x3f, sizeof dist);
    dist[x] = 0;
    q.push({0, x});
    while(!q.empty()) {
        int k = q.top().second;
        q.pop();
        for(auto i : E[k]) {
            if(dist[i.first] > dist[k] + i.second) {
                dist[i.first] = dist[k] + i.second;
                q.push({dist[i.first], i.first});
            }
        }
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(dist[id[i]] == INF) return INF;
        cnt += dist[id[i]];
    }
    return cnt;
}

int main() {
    scanf("%d%d%d", &n, &p, &c);
    
    for(int i = 1; i <= n; i++) {
        scanf("%d", &id[i]);
    }
    
    for(int i = 1; i <= c; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        E[u].push_back(make_pair(v, w));
        E[v].push_back(make_pair(u, w));
    }

    int mx = INF;
    for(int i = 1; i <= p; i++) {
        mx = min(mx, sPath(i));
    }

    printf("%d\n", mx);
    return 0;
}