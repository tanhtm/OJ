#include <bits/stdc++.h>
using namespace std;
typedef pair < int , int > ii;
int n, t;
int h[100002];
int T[100002];
int L[100002];
int R[100002];
int main(){
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>h[i];
		//cout<<h[i]<<" ";
	}
	T[1] = 0;
	for(int i = 2;i<=n;i++){
		T[i] = T[i-1] + h[i];
	}
	R[1] = t / h[1] + 1;
	L[1] = (R[1] - 1)*h[1];

	for(int i= 2; i<= n ;i++){
		int x = L[i-1] + h[i];
		int y = T[i] + (R[i-1]-1)*h[i];
		if( x > y){
			L[i] = x;
			if(L[i] > t){
				int z = L[i] - t;
				if(z % h[i-1] == 0) z/= h[i-1];
				else{
					z/= h[i-1];
					z++;
				} 
				L[i] -= z*h[i-1];
			}

		}else{
			// ko doi 
		}

	}
	return 0;
}