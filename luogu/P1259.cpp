#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	for(int j = 1; j <= n - 3; j++) {
		for(int i = 1; i <= n - j + 1; i++) printf("o");
		for(int i = 1; i <= n - j + 1; i++) printf("*");
		printf("--");
		for(int i = 1; i < j; i++) printf("o*");
		puts("");
		for(int i = 1; i <= n - j; i++) printf("o");
		printf("--");
		for(int i = 1; i <= n - j; i++) printf("*");
		for(int i = 1; i <= j; i++) printf("o*");
		puts("");
	}

	printf("ooo*o**--*");
	for(int i = 1; i <= n - 4; i++) printf("o*");
	printf("\no--*o**o");
	for(int i = 1; i <= n - 3; i++) printf("o*");
	puts("");
	for(int i = 1; i <= 3; i++) printf("o*");
	printf("--");
	for(int i = 1; i <= n - 3; i++) printf("o*");
	printf("\n--");
	for(int i = 1; i <= n; i++) printf("o*");
	return 0;
}