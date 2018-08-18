#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int n, k, m, t;
int table[21][21]; //table[i][j] la phan dien tich chung giua tower i va j
vector < int > towers;
int a[20],c;
bool b[21];
void Clear(){
	for(int i=1;i<=n;i++){
		b[i] = false;
		for(int j=1;j<=n;j++){
			table[i][j]=0;
		}
	}
}
void pre(){ // xu ly vung chung
	int t1, t2, x;
	for(int i = 0; i <t-1;i++){
		t1 = a[i];
		for(int j=i+1;j<t;j++){
			t2 = a[j];
			x = max(table[t1][t2],c);
			table[t1][t2] = x;
			table[t2][t1] = x;
		}
	}

}
void In(){
	towers.resize(n+1);
	for(int i = 1;i<=n;i++) cin>>towers[i];
	cin>>m;
	for(int i = 0; i< m;i++){
		cin>>t;
		for(int j= 0;j<t;j++) cin>>a[j];
		cin>>c;
		pre();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

};
int getSum(){
	int res = 0;
	for(int i=1;i<=n;i++){
		res+= towers[i];
		b[i] = true;
		for(int j = i-1;j>= 1;j--){
			res-=table[i][j];
		}
		//cout<<res<<" ";
	}
	//cout<<endl;
	return res;
}
void solve(){
	int maxSum = getSum();
	int x=0,y = n-k;
	while(x != y){
		int MinArea = maxSum;
		int idTowerMin = 1;
		for(int i=1; i<=n;i++){
			if(!b[i]) continue; // xoa roi
			// neu ma xoa tower i
			int tower = towers[i];
			for(int j=1;j<=n;j++){
				if(!b[j]) continue;
				tower-= table[i][j];
			}
			if(tower < MinArea){
				MinArea = tower;
				idTowerMin = i;
			}
		}
		cout<<idTowerMin<<endl;
		b[idTowerMin] = false;
		maxSum -= MinArea;
		x++;
	}
	cout<<maxSum<<endl;
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	while(cin>>n>>k && n != 0){
		Clear();
		In();
		solve();
	}
	return 0;
}