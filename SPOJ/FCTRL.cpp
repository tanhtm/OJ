#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
long logOf5(long x){
    long res=0;
    while(x>=5){
        res++;
        x= x/5;
    }
    return res;
}
long getAns(long x){
    long l = logOf5(x);
    long res =0;
    for(int i=1;i<= l;i++){
        res+= x/pow(5,i);
    }
	return res;
}
int main() {
	long c,x;
	cin>>c;
	for(long i =0; i<c;i++){
		cin>>x;
		cout<<getAns(x)<<endl;
	}
	return 0;
}
