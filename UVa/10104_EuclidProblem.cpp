#include <bits/stdc++.h>
using namespace std;
void gcd_extended(int a, int b, int &x, int &y, int &d){
	int u1,u2,u3,v1,v2,v3,t1,t2,t3;
	u1 = 1; u2= 0; u3 = a;
	v1 = 0; v2= 1; v3 = b;
	while(v3 != 0){
		int q = u3/v3;
		t1 = u1 - q*v1;
		t2 = u2 - q*v2;
		t3 = u3 - q*v3;
		u1 = v1; u2= v2; u3= v3;
		v1 = t1; v2= t2; v3= t3;
	}
	x = u1; y = u2; d = u3;
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	int a,b,x,y,d;
	while(cin>>a>>b){
		gcd_extended(a,b,x,y,d);
		cout<<x<<" "<<y<<" "<<d<<endl;
	}

	return 0;
}