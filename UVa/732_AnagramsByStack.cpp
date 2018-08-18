#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
string a,b;
int n;
void solve(string r, int i, int j, stack < char > Stack){
	if(j == n){
		cout<<r<<endl;
		return;
	} 
	if(i==n){
		if(Stack.top() == b[j]){
			r+='o';
			Stack.pop();
			j++;
			solve(r,i,j,Stack);
		}else{
			return;
		}
	}
	if(Stack.empty()){
		Stack.push(a[i]);
		i++;
		r+= 'i';
		solve(r,i,j,Stack);
		return;
	}
	if(Stack.top() != b[j]){
		if( i == n ) return;
		Stack.push(a[i]);
		i++;
		r+= 'i';
		solve(r,i,j,Stack);
		return;
	}
	if(Stack.top() == b[j]){
		stack < char > t = Stack;
		t.pop();
		solve(r+'o',i,j+1,t);
		Stack.push(a[i]);
		solve(r+'i',i+1,j,Stack);
	}
}
int main(){
	string r;
	stack < char > Stack;
	while(cin>>a){
		cin>>b;
		n = a.size();
		solve(r,0,0,Stack);
	}
	return 0;
}