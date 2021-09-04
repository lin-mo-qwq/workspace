#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[100005];

int main()
{
    cin>>n>>m;
    for(int i = 1; i <= n; i++) cin>>a[i];
    while(m--)  next_permutation(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}