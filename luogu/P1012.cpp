#include<bits/stdc++.h>
using namespace std;

int n;
vector<string> a;

bool cmp(string a, string b)
{
    return a+b < b+a;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) {string s; cin >> s;a.push_back(s);}
    sort(a.begin(), a.end(), cmp);
    for(int i = n - 1; i >= 0; i--){cout << a[i];}
    puts("");
    return 0;
}