#include<iostream>
#include<algorithm>
#include<vector>
#include <string.h>
using namespace std;
int n;
int main(){
	while(cin>>n){
		vector < int > a;
		for(int i=0;i < 1<<n ; i++){
			int x;
			cin>>x;
			a.push_back(x);
		}
		vector < int > ws;
		for(int i=0 ;i< 1<<n ; i++){
			int w = a[i];
			int v;
			for(int j = 0 ;j<n;j++){
				if(i & (1<<j)) v = i - (1<<j);
				else v = i + (1<<j);
				//cout<<v<<" ";
				w+= a[v];
			}
			//cout<<endl;
			ws.push_back(w);
		}
		/*for(int i=0 ;i< 1<<n ; i++){
			cout<<ws[i]<<" ";
		}*/
		int res = 0;
		for(int i=0 ;i< 1<<n ; i++){
			int v;
			for(int j = 0 ;j<n;j++){
				if(i & (1<<j)) v = i - (1<<j);
				else v = i + (1<<j);
				res = max(res, ws[i] + ws[v] - a[i] - a[v]);
			}
		}
		cout<<res<<endl;
		
	}
    return 0;
}