#include <bits/stdc++.h>
using namespace std;
long long int UCLN(int x, int y) {
	if (y == 0)
		return x;
	return UCLN(y, x%y);
}
int main() {
	long long int a, b, x, y, min;
	cin>>a>>b>>x>>y;
	long long int uc = UCLN(x, y);
	x = x/uc;
	y = y/uc;
	min = a/x > a/y?a/y:a/x;
	cout<<min<<endl;
	return 0;
}