#include<iostream>
using namespace std;
int k;
int xDP, yDP;
int main(){
	int x,y;
	while(true){
		cin>>k;
		if(k == 0) break;
		cin>>xDP>>yDP;
		for(int i= 0 ;i< k; i++){
			cin>>x>>y;
			if(x == xDP || y == yDP) cout<<"divisa";
			if(x < xDP && y > yDP ) cout<<"NO"; 
			if(x > xDP && y > yDP ) cout<<"NE"; 
			if(x > xDP && y < yDP ) cout<<"SE";
			if(x < xDP && y < yDP ) cout<<"SO"; 
			cout<<endl; 
		}
	}
    return 0;
}