#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
#define clr(x) memset(x, 0, sizeof x)
typedef long long ll;
int r, b, c;
ll m[N], s[N], p[N], a[N];

bool cmp(ll x, ll y) {
    return x > y;
}

bool check(ll x) {
    clr(a);
    for(int i = 1; i <= c; i++) {
        if(m[i] * s[i] + p[i] <= x) a[i] = m[i];
        else a[i] = max(0ll, (x - p[i]) / s[i]);
    }
    sort(a + 1, a + 1 + c, cmp);
    ll cnt = 0;
    for(int i = 1; i <= r; i++) {
        cnt += a[i];
    }
    return cnt >= b;
}

ll solve() {
    scanf("%d%d%d", &r, &b, &c);
    clr(m), clr(s), clr(p);
    for(int i = 1; i <= c; i++) {
        scanf("%lld%lld%lld", &m[i], &s[i], &p[i]);
    }
    ll l = 1, r = 1ll << 62, best = -1;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(check(mid)) {
            best = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return best;   
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        printf("Case #%d: %lld\n", i, solve());        
    }
    return 0;
}