#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
int n, m, a[N];
ll tr1[N], tr2[N];

int lowbit(int x) {
    return x & -x;
}

void add(ll tr[], int x, ll c) {
    for(int i = x; i <= n; i += lowbit(i)) 
        tr[i] += c;
}

ll sum(ll tr[], ll x) {
    ll res = 0;
    for(int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

ll pre(int x) {
    return (x + 1) * sum(tr1, x) - sum(tr2, x);
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    
    for(int i = 1; i <= n; i++) {
        int b = a[i] - a[i - 1];
        add(tr1, i, b), add(tr2, i, 1ll * i * b);
    }
    
    for(int i = 1; i <= m; i++) {
        char op[2];
        int l, r;
        scanf("%s%d%d", op, &l, &r);
        if(op[0] == 'C') {
            int d;
            scanf("%d", &d);
            add(tr1, l, d), add(tr1, r + 1, -d);
            add(tr2, l, 1ll * l * d), add(tr2, r + 1, 1ll * -d * (r + 1));
        } else {
            printf("%lld\n", pre(r) - pre(l - 1));
        }
    }
    return 0;
}