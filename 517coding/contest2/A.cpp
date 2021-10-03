#include<bits/stdc++.h>
using namespace std;
#define clr(x) memset(x, 0, sizeof x)
const int N = 105;
int r, c, h, v;
int has1[N * N], has2[N * N], sum1[N], sum2[N], b1[N], b2[N], g[N][N];
char s[N][N];
void solve() {
    scanf("%d%d%d%d", &r, &c, &h, &v);
    for(int i = 1; i <= r; i++)
        scanf("%s", &s[i][1]);
    
    int cnt = 0;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(s[i][j] == '@') cnt++;
        }
    }

    if(cnt % ((h + 1) * (v + 1))) {
        goto imp;
    }

    clr(sum1), clr(sum2);
    for(int i = 1; i <= r; i++) {
        sum1[i] = sum1[i - 1];
        for(int j = 1; j <= c; j++) {
            if(s[i][j] == '@') sum1[i]++;
        }
    }
    for(int j = 1; j <= c; j++) {
        sum2[j] = sum2[j - 1];
        for(int i = 1; i <= r; i++) {
            if(s[i][j] == '@') sum2[j]++;
        }
    }

    clr(has1), clr(has2);
    for(int i = 1; i <= r; i++) {
        has1[sum1[i]] = i;
    }
    for(int i = 1; i <= c; i++) {
        has2[sum2[i]] = i;
    }
    for(int i = 1; i <= (h + 1); i++) {
        if(!has1[cnt * i / (h + 1)]) {
           goto imp; 
        }
    }
    for(int i = 1; i <= (v + 1); i++) {
        if(!has2[cnt * i / (v + 1)]) {
            goto imp;
        }
    }

    clr(b1), clr(b2);
    for(int i = 1; i <= (h + 1); i++) {
        for(int j = has1[cnt * (i - 1) / (h + 1)] + 1; j <= has1[cnt * i / (h + 1)]; j++) 
            b1[j] = i;
    }
    for(int i = 1; i <= (v + 1); i++) {
        for(int j = has2[cnt * (i - 1) / (v + 1)] + 1; j <= has2[cnt * i / (v + 1)]; j++) 
            b2[j] = i;
    }
    
    clr(g);
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) 
            if(s[i][j] == '@') g[b1[i]][b2[j]]++;
    }

    for(int i = 1; i <= (h + 1); i++) {
        for(int j = 1; j <= (v + 1); j++) 
            if(g[i][j] != (cnt / (h + 1) / (v + 1))) {
                goto imp;
            }
    }

    printf("POSSIBLE\n");
    return ;
    imp:
        printf("IMPOSSIBLE\n");
        return ;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }    
    return 0;
}