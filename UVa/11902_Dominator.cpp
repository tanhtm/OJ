#include <bits/stdc++.h>
using namespace std;
int t,n;
bool m[101][101] , r[101][101], dd[101];
void dfs(int x){
	dd[x] = 1;
	r[0][x] = 1;
	for(int i=0;i<n;i++){
		if(!m[x][i]) continue;
		if(!dd[i]){
			dfs(i);
		}
	}
}
void dfs(int x, int z){ // dfs bo qua dinh z
	if(x == z) return;
	dd[x] = 1;
	for(int i=0;i<n;i++){
		if(!m[x][i]) continue;
		if(!dd[i]){
			dfs(i,z);
		}
	}
}
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	cin>>t;
	for(int c=0;c<t;c++){
		printf("Case %d:\n",c+1);
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>m[i][j];
			}
		}
		memset(r,0,sizeof r);
		memset(dd,0,sizeof dd);
		dfs(0);
		for(int i=0;i<n;i++){
			if(!r[0][i]) continue;
			memset(dd,0,sizeof dd);
			dfs(0,i);
			for(int j= 0;j<n;j++){
				if(r[0][j] == 1 && dd[j] == 0) r[i][j] = 1;
			}

		}
		for(int i=0;i<n;i++){
			cout<<'+';
			for(int j=1;j<n+n;j++) cout<<'-';
			cout<<'+'<<endl<<'|';
			for(int j=0;j<n;j++){
				if(r[i][j]) cout<<'Y';
				else cout<<'N';
				if(j!=n-1) cout<<'|';
			}
			cout<<'|'<<endl;
		}
		cout<<'+';
		for(int j=1;j<n+n;j++) cout<<'-';
		cout<<'+'<<endl;
	}
	return 0;
}