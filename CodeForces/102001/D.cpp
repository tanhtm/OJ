#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("PALIN.INP","r",stdin);
	//freopen("PALIN.OUT","w",stdout);
	int m,n;
	cin>>m>>n;
	int d = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			char c;
			cin>>c;
			if(c =='.'){
				if(i != 0 && i != m-1 && j!= 0 && j!= n-1) d++;
			}
		}
	}
	cout<<d<<endl;
	return 0;
}
