#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int A,B,C;
/*
x*y*z = b => 1
*/
int giaiPT2(int a, int b, int c){
	int del = b*b - a*c*4;
	if(del < 0) return 0;
	if(del == 0) return (b*-1)/(a*2);
	del = sqrt(del);
	return (b*-1+del)/(a*2);
}
void solve(){
	for(int x=-1817120;x<=1817120;x++){
		cout<<x<<endl;
		int y = giaiPT2(x*-1,(A-x)*x,B*-1);
		if(y == 0) continue; // y = 0 la ko tim dc nghiem
		int z = A - x - y;
		if(x*x + y*y + z*z != C) continue;
		cout<<x<<" "<<y<<" "<<z<<endl;
		return;
	}
	cout<<"No solution."<<endl;
}
int main(){
	//freopen("data.txt","r",stdin);
	int CC;
	cin>>CC;
	while(CC--){
		cin>>A>>B>>C;
		solve();
	}
}