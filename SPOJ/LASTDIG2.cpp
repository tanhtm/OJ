#include <iostream>
#include <math.h>
using namespace std;
long a, b;
long getLastDig(long a, long b){
    if(b<=10) return long(pow(a,b))%10;
    long i = getLastDig(a,b/2);
    i= i*i;
    if( b%2 != 0) i*= a;
    return i%10;
}
int main() {
    long c;
	cin>>c;
	for(long i =0; i<c;i++){
		cin>>a>>b;
		a= a%10;
		cout<<getLastDig(a,b)<<endl;
	}
	return 0;
}


