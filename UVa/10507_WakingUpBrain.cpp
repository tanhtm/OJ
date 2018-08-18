#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <map>
using namespace std;
int n,m;
string  wakeUp; // vung nao da tinh giac
vector < vector < int > > dsk;
queue < int > qWakeUp;
map < char , int > M;
bool in(){
	cin>>n;
	if(!cin) return false;
	cin>>m;
	cin>>wakeUp;
	dsk.resize(n+1);
	int d = 1;
	for(int i=0 ;i<m;i++){
		string s;
		cin>>s;
		if(M[s[0]] == 0){
			M[s[0]] = d;
			d++;
		}
		if(M[s[1]] == 0){
			M[s[1]] = d;
			d++;
		}
		int x = M[s[0]], y= M[s[1]];
		dsk[x].push_back(y);
		dsk[y].push_back(x);
	}
	return true;
}
int solve(){
	vector < int > vec(n+1); // vec[i] la so luong dinh ke voi dinh i da duoc thuc day
	for(int i = 0; i<3;i++) {
		int v = M[wakeUp[i]];
		qWakeUp.push(v);
		vec[v] = 3; // dnh dau dinh da thuc
	}
	int sv = 0; // so dinh da thuc day
	int sy = 0; // so nam
	while(!qWakeUp.empty()){
		int sz = qWakeUp.size();
		sv+= sz;
		if(sv == n)
			return sy;
		while(sz != 0){
			int u = qWakeUp.front(); qWakeUp.pop();
			for(int i = 0 ;i<dsk[u].size();i++){
				int v = dsk[u][i];
				if(vec[v] == 3) continue;
				vec[v]++;
				if(vec[v] == 3) qWakeUp.push(v);
			}
			sz--;
		}
		sy++;
	}
	return -1;
}
void Clear(){
	dsk.clear();
	M.clear();
	while(!qWakeUp.empty()) qWakeUp.pop();
}
int main(){
	//freopen("data.txt","r",stdin);
	while(in()){
		int r = solve();
		if(r == -1) cout<<"THIS BRAIN NEVER WAKES UP"<<endl;
		else cout<<"WAKE UP IN, "<<r<<", YEARS"<<endl;
		Clear();
	}
	return 0;
}