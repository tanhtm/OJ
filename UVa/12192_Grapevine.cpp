#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, q;
int region[505][505];
typedef pair < int , int > ii;
bool in(){
	cin>>n>>m;
	if(n == 0) return false;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>region[i][j];
	return true;
}
int bsHorizon(int i, int l, int r, int v){
	if( l == r ) return l;
	int mid = (l+r)/2;
	if(region[i][mid] >= v) return bsHorizon(i,l,mid,v);
	return bsHorizon(i,mid+1,r,v);
}
void solve(int a, int b){
	int res = 0;
	for(int i=0;i<n;i++){
		int j = bsHorizon(i,0,m-1,a);
		if(j == m-1 && region[i][j] < a) continue;
		int Max = min(n-i-1, m-j-1); // chieu cao cua duong cheo max nhat co the tu i j
		int xi = i+Max, xj = j+Max;
		while(region[xi][xj] > b){
			xi--;
			xj--;
		}
		res = max(res, xi-i+1);
	}
	cout<<res<<endl;
}
void query(){
	int a,b;
	cin>>q;
	for(int i = 0;i< q;i++){
		cin>>a>>b;
		solve(a,b);
	}
	cout<<"-"<<endl;
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	while(in()){
		query();
	}
	return 0;
}