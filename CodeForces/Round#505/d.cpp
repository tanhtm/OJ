#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	if(b == 0) return a;
	return gcd(b,a%b);
}
const int MAX = 707;
int n;
int A[MAX]; // Mang input
bool Left[MAX][MAX];// Left[i][j] la doan tu i -> j co the tao thanh BST la nhanh ben trai cua A[j]
bool Right[MAX][MAX]; // Right[i] la doan tu i -> j co the tao thanh BST la nhanh ben phai cua A[i]
bool GCD[MAX][MAX]; // GCD[i][j] == 1 => gcd(A[i][i]) > 1
bool F[MAX][MAX]; // co the tao cay BST tu i -> j
void input(){
	cin>>n;
	A[0] = 0;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		GCD[i][i] = true;
	}

}
void solve(){ //DP
	for(int i= 1;i<=n;i++){
		Right[i][i] = Left[i][i] = true;
		GCD[i][i] = GCD[i][i] =  true;
	}
	for(int i= 1;i<=n;i++){
		for(int j= 1;j<=n;j++){
			if(i == j) continue;
			if(gcd(A[i],A[j]) > 1) GCD[i][j] = GCD[j][i] =  true;
			else GCD[i][j] = GCD[j][i]= false;
		}
	}
	for(int l = n;l >= 1 ;l--){
		for(int r = l;r <= n; r++){
			for(int mid = l; mid <= r; mid++){
				if(Left[l][mid] && Right[mid][r]){
					F[l][r] = true;
					Right[l-1][r] |= GCD[mid][l-1];
					Left[l][r+1] |= GCD[mid][r+1];
				}
			}
		}
	}
	if(F[1][n]) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
int main(){
	input();
	solve();
	return 0;
}