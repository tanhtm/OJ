#include <bits/stdc++.h>
using namespace std;
int n,k;
stack < int > S;
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	cin>>n>>k;
	for(int i=0;i<k;i++){
		string s;
		cin>>s;
		if(s != "undo") S.push(stoi(s));
		else{
			int x;
			cin>>x;
			while(x-- && !S.empty()) S.pop();
		}
	}
	int k =0;
	while(!S.empty()){
		k+= S.top();
		k%= n;
		if(k<0) k+=n;
		S.pop();
	}
	cout<<k<<endl;
	return 0;
}