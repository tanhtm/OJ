#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;
string s,t;
void in(){
	//freopen("data.txt","r",stdin);
	cin>>t>>s;
	t = string("-") + t;
	s = string("-") + s;
	//cout<<t<<endl<<s<<endl;
}
vector < int > p; // ham tien to // p[i] la do dai lon nhat cua sau hau to tinh tu 1..i 
void XuLyHamTienTo(){
	int k = 0;
	p.resize(s.size()+1);
	p[1] = 0;
	for(int i= 2; i < s.size();i++){
		while (k > 0 && s[k+1] != s[i]) k = p[k];
		if(s[k+1] == s[i]) k++;
		p[i] = k; 
	}
	/*for(int i = 0; i< s.size(); i++){
		cout<<p[i]<<" ";
	}
	cout<<endl;*/
}
void KMP(){ // so khop
	int k = 0;
	for(int i = 1; i< t.size() ; i++){
		while(k > 0 && s[k+1] != t[i]) k = p[k];
		if(s[k+1] == t[i]) k++;
		if(s[k+1] == 0) { // het sau s
			cout<<i - k + 1<<" ";
			k = p[k];
		}
	}
}
int main(){
	in();
	XuLyHamTienTo();
	KMP();
	return 0;
}