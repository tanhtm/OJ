#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int r,s;
int a[20000];
void input(){
	cin>>s;
	for(int i =0;i< s-1;i++){
		cin>>a[i];
	}
}
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	int b;
	cin>>b;
	int c = 1;
	while(c <= b){
		input();
		int sum = 0, ans = 0,lans = 0,rans= 1,l = 0,r = 1;
		for(int i= 0;i< s-1;i++){
			sum+= a[i];
			if(ans == sum){
				if(rans - lans < r -l){ // uu tien doan duong dai hon
					lans = l;
					rans = r;
				}
			}
			if(ans < sum){
				lans = l;
				rans = r;
				ans = sum;
			}
			if(sum < 0){ // bat dau 1 tuyen duong moi
				l = i+1;
				r = l+1;
				sum = 0;
			}else r++;
		}
		if(ans) printf("The nicest part of route %d is between stops %d and %d\n",c,lans+1,rans+1);
		else printf("Route %d has no nice parts\n",c);
		c++;
	}
	return 0;
}