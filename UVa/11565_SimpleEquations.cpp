#include <iostream>
#include <vector>
using namespace std;
int a,b,c;
void solve(){
	for(int x=-100;x<=100;x++){
		for(int y=-100;y <= 100;y++){
			int z = a - x - y;
			if(x == z || z == y || x == y) continue;
			if(x*y*z != b ) continue;
			if(x*x + y*y + z*z != c) continue;
			cout<<x<<" "<<y<<" "<<z<<endl;
			return;
		}
	}
	cout<<"No solution."<<endl;
}
int main(){
	//freopen("data.txt","r",stdin);
	int C;
	cin>>C;
	while(C--){
		cin>>a>>b>>c;
		solve();
	}
}