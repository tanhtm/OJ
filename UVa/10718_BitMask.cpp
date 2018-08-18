#include <iostream>
using namespace std;
long long int N,L,R;
int main(){
	freopen("data.txt","r",stdin);
	long long int x,ans;
	while(cin>>N>>L>>R){
		ans= 0;
		for(int i = 31; i>=0;i--){
			x = ans + (1LL<<i);
			if(N &(1LL<<i)){
				if(x <= L) ans+= (1LL<<i);
			}else{
				if(x <= R) ans+= (1LL<<i);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}//4294967296	