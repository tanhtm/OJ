#include <bits/stdc++.h>
using namespace std;
typedef pair < int , int > ii;
int n, t;
int h[100002];
int T[100002];
bool b[100002];
int main(){
	cin>>n>>t;
	h[0] = 0;
	b[0] = 0;
	for(int i=1;i<=n;i++){
		cin>>h[i];
		if(h[i] > h[i-1]) b[i] = 1;
		else b[i] = 0;
	}
	b[n+1] = 1;
	T[0] = 0;
	for(int i=1;i<=n;i++){
		T[i]= T[i-1] + h[i];
		//cout<<T[i]<<" ";
	}
	//cout<<endl;
	int x, y;
	x = y = 0;

	while(y != n){
		x = y;
		y++;
		while(b[x] != b[y]){
			y++;
			if(y == n) break;
		}
		if(b[x] == b[y]) y--;
		if(b[x] == 0){
			cout<<x<<" "<<y<<endl;
			if(x == 0) x++;
			for(int i = x;i<=y;i++){
				cout<<(t - T[i])/h[i] + 2<<endl;
			}
		}else{
			cout<<x<<" "<<y<<endl;
			for(int i = x+1;i<=y;i++){
				cout<<(t - (T[x] - h[x]) - (T[i] - T[x]))/h[x] + 1<<endl;
			}
		}
	}

	return 0;
}