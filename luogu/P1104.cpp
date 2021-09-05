#include<bits/stdc++.h>
using namespace std;

struct oi
{
    string name;
    int year, mouth, day, s;
    friend bool operator < (oi a, oi b)
    {
        if(a.year != b.year) return a.year < b.year;
        else if (a.mouth != b.mouth)  return a.mouth < b.mouth;
        else if (a.day != b.day)return a.day < b.day;
        else return a.s > b.s;
    }
    void ins()
    {cin >> name >> year >> mouth >> day;}
}  M[105];

int main(void)
{
    int n;
    cin >>n;
    for(int i = 1; i <= n; i++) M[i].ins(), M[i].s = i;
    sort(M + 1, M + 1 + n);
    for(int i = 1; i <= n; i++) cout << M[i].name <<endl;
    return 0;
}