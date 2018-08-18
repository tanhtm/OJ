#include <iostream>
#include <queue>
using namespace std;
int n;
struct cmp
{
	bool operator () ( const int a,const int b){
		return a>b;
	}
};
priority_queue < int ,vector < int >, cmp > Q;
int main(){
	while( cin >> n && n != 0){
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			Q.push(x);
		}
		int res = 0;
		while(true){
			int a = Q.top();Q.pop();
			int b = Q.top();Q.pop();
			res+= a+b;
			if(Q.empty()){
			 	break;
			}
			Q.push(a+b);
		}
		cout<<res<<endl;
	}
	return 0;
}