#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size()-1;i++){
		if(s[i] == 's' && s[i+1] =='s'){
			cout<<"hiss"<<endl;
			return 0;
		}
	}
	cout<<"no hiss"<<endl;
	return 0;
}