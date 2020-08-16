#include<bits/stdc++.h>
using namespace std;

int n;
int data[200];
char a[10][5][3]=
{
	{ // todo 0
		'X','X','X',
		'X','.','X',
		'X','.','X',
		'X','.','X',
		'X','X','X',
	},

	{// todo 1
		'.','.','X',
		'.','.','X',
		'.','.','X',
		'.','.','X',
		'.','.','X',
	},

	{// todo 2
		'X','X','X',
		'.','.','X',
		'X','X','X',
		'X','.','.',
		'X','X','X',
	},

	{// todo 3
		'X','X','X',
		'.','.','X',
		'X','X','X',
		'.','.','X',
		'X','X','X',
	},

	{// todo 4
		'X','.','X',
		'X','.','X',
		'X','X','X',
		'.','.','X',
		'.','.','X',
	},

	{// todo 5
		'X','X','X',
		'X','.','.',
		'X','X','X',
		'.','.','X',
		'X','X','X',
	},

	{// todo 6
		'X','X','X',
		'X','.','.',
		'X','X','X',
		'X','.','X',
		'X','X','X',

	},
	
	{// todo 7
		'X','X','X',
		'.','.','X',
		'.','.','X',
		'.','.','X',
		'.','.','X',
	},

	{// todo 8
		'X','X','X',
		'X','.','X',
		'X','X','X',
		'X','.','X',
		'X','X','X',
	},

	{// todo 9
		'X','X','X',
		'X','.','X',
		'X','X','X',
		'.','.','X',
		'X','X','X',
	}
};

void inp()
{
	cin>>n;
	getchar();
	getchar();
	for(int i=1;i<=n;i++)
		data[i]=(getchar()-'0');
}

void print()
{	
	for(int j=0;j<5;j++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int k=0;k<3;k++)
				cout<<(a[data[i]][j][k]+'0');
			
			if(i!=n)
				cout<<'.';
			
		}
		cout<<endl;
	}
}

int main()
{
	inp();
	print();
	return 0;
}