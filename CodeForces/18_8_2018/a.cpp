#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int t,n;
string s;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>s;
		bool ch = true;
		for(int i=0;i<n/2;i++){
			if(s[i] == s[n-1-i]) continue;
			int x = abs((int)s[i]-(int)s[n-i-1]);
			//cout<<x<<endl;
			if(x == 2) continue;
			ch = false;
			break;
		}
		if(ch) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}