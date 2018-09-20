#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200002;
typedef pair< int , int > ii;
int n,q;
int st[4*MAX_N];
ii tst[4*MAX_N];
map < int, int > M[MAX_N]; 

update()
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	cin>>n>>q;
	memset(st,0,sizeof st);
	int t,c,a,b,d;
	for(int i=0;i<q;i++){
		cin>>t;
		if(t==1){
			cin>>c>>a>>b;
			M[a][b] += c;
			update(1,1,n,ii(a,b));
		}else{
			cin>>d;
			cout<<get(1,1,n,d)<<endl;
		}
	}
	return 0;
