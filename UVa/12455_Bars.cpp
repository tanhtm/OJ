#include <iostream>
#include <vector>
using namespace std;
const int nMax = 1005;
int n,p;
int a[nMax];
bool F[nMax][nMax]; // F[i][j] true: tim dc tong bang j xet tu 0,i
/*
120
5
25 25 25 25 25
*/
void run(){
	cin>>n;
	cin>>p;
	for(int i = 1 ;i<= p;i++){
		cin>>a[i];
	}
	for(int i = 0; i<p;i++){
		F[i][0] = true;
	}
	F[0][0] = true;
	for(int i = 1 ; i<=n;i++ ){
		F[0][i] = false; 
	}
	for(int i = 1; i <= n;i++){
		for(int j = 1; j<=p ;j++){
			if(F[j-1][i]){
				F[j][i] = true;
				continue;
			}
			if(i < a[j]) F[j][i] = F[j-1][i];
			else{
				if(F[j-1][i-a[j]]) F[j][i] = true;
				else F[j][i]= false;
			}
		}
	}
	if(F[p][n]) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
int main(){
	//freopen("data.txt","r",stdin);
	int c;
	cin>>c;
	while(c--){
		run();
	}
	return 0;
}