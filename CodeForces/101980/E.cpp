#include <bits/stdc++.h>
using namespace std;
string a,b;
int n,m;
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	cin>>a>>b;
	int r = 0;
	n = a.size(); m = b.size();
	for(int i = 0 ;i< n- m + 1;i++){
		for(int j=0;j< m;j++){
			if(a[i+j] == b[j]){
				r++;
				break;
			}
		}
	}
	cout<<n-m + 1-r<<endl;
	return 0;
}