#include<bits/stdc++.h>
using namespace std;
const int N = 100000;
int n, p;
double w[N], h[N], f[N];

double solve() {
    scanf("%d%d", &n, &p);
    double mx = 0, need = 0; 
    for(int i = 1; i <= n; i++) {
        scanf("%lf%lf", &w[i], &h[i]);
        if(w[i] > h[i]) swap(w[i], h[i]);   
        need += 2 * (w[i] + h[i]);
        mx += 2 * (w[i] + h[i] + sqrt(w[i] * w[i] + h[i] * h[i]));    
    }
    if(mx <= p) return mx;
    p -= need;
    
    memset(f, 0, sizeof f);
    for(int i = 1; i <= n; i++) {
        int mi = 2 * w[i];
        double mx = 2 * sqrt(w[i] * w[i] + h[i] * h[i]);
        for(int j = p; j >= mi; j--)
            f[j] = max(f[j], f[j - mi] + mx);
    }

    double ans = 0;
    for(int i = 1; i <= p; i++) {
        if(f[i] >= p) return p + need;
        ans = max(ans, f[i]);
    }
    return ans + need;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        printf("Case #%d: %.10lf\n", i, solve()); 
    }
    return 0;
}