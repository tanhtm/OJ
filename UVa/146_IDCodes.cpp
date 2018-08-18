#include<iostream>
#include<algorithm>
#include<vector>
#include <string.h>
#include <bitset>
using namespace std;
string s,stop("#");
void run(){
	string t = s;
	if (next_permutation(s.begin(),s.end()))
		cout<<s;
	else cout<<"No Successor";
	cout<<endl;
}
int main(){
	while(cin>>s && s != stop ){
		run();
	}
    return 0;
}