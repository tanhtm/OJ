#include <iostream>
#include <queue>
using namespace std;
vector < vector< int > > vT,pT;
vector < int > p,v;
int m,n;
int main(){
	freopen("data.txt","r",stdin);
	while(cin>>m>>n){
		vT.clear();
		pT.clear();
		vT.resize(n+1);
		pT.resize(n+1);
		int r;
		for(int i= 1 ;i<=m;i++){
			cin>>r;
			p.clear();v.clear();
			if(r == 0) continue;
			for(int j = 0; j<r;j++){
				int x;
				cin>>x;
				p.push_back(x);
			}
			for(int j = 0; j<r;j++){
				int x;
				cin>>x;
				v.push_back(x);
			}
			for(int j = 0; j<r;j++){
				vT[p[j]].push_back(v[j]);
				pT[p[j]].push_back(i);
			}
		}
		cout<<n<<" "<<m<<endl;
		for(int i= 1; i<=n;i++){
			r = pT[i].size();
			cout<<r;
			for(int j = 0; j < r; j++)
				cout<<" "<<pT[i][j];
			cout<<endl;
			for(int j = 0; j < r; j++){
				cout<<vT[i][j];
				if(j != r - 1) cout<<" "; // ko duoc thu dau cach >.<
			}
			cout<<endl;
		}
	}
	return 0;
}