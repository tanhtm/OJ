#include <iostream>
#include <stack>
using namespace std;
const int nmax = 1000;
int n;
int a[nmax+1];
void solve(){
	int d = 1;
	stack < int > st;
	for(int i= 1; i<=n;i++){
		if(st.empty()){
			if(d > n){
				cout<<"No"<<endl;
				return;
			}
			st.push(d);
			d++;
		}
		while(a[i] != st.top()){
			if(d > n){
				cout<<"No"<<endl;
				return;
			}
			st.push(d);
			d++;
		}
		st.pop();
	}
	cout<<"Yes"<<endl;
}
int main(){
	//freopen("data.txt","r",stdin);
	while( cin >> n && n != 0){
		int x;
		while(cin>>x && x!=0){
			a[1] = x;
			for(int i=2;i<=n;i++) cin>>a[i];
			//cout<<a[n]<<endl;
			solve();
			
		}
		cout<<endl;
	}
	return 0;
}