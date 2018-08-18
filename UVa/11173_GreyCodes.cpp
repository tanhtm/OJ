#include<iostream>
#include<algorithm>
#include<vector>
#include <string.h>
#include <bitset>
using namespace std;
int p[8] = {0,1,3,2,6,7,5,4};
int n;
int getSizeBit( int a){
	int i = 0;
	while(a != 0){
		a >>= 1;
		i++;
	}
	return i;
}
int get(int k){
	if(k < 2) return p[k] ;
	int u = getSizeBit(k); // lay so bit cua k
	int m = ((1 << u) -1) >> 1 ; // tim mid cua so u bit
	int k2 = (m << 1) + 1 - k; // lay k2 la doi cua k qua mid
	int r = get(k2); // lap voi k2 be hon la doi xung voi k 
	return r +  (1 << (u-1)); // them bit 1 vao dau ket qua tim dc
}
int main(){
	cin>>n;
	for(int i=0;i< n;i++){
		int u,k;
		cin>>u>>k;
		cout<<get(k)<<endl;
	}
    return 0;
}