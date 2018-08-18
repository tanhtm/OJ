#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
float h,u,d,f;
float hight;
int main(){
	while(cin>>h>>u>>d>>f && h != 0){
		int day = 0;
		hight = 0;
		float drop = u*f/100;
		while(true){
			day++;
			hight+= u;
			if(hight > h){
				cout<<"success on day "<<day<<endl;
				break;
			}
			hight-=d;
			if(hight < 0){
				cout<<"failure on day "<<day<<endl;
				break;
			}
			if(u > 0 ) u -= drop;
		}
	}
    return 0;
}