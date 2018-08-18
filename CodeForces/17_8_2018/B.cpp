#include <iostream>
#include <vector>
using namespace std;
int main(){
	long long int n,k;
	cin>>n>>k;
	if(k <= n) {
		cout<<(k-1)/2<<endl;
		return 0;
	}
	long long int mid = k/2;
	mid++;
	if(mid > n){ 
		cout<<0<<endl;
		return 0;
	}
	cout<<(n-mid+1)<<endl;
	return 0;
}