#include <bits/stdc++.h>
using namespace std;
int n;
string s;
void e(){
	int sz = s.size();
	vector < int > a(sz); 
	for(int i= 1;i<sz;i++){
		if(s[i] == ' ') a[i] = 0;
		else a[i] = s[i] - 'a' + 1;
	}
	if(a[1] == 0) cout<<' ';
	else cout<<char(a[1]+'a'-1);
	for(int i= 2;i<sz;i++){
		a[i]+= a[i-1];
		a[i]%= 27;
		if(a[i] == 0) cout<<' ';
		else cout<<char(a[i]+'a'-1);
	}
	cout<<endl;
}
void d(){
	int sz = s.size();
	vector < int > a(sz); 
	for(int i= 1;i<sz;i++){
		if(s[i] == ' ') a[i] = 0;
		else a[i] = s[i] - 'a' + 1;
	}
	for(int i= sz-1;i>=2;i--){
		a[i]-= a[i-1];
		if(a[i]<0) a[i]+= 27;
	}
	for(int i= 1;i<sz;i++){
		if(a[i] == 0) cout<<' ';
		else cout<<char(a[i]+'a'-1);
	}
	cout<<endl;
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	cin>>n;
	for(int i=0;i<n;i++){
		char c;
		cin>>c;
		getline(cin,s);
		//cout<<s<<endl;
		if(c == 'e') e();
		else d();
	}
	return 0;
}