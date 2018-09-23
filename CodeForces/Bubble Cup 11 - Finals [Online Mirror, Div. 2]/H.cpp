#include <bits/stdc++.h>
using namespace std;
int n;
map < string , int > M;
set < string > L;
string s;
int C[50];
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		memset(C,0,sizeof C);
		for(int j=0;j<s.size();j++){
			C[s[j]-'a']++;
		}
		s = "";
		for(int j=0;j<50;j++){
			if(C[j]%2==1) s+= j + 'a';
		}
		if(s.size() == 0) s=".";
		//cout<<s<<endl;
		M[s]++;
		L.insert(s);
	}
	int r = 0;
	set< string >::iterator it;
	for (it=L.begin(); it!=L.end(); ++it){
		s= *it;
		string t;
		r+= (M[s]*(M[s]-1))/2;
		if(s[0] == '.') continue;
		if(s.size() == 1){
			r+= M[string(".")] * M[s];
			continue;	
		}
		for(int i=0;i<s.size();i++){
			t = s;
			t.erase(t.begin()+i);
			r+= M[t]*M[s];
		}
	}
	cout<<r<<endl;
	return 0;
}