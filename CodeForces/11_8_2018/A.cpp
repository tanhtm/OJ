#include <iostream>
#include <math.h>
using namespace std;
int n, h,a,b,k;
int ta,fa,tb,fb;
void solve(){
	int res = 0;
	if(fa > b){
		res+= fa-b;
		fa = b;
	}
	if(fa < a){
		res+= a - fa;
		fa = a;
	} 
	if(fb > b){
		res+= fb-b;
		fb = b;
	}
	if(fb < a){
		res+= a - fb;
		fb = a;
	}
	
	if(fa != fb) res+= abs(fa - fb);
	res += abs (ta - tb);
	cout<<res<<endl;

}
int main(){
	//freopen("data.txt","r",stdin);
	cin>>n>>h>>a>>b>>k;
	for(int i = 0 ;i<k;i++){
		cin>>ta>>fa>>tb>>fb;
		solve();
	}
	return 0;
}