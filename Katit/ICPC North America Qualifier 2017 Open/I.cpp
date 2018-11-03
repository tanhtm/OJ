#include <bits/stdc++.h>
using namespace std;
int n,g;
int a[1002];
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	cin>>n;
	for(int i= 0 ;i<n;i++){
		cin>>g;
		for(int j=0;j<g;j++){
			cin>>a[j];
		}
		for(int j=1;j<g-1;j++){
			if(a[j] - a[j-1] != 1){
				cout<<j+1<<endl;
				break;
			} 
		}

	}
	return 0;
}