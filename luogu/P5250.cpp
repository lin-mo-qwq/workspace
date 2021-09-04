#include<bits/stdc++.h>
using namespace std;
vector<int> repo;
int n;
map <int, bool> vis; 
int main()
{
	cin>>n;
	while(n--)
	{
		int opt, ret;
		cin>>opt>>ret;
		if(opt == 1)
		{
			if(!vis[ret]) repo.push_back(ret), vis[ret] = true;
			else cout<<"Already Exist"<<endl;
 		}
		else
		{
			if(repo.empty()) cout<<"Empty"<<endl;
			else
			{
				int tmp = 0;
				sort(repo.begin(), repo.end());
				for(int i = 0; i < repo.size(); i++)
				{ 
					if(abs(repo[i] - ret) < abs(repo[tmp] - ret)) tmp = i;
				}
				cout<<repo[tmp]<<endl;
				vis[repo[tmp]] = false;
				repo.erase(repo.begin() + tmp);
			}
		}
	}
	return 0;
}		