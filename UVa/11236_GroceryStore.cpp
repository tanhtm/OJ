#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
/*
With two items and three items, it still
seems quite a boring task to you, so now you are interested in finding possible prices of four items such
that the sum of the four prices is equal to the product of the four prices
*/
void print(int x){
	cout<<x/100<<".";
	x= x%100;
	if(x < 10) cout<<"0";
	cout<<x;
}
int main(){
	//int i = 0;
	for(int a = 1; a<=500;a++){
		for(int b = a; b<2000;b++){
			if(a+b>=2000) break;
			for(int c = b; c<2000;c++){
				int sum = a+b+c;
				if(sum>=2000) break;
				int pro = a*b*c;
				if(pro <= 1000000) continue;
				pro -= 1000000;
				sum *= 1000000;
				if(sum%pro!=0) continue;
				int d = sum/pro;
				if(d < c) continue;
				if(a+b+c+d > 2000) continue;
				print(a);
				cout<<" ";
				print(b);
				cout<<" ";
				print(c);
				cout<<" ";
				print(d);
				cout<<endl;
				//i++;
			}
		}
	}
	//cout<<i<<endl;
	return 0;
}