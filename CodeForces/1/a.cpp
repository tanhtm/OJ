#include <bits/stdc++.h>
using namespace std;
int main(){
	long long int n,m,a;
	cin>>n>>m>>a;
	((n + (a - 1)/a) * ((m + (a - 1))/a))?cout<<(((n + (a - 1))/a) * ((m + (a - 1))/a)):cout<<1;
	return 0;
}