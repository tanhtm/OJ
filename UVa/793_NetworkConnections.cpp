#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <map>
using namespace std;
vector < int > par, rankR;
int n;
void Clear(){
	par.clear();
	rankR.clear();
}
int findSet(int i){
	if(par[i] == i) return i;
	par[i] = findSet(par[i]);
	return par[i]; 
}
bool isSameSet(int i, int j){
	return (findSet(i) == findSet(j));
}
void unionSet(int i, int j){
	i = findSet(i);
	j = findSet(j);
	if(i == j) return;
	if(rankR[i] > rankR[j]) par[j] = i;
	else {
		par[i] = j;
		if(rankR[i] == rankR[j]) rankR[j]++;
	}
}
void run(){
	cin>>n;
	string s;
	getline(cin,s);
	par.resize(n+1);
	rankR.resize(n+1);
	for(int i=1;i<=n;i++) par[i] = i;
	char ch;
	int x,y;
	int nSuc = 0, nUnsuc= 0;
	while(true){
		getline(cin,s);
		if(!s.size()) break;
		ch = s[0];
		x=y=0;
		int i = 2;
		for(;s[i] != ' ';i++){
			x*=10;
			x+=s[i]-'0';
		}
		i++;
		for(;i<s.size();i++){
			y*=10;
			y+=s[i]-48;
		}
		if(ch == 'c'){
			unionSet(x,y);
			//cout<<findSet(x)<<" "<<findSet(y)<<endl;
		}
		if(ch =='q'){
			//cout<<findSet(x)<<" "<<findSet(y)<<endl;
			if(isSameSet(x,y)) nSuc++;
			else nUnsuc++;
		}
	}
	cout<<nSuc<<','<<nUnsuc<<endl;
	Clear();
}
int main(){
	//freopen("data.txt","r",stdin);
	int c;
	//run();
	cin>>c;
	string s;
	getline(cin,s);
	getline(cin,s);
	while(c!=0){
		run();
		c--;
		if(c!=0) cout<<endl; 
	}
	return 0;
}