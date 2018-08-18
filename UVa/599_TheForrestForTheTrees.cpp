// sai ngu ngoc // loi form output
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string v;
vector < string > dsPair;
vector < vector < int > >  dsk;
vector < bool > mark;
int dfs(int v){
	mark[v]= true;
	int count = 1;
	for(int i= 0 ;i<dsk[v].size();i++){
		int u = dsk[v][i];
		if(!mark[u]) count+= dfs(u);
	}
	return count;
}
void solve(){
	int d = 0;
	int dsd[26]; // ds ten dinh
	for(int i=0;i<v.size();i+=2){
		dsd[v[i]-'A'] = d;
		d++;
	}
	// d la so luon dinh
	dsk.resize(d);
	mark.resize(d);
	for(int i=0 ;i<dsPair.size();++i){
		int x = dsd[dsPair[i][1]-'A'], y= dsd[dsPair[i][3]-'A'] ;
		dsk[x].push_back(y);
		dsk[y].push_back(x);
	}
	/*for(int i = 0 ;i< dsk.size();i++){
		cout<<i<<": ";
		for(int j = 0;j<dsk[i].size();j++){
			cout<<dsk[i][j]<<" ";
		}
		cout<<endl;
	}*/
	int countTree = 0;
	int countAcorn = 0;
	for(int i = 0 ;i< d;i++){
		if(!mark[i]){ 
			if(dfs(i) == 1) countAcorn ++;
			countTree++;
		}
	}
	cout<<"There are "<<countTree - countAcorn<<" tree(s) and "<<countAcorn<<" acorn(s)."<<endl; //KO DC SAI format
}
int main(){
	int c;
	cin>>c;
	string s;
	while(c!=0){
		while(cin>>s && s[0]!='*') dsPair.push_back(s);
		cin>>s;
		v= s;
		solve();
		dsPair.clear();
		dsk.clear();
		mark.clear();
		c--;
	}
	return 0;
}