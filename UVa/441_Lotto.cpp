#include <iostream>
#include <vector>
using namespace std;
int n;
vector< int > a;
void in(){
	a.resize(n);
	for(int i=0 ;i< n;i++)
		cin>>a[i];
}
void solve(){
	for(int i=0;i<n-5;i++){
		for(int j=i+1;j<n-4;j++){
			for(int u = j+1;u<n-3;u++){
				for(int v = u+1;v<n-2;v++){
					for(int g = v+1;g<n-1;g++){
						for(int h = g+1;h<n;h++){
							cout<<a[i]<<" "<<a[j]<<" "<<a[u]<<" "<<a[v]<<" "<<a[g]<<" "<<a[h]<<endl;
						}
					}
				}
			}
		}
	}
}
int main(){
	bool b = false;
	while(cin>>n && n!=0){
		if(b) cout<<endl;
		else b= true;
		in();
		solve();
	}
	return 0;
}