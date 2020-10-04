#include<bits/stdc++.h>
using namespace std;

string s;
int w[105], b[105], r[105], n, m, ans = 114514;

int cnt(char c, string s)
{
    int cnt = 0;
    for(int i = 0; i < s.size(); i++)
        if(s[i] != c) cnt++;
    return cnt;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> s, w[i] = w[i - 1] + cnt('W', s), b[i] = b[i - 1] + cnt('B', s), r[i] = r[i - 1] + cnt('R', s);
    for(int i = 1; i <= n - 2; i++)
        for(int j =i + 1; j < n; j++)
            ans = min(ans, w[i] + b[j] - b[i] + r[n] - r[j]);
    cout << ans << endl;
    return 0;
}