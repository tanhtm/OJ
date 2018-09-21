#include <bits/stdc++.h>
using namespace std;
typedef pair < int , int > ii;
int n,m;
vector < string > grid; // grid[i][j] mo ta du lieu vong dat
vector < ii > cells; // cells[i] luu toa do cau hoi
vector < int > memoR; // memoR[i] luu dap an cua cells[i]
string s;
int memo [101][101]; // memo[i][j] = x danh dau 
int r;
void dfs (int x, int y, int i){
	if(x < 0 || x == n || y < 0 || y == m) return;
	if(grid[x][y] != 'W') return;
	if(memo[x][y] != -1) return;
	memo[x][y] = i; // danh dau da di qua
	r++;
	dfs(x-1,y,i);
	dfs(x+1,y,i);
	dfs(x,y-1,i);
	dfs(x,y+1,i);
	dfs(x+1,y+1,i);
	dfs(x-1,y+1,i);
	dfs(x-1,y-1,i);
	dfs(x+1,y-1,i);
}
void solve(){
	memset(memo,-1,sizeof memo);
	memoR.resize(cells.size());
	for(int i=0;i<cells.size();i++){
		r = 0;
		int x = cells[i].first, y= cells[i].second;
		if(memo[x][y] != -1) r = memoR[memo[x][y]];
		else
			dfs(x,y,i);
		memoR[i] = r;
		cout<<r<<endl;
	}
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	int t;
	cin>>t;
	getline(cin,s);
	getline(cin,s);
	while(t--){
		grid.clear();
		cells.clear();
		while(getline(cin,s) && !s.empty()){
			//cout<<s<<endl;
			if(s[0] == 'L' || s[0] == 'W'){
				grid.push_back(s);
				m= s.size();
			}
			else{
				int x,y;
				sscanf(s.c_str(),"%d %d",&x,&y);
				x--;
				y--;
				cells.push_back(ii(x,y));
			}
		}
		n = grid.size();
		//printf("%d %d\n",n,m);
		solve();
		if(t != 0)cout<<endl;
	}
	return 0;
}