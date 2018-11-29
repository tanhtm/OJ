#include <bits/stdc++.h>
using namespace std;
int t,n;
vector < int > A;
set < int > S;
int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}
int DP(int i){
	if (i == n) return 0;
	if (i == 0) return min(A[i+1] - A[i] - 1 + DP(i+1), n - i + 1);
	return min(A[i+1] - A[i] - 1 + DP(i+1), n - i);
}
int main(){
	freopen("task.in","r",stdin);
	cin>>t;
	while(t--){
		cin>>n;
		int ANS = 0;
		S.clear();
		for(int i= 0; i< n;i++){
			int x;
			x = read();
			//cin>>x;
			S.insert(x);
		}
		ANS = n - S.size();
		n = S.size();
		S.insert(0);
		A = vector< int >(S.begin(), S.end());
		//cout<<DP(0)<<endl;
		cout<<DP(0)+ ANS<<endl;
	}
	return 0;
}