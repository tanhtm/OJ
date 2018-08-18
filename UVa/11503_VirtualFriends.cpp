#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <map>
using namespace std;
typedef pair < string , string > ss;
int n,d; // d la so luong nguoi
map < string , int > mapName;
vector < ss > vPair; 
vector < int > par,nPeople;
void in(){
	cin>>n;
	string a,b;
	d= 1;
	mapName.clear();
	vPair.clear();
	for(int i=0;i<n;i++){
		cin>>a>>b;
		if(!mapName[a]){
			mapName[a] = d;
			d++;
		}
		if(!mapName[b]){
			mapName[b] = d;
			d++;
		}
		vPair.push_back(ss(a,b));
	}
}
void init(){
	nPeople.assign(d+1,1);
	par.resize(d+1);
	for(int i=1 ;i<=d;i++) par[i] = i;
}
int findRoot(int i){
	if(par[i] == i) return i;
	par[i] = findRoot(par[i]);
	return par[i];
}
void unionRoot(int i, int j){
	i = findRoot(i);
	j = findRoot(j);
	if(i == j) return;
	if(nPeople[i] > nPeople[j]){
		par[j] = i;
		nPeople[i] += nPeople[j];
	}else{
		par[i] = j;
		nPeople[j] += nPeople[i];
	}
}
void solve(){
	init();
	for(int i=0 ;i<n;i++){
		ss s = vPair[i];
		int x = mapName[s.first], y= mapName[s.second];
		unionRoot(x,y);
		x = findRoot(x);
		cout<<nPeople[x]<<endl;
	}
}
int main(){
	//freopen("data.txt","r",stdin);
	int c;
	cin>>c;
	while(c!=0){
		in();
		solve();
		c--;
	}
	return 0;
}