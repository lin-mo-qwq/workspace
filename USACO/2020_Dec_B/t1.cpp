#include<bits/stdc++.h>
using namespace std;
int A[15];
int main()
{
	for(int i = 1; i <= 7; i++) cin>>A[i];
	sort(A + 1, A + 1 + 7);
	cout<<A[1]<<' '<<A[2]<<' '<<A[7] - A[1] - A[2];
	return 0;
}