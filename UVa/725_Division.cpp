#include <iostream>
#include <vector>
using namespace std;
bool check(int x, int y){
	vector < bool > v(10);
	int z;
	if(x<=9999) v[0] = 1;
	while(x != 0){
		z = x%10;
		if(v[z]) return false;
		v[z] = 1;
		x/=10;
	}
	while(y != 0){
		z = y%10;
		if(v[z]) return false;
		v[z] = 1;
		y/=10;
	}
	return true;
}
int main(){
	//freopen("data.txt","r",stdin);
	int n;
	bool b = false;
	bool first = false;
	while(cin>>n && n != 0){
		if(first)cout<<endl;
		else first = true;
		b = false;
		for(int i= 1234; i<=98765/n;i++){
			int x = i*n;
			if(x<=9999) continue;
			if(check(i,x)){
				b = true;
				cout<<x<<" / ";
				if(i < 9999) cout<<0;
				cout<<i<<" = "<<n<<endl;
			}
		}
		if(b == false) cout<<"There are no solutions for "<<n<<"."<<endl;
	}
	return 0;
}