#include <bits/stdc++.h>
using namespace std;
int L, W;
int O[100], I[100], S[100];
int P;
string M;
static bool Grid[11][22]; // Grid[i][j] = 1 = Car
int getPosCar(int t,int l){ // lay o to lan l tai thoi gian t
	if(l %2 == 0) return (O[l] - t*S[l] + 20*t*I[l]) % I[l];
	return (O[l] + t*S[l]) % I[l];
}
void getGrid(int t){
	memset(Grid,0,sizeof Grid);
	for(int i=1;i<=L;i++){
		int start = getPosCar(t,i);
		while(start<= W){
			Grid[i][start] = 1;
			start+= I[i];
		}
	}
	/*for(int i=1;i<=L;i++){
		for(int j=0;j<W;j++){
			cout<<Grid[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;*/
}
bool Frog(int t, int c, int r) {
	//cout<<t<<c<<r<<endl;
	getGrid(t);
	if (c % 2 == 1) {
		for (int i = r; i < r + S[c] && i <= W; i++) {
			if (Grid[c][i] == 1)
				return 1;
		}
	} else {
		for (int i = r; i > r - S[c] && i >= 0; i--) {
			if (Grid[c][i] == 1)
				return 1;
		}
	}
	return 0;
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	cin>>L>>W;
	for (int i = 1; i <= L; i++) {
		cin>>O[i]>>I[i]>>S[i];
	}
	cin>>P>>M;
	int t = 0;
	int c = L + 1, r = P;
	while (1) {
		t++;
		if(t == M.size() + 1){
			 cout<<"squish"<<endl;
			 return 0;
		}
		char n = M[t - 1];
		//cout<<n<<endl;
		if (n == 'U') c--;
		if (n == 'D') c++;
		if (n == 'L') r--;
		if (n == 'R') r++;
		if (c == 0) {
			cout<<"safe"<<endl;
			exit(0);
		}
		if (c > L + 1) c = L + 1;
		if (Frog(t, c, r)) {
			cout<<"squish"<<endl;
			exit(0);
		}
	}
	return 0;
}