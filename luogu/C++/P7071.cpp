#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n % 2 != 0) cout<<-1<<endl, exit(0);
    for(int i = 24; i >= 1; i--) if(n >= (1 << i)) n -= (1 << i), cout<<(1 << i)<<' ';
    cout<<endl;
    return 0;
}