#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,b,h,w;
int main(){

	while(true){
		cin>>n>>b>>h>>w;
		if(!cin) break; /////////////////// !cin
		int p,res= b+1;
		for(int i=0;i< h; i++){
			cin>>p;
			int s = 0; // co o dc hay ko
			for(int j=0;j<w;j++){
				int v;
				cin>>v;
				s = max(s,v);
			}
			if(s >= n){
				res = min(res, n*p);
			}
		}
		if(res>b) cout<<"stay home";
		else cout<<res;
		cout<<endl;
		cin.clear(); //////////////////// !cin
	}
	return 0;
}