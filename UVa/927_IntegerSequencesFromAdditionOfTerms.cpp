#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector < long long int > c; // c[j]
long long int i; // degree
long long int d,k;
long long int find(){
	long long int x = 1;
	long long int y = d;
	while (y< k){
		x++;
		y += x*d;
	}
	return x;
}
long long int getAn(long long int n){
	long long int r= 0;
	for(long long int j=0;j<=i;j++){
		r+= c[j]*pow(n,j);
		//cout<<r<<endl;
	}
	return r;
}
void solve(){
	long long int n = find();
	cout<<getAn(n)<<endl;
}
int main(){
	//freopen("data.txt","r",stdin);
	long long int test;
	cin>>test;
	while(test--){
		cin>>i;
		c.resize(i+1);
		for(long long int j = 0; j<=i;j++)
			cin>>c[j];
		cin>>d>>k;
		solve();
	}
	return 0;
}