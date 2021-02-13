#include<bits/stdc++.h>
using namespace std;

int r, c, k, ans;
char M[105][105], ox[2]={0, 1}, oy[2]={1, 0};

void dfs(int x, int y, int i, int j)
{
    if(j > k)
    {
        ans++;
        return ;
    }
    if(M[x][y] != '.' || x <= 0 || y <= 0 || x > r || y > c)
        return ;   
    dfs(x + ox[i], y + oy[i], i, j + 1);
}

int main()
{
    cin>>r>>c>>k;

    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            cin>>M[i][j];
    
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            if(M[i][j] == '.')
                for(int k = 0; k < 2; k++)
                    dfs(i, j, k, 1);

    if(k == 1)
        ans /= 2;
    
    cout<<ans<<endl;
    return 0;
}