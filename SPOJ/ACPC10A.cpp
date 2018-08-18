#include <iostream>
using namespace std;

int main() {

	int x=3,y=3,z=3;
	while(true){
        cin>>x>>y>>z;
        if(!x&&!y&&!z) break;
        if(x==y && y== z){
            cout<<"GP "<<z<<endl;
            continue;
        }
        if(y-x == z-y){
            cout<<"AP "<<z+(z-y)<<endl;
            continue;
        }
        if((double)y/x == (double)z/y){
            cout<<"GP "<<z*double(z/y)<<endl;
            continue;
        }
	}
	return 0;
}
