#include <bits/stdc++.h>
using namespace std;
const int MAX = 300005;
int n, L[MAX],R[MAX],A[MAX],B[MAX];
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>L[i]>>R[i];
		A[i] = L[i];
		B[i] = R[i];
	}
	sort(L,L+n);
	sort(R,R+n); //R lay min
	reverse(L,L+n); // L lay max;
	int ans = 0;
	ans = max(ans, R[0] -L[0]);
	int isPair = false;
	for(int i=0;i<n;i++){
		if(L[0] == A[i] && R[0] == B[i]){
			isPair = true;
			break;
		}
	}
	if(isPair)
		ans = max(ans, R[1]- L[1]);
	else{
		ans = max(ans, R[0] - L[1]);
		ans = max(ans, R[1] - L[0]);
	}
	cout<<ans<<endl;
	return 0;	
}