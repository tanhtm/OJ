#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
void solve(int n){
	vector < vector < int > > mt(n,vector < int > (n));
	for(int i=0;i<n;i++){
		for(int j = 0 ;j< n;j++){
			cin>>mt[i][j];
			if(i > 0) mt[i][j]+= mt[i-1][j];
			if(j > 0) mt[i][j]+= mt[i][j-1];
			if(i > 0 && j > 0) mt[i][j]-= mt[i-1][j-1];
		}
	}
	/*for(int i = 0;i< n;i++){
		for(int j=0;j<n;j++){
			cout<<mt[i][j]<<" ";	
		}
		cout<<endl;
	}*/
	int sum, sumMax = -1000000000;
	for(int i =0;i< n;i++){
		for(int j=0;j< n;j++){
			for(int k = i;k<n;k++){
				for(int h = j;h<n;h++){
					sum = mt[k][h];
					if(i > 0) sum-= mt[i-1][h];
					if(j > 0) sum-= mt[k][j-1];
					if(i > 0 && j > 0) sum+= mt[i-1][j-1];
					sumMax = max(sumMax,sum);
				}
			}
		}
	}
	cout<<sumMax<<endl;
}
int main(){
	//freopen("data.txt","r",stdin);
	int n;
	cin>>n;
	solve(n);
	return 0;
}