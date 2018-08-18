#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	stack < char > Stack;
	string res;
	for(int i =0;i< n;i++){
		if(s[i] == '(') Stack.push(s[i]);
		else{
			res+='(';
			res+=')';
			Stack.pop();
			if(res.size() == k){
				cout<<res<<endl;
				return 0;
			}
		}
	}
	return 0;
}