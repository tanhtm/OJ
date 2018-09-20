#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int num[55];
char sign[55]; // sign[i] la dau nam truoc num[i]
int memo[55][55]; // memo[i][j] la ket qua dau '(' o trc so num[i] va ngoac ')' o sau num[j] 
map < int , bool > memoMap[55][55]; // memoMap[i][j][x] = T/F kiem tra xem gia tri x da xuat hien chua
void solveString(){
	n = 0;
	int x = 0;
	bool b = false;
	sign[0] = '+';
	for(int i=0;i<s.size();i++){
		if(s[i] >='0' && s[i] <= '9'){
			x*= 10;
			x+= s[i] -'0';
			b = true;
		}
		else{
			if(b){
				num[n] = x;
				n++;
				x = 0;
				b = false;
			}
			if(s[i] != ' ') sign[n] = s[i];
		}
	}
	num[n++] = x;
	/*for(int i=0;i<n;i++){
		cout<<sign[i]<<" "<<num[i]<<endl;
	}*/
}
int dp(int l, int r){
	if(l == r) return 0;
	if(memo[l][r] != -1) return memo[l][r];
	
	for(int i = l;i<=r;i++){
		for(int j = i;j<=r;j++){

		}
	}
}
void solve(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			memo[i][j] = -1;
			memoMap[i][j].clear();
		}
	}
	cout<<dp(0,n-1)<<endl;
}
int main(){
	freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);*/
	while(true){
		s = "";
		getline(cin,s);
		if(s == "") break;
		solveString();
		//cout<<s<<endl;
	}
	return 0;
}