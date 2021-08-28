#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, a[N];
int ret[N];
int main() {
    long long k;
    scanf("%d%d%lld", &n, &m, &k);
    a[1] = n % 10, a[2] = m % 10;
    if(k <= N) {
        for(long long i = 3; i <= k; i++) {
            a[i] = (a[i - 1] * a[i - 2]) % 10;
        }
        printf("%d\n", a[k]);
        exit(0);
    } 

    for(long long i = 3; i <= k; i++) {
        a[i] = a[i - 1] * a[i - 2] % 10;
        int mask = a[i - 1] * 10 + a[i - 2];
        if(ret[mask]) {
            int w = i - ret[mask];
            printf("%d\n", a[(k - i) % w + ret[mask]]);
            exit(0);
        } 
        ret[mask] = i;
    }

    return 0;
}