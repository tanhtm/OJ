#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
using namespace std;
string s,t;
int n;
int r = 0 ;
void in(){
	//freopen()
	cin>>s>>t;
	n = s.size();
}
vector < int > p;
void xuLyHamTienTo(){
	p.resize(n+1);
	int k = 0;
	for(int i = 2; i<t.size() ; i++){
		while ( k > 0 && t[k+1] != t[i]) k = p[k];
		if(t[k+1] == t[i]) k++;
		p[i] = k;
	}
	for(int i = 1; i< t.size(); i++){
		cout<<p[i]<<" ";
	}
	cout<<endl;
}
void KMP(){
	int k = 0;
	for(int i = 1; i< s.size()-1; i++){
		while ( k > 0 && t[k+1] != s[i]) k = p[k];
		if(t[k+1] == s[i]) k++;
		if(k == n){ 
			r++;
			//cout<<i-k+1<<" ";
			k = p[k];
		}
	}
}
int main(){
	in();
	// tim ki tu con doi
	map < char , int > Map;
	for(int i= 0 ;i < n ; i++){
		Map[t[i]]++;
		Map[s[i]]--;	
	}
	int  posS = -10, posT;
	for(int i= 0 ;i < n ; i++){
		if(Map[t[i]] == 1) // dau hieu cho thay can doi ki tu
			posT = i;
		if(Map[s[i]] == -1)
			posS = i;
	}
	if(posS >= 0) s[posS] = t[posT];
	// tao vong chuoi 
	for(int i = 0; i<n;i++){
		s+= s[i];
	}
	//cout<<s<<endl;
	s= string("-") + s;
	t= string("-") + t;
	xuLyHamTienTo();
	KMP();
	if(posS == -10) cout<<n*r<<endl;
	else cout<<r<<endl;
	return 0;
}