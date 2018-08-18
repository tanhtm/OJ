#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <cstdio>
using namespace std;
int n,d,r;
int a[100],b[100];
int main(){
	while(cin>>n>>d>>r && n!=0){
		for(int i = 0; i< n;i++) cin>>a[i];
		for(int i = 0; i< n;i++) cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		int res= 0;
		for(int i = 0; i< n;i++){
			if(a[i] + b[n-i-1] > d){
				res+= (a[i] + b[n-i-1] - d)*r;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}