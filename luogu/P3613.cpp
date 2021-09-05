#include<bits/stdc++.h>
using namespace std;
int n,q;
int main()
{
	cin>>n>>q;
	vector< vector<int> > locker((unsigned int)n+1);
	
	while (q--)
	{
		int num,i,j,k;
		cin>>num;
		if(num&1)
		{
			cin>>i>>j>>k;
			if((int)locker[i].size()<j+1) 
				locker[i].resize((unsigned int)j+1);
			locker[i][j]=k;
		}
		else
			cin>>i>>j,cout<<locker[i][j]<<endl;
	}
	
	return 0;
}