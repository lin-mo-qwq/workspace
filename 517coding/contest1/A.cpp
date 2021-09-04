#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;
long long n, a[N], f[N], g[N];
int main() {
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) 
        scanf("%lld", &a[i]);
    
    for(int i = n; i >= 1; i--) {
        f[i] = max(a[i], f[i + 1] + a[i]);   
    }

    long long ans = -INF, nowMax = -INF, tmp = -INF;

    for(int i = 1; i <= n; i++) {
        tmp = max(a[i], tmp + a[i]);
        nowMax = max(nowMax, tmp);
        ans = max(ans, nowMax + f[i + 1]);
    }

    printf("%lld\n", ans); 
    return 0;
}