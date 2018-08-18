#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		vector < int > a(n);
		vector < bool > b(n);
		for(int i=0 ;i<n; i++){
			cin>>a[i];
		}
		bool check = true;
		for(int i=0 ;i<n-1; i++){
			int v = abs(a[i]- a[i+1]);
			if(v == 0 || v>=n ) check = false;
			else b[v] = true;
		}
		for(int i=1 ;i<=n-1; i++){
			if(!b[i]) check = false;
		}
		if(check) cout<<"Jolly";
		else cout<<"Not jolly";
		cout<<endl;
	}
    return 0;
}