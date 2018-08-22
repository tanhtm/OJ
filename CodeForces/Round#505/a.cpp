#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	if(n == 1){
		cout<<"Yes"<<endl;
		return 0;
	}
	static int mark[270];
	for(int i = 0;i< n;i++){
		if(mark[s[i]]){
			cout<<"Yes"<<endl;
			return 0;
		}
		mark[s[i]]++;
	}
	cout<<"No"<<endl;
	return 0;
}