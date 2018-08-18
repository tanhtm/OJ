#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int t,n,res;
	cin>>t;
	for(int i=0 ;i< t ;i++){
		cin>>n;
		res= 0;
		for(int j =0 ;j<n;j++){
			int x;
			cin>>x;
			res = max(res,x);
		}
		cout<<"Case "<<i+1<<": "<<res<<endl;
	}
	
	return 0;
}