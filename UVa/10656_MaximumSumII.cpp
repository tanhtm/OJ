#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int n;
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	while(cin>>n  && n!= 0){
		bool b = true;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			if(x != 0){
				if(b) b = false;
				else cout<<" ";
				cout<<x;
			}
		}
		if(b) cout<<0;
		cout<<endl;
	}
	return 0;
}