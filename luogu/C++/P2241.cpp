#include<bits/stdc++.h>
using namespace std;
long long n, m, r, s;
int main()
{
    cin>>n>>m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(i == j) r += (n - i) * (m - j);
            else s += (n - i) * (m - j);
        }
    cout<<r<<' '<<s<<endl;
    return 0;
}