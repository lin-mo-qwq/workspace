#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
int tr[N], a[N], ret[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int c) {
    for(int i = x; i <= n; i += lowbit(i)) {
        tr[i] += c;
    }
}

int sum(int x) {
    int res = 0;
    for(int i = x; i; i -= lowbit(i)) {
        res += tr[i];
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    for(int i = 1; i <= n; i++) {
        add(i, 1);
    }
    
    for(int i = n; i; i--) {
        int k = a[i] + 1;
        int l = 1, r = n, best;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(sum(mid) >= k) {
                best = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        ret[i] = best;
        add(best, -1);
    }
    
    for(int i = 1; i <= n; i++) printf("%d\n", ret[i]);
    return 0;
}