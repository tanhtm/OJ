#include <bits/stdc++.h>
using namespace std;
int main() {
	int N;
	static int x[500005], f[500005];
	cin>>N;
	cin>>x[0];
	for (int i = 1; i < N; i++){
		int a;
		cin>>a;
		if(a < 0 ){
			x[i] = a;
		}else{
			if(x[i-1] < a) x[i-1] -= a;
			else x[i-1] = a- x[i-1];
		}
	}
	f[0] = x[0];
	f[1] = abs(x[0] - x[1]);
	for(int i=2;i<N;i++){
		int a = min(x[i] - x[i-1],x[i-1] - x[i]);
		a = f[i-2] - a;
		int b = max(f[i-1] - x[i] , x[i] - f[i-1]);
		a = max(a,b);
		f[i] = a;
		cout<<f[i]<<endl;
	}
	cout<<f[N-1]<<endl;
	return 0;
}