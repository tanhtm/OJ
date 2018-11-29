#include <bits/stdc++.h>
using namespace std;
int GCD_extended(int a, int b, int &x, int &y){
	int u1, u2, u3, v1, v2, v3, t1, t2, t3;
	u1 = 1; u2 = 0; u3 = a;
	v1 = 0, v2 = 1; v3 = b;
	while(v3 != 0){
		int q = u3 / v3;
		t1 = u1 - q*v1;
		t2 = u2 - q*v2;
		t3 = u3 - q*v3;
		u1 = v1; u2 = v2; u3 = v3; 
		v1 = t1; v2 = t2; v3 = t3;
	}
	x = u1; y = u2;
	return u3;
}
int main(){
	int x,y,z;
	z = GCD_extended(34,23,x,y);
	printf("%d %d %d\n",x,y,z);
	return 0;
}