#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
string s,t;
int main(){
	cin>>n>>m;
	cin>>s>>t;
	if(m < n - 1){
		cout<<"NO";
		return 0;
	}
	bool check = true;
	bool checkSao = false;
	for(int i =0;i<n;i++){
		if(s[i] =='*'){
			checkSao = true;
			break;
		}
		if(s[i] != t[i]){
			check = false;
			break;
		}
	}
	for(int i =0;i< n;i++){
		if(s[n-1-i] =='*') break;
		if(s[n-1-i] != t[m-1-i]){
			check = false;
			break;
		}
	}
	if(!checkSao && n != m){
		cout<<"NO";
		return 0;
	}
	if(check) cout<<"YES";
	else cout<<"NO";
	return 0;
}