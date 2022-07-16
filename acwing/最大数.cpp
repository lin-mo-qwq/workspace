#include<bits/stdc++.h>
using namespace std;
#define lson u << 1 
#define rson u << 1 | 1
typedef long long ll;
const int N = 2e5 + 5;
ll tr[N << 2];

void pushup(int u) {
    tr[u] = max(tr[lson], tr[rson]);
}

void modify(int u, int l, int r, int x, int v) {
    if(l == r) {
        tr[u] = v;
        return ;
    }
    int mid = (l + r) / 2;
    if(x <= mid) modify(lson, l, mid, x, v);
    else modify(rson, mid + 1, r, x, v);
    pushup(u);
}

ll query(int u, int l, int r, int a, int b) {
    if(a <= l && r <= b) return tr[u];
    int mid = (l + r) / 2;
    ll ans = 0;
    if(a <= mid) ans = query(lson, l, mid, a, b);
    if(b > mid) ans = max(ans, query(rson, mid + 1, r, a, b));
    return ans;
}

int main() {
    int m, p, n = 0;
    ll last = 0;
    scanf("%d%d", &m, &p);
    char op[2];
    for(int i = 1; i <= m; i++) {
        ll x;
        scanf("%s%lld", &op, &x);
        if(*op == 'Q') {
            last = query(1, 1, m, n - x + 1, n);
            printf("%lld\n", last);
        } else {
            x = (x + last) % p;
            modify(1, 1, m, ++n, x);
        }
    }
    return 0;
}