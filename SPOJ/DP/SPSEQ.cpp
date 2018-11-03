#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9 + 7;
int n;
int a[100005];
int L[100005]; //L[i] do dai day con tang lon nhat tinh tu 1 - > i voi so ket thuc la a[i]
int R[100005]; //R[i] do dai day con giam lon nhat tinh tu i - > n voi so bat dau la a[i]
void dp(int x[]){
	vector < int > H(n+1,oo); // H[i] la gia tri ket thuc nho nhat de co day con tang co do dai i
	H[0]= -1;
	for(int i=1;i<=n;i++){
		int p = lower_bound(H.begin(), H.end(), a[i]) - H.begin(); // vi tri dau tien gap so  >= a[i]
		// p chinh la do dai day con lon nhat tang ket thuc boi a[i]
		//cout<<a[i]<<" "<<H[p]<<endl;
		H[p] = min(H[p],a[i]);
		x[i]= p;
	}
	/*for(int i=1;i<=n;i++){
		cout<<H[i]<<" ";
	}
	cout<<endl;*/
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		L[i] = oo;
		R[i] = oo;
	} 
	dp(L);
	reverse(a+1,a+n+1);
	dp(R);
	reverse(R+1,R+n+1);
	/*for(int i=1;i<=n;i++) cout<<L[i]<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++) cout<<R[i]<<" ";
	cout<<endl;*/
	int r = 1;
	for(int i=1;i<=n;i++){
		int x = min(L[i],R[i]); // n+1 tang, n+1 giam
		x= x+x-1;// lap lai a[i]
		if(x % 2 == 0) x--; // Do dai le
		r= max(r,x);
	}
	cout<<r<<endl;
	return 0;
}