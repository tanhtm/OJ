#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n;
int c[200001],p[200001];
bool mark[200001];
bool mark2[200001];
int dfs(int i){
	int cMin = 10000,v;
	while(!mark[p[i]]){
		i = p[i];
		mark[i] = true;
		if(cMin > c[i]){
			cMin = c[i];
			v = i;
		}
	}
	if(mark2[v]) return 
	return cMin;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) cin>>p[i];
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(!mark[i]) ans += dfs(i);
	}
	cout<<ans<<endl;
	return 0;
}