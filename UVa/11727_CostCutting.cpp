#include<iostream>
#include<algorithm>
using namespace std;
int c;
int a[3];
int main(){
	cin>>c;
	for(int i=0 ;i<c;i++){
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		cout<<"Case "<<i+1<<": "<<a[1]<<endl;
	}
    return 0;
}