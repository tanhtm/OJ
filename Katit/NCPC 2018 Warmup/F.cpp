#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	string A,B;
	cin>>A>>B;
	static bool b[27];
	char c;
	for(int i=0;i<B.size();i++) b[B[i]-'A'] = 1;
	for(int i=0;i<A.size();i++){
		if(b[A[i]-'A']){
			c = A[i];
			break;
		}
	}
	int iA,iB;
	for(int i=0;i<A.size();i++){
		if(c == A[i]) {
			iA = i;
			break;
		}
	} 
	for(int i=0;i<B.size();i++){
		if(c == B[i]) {
			iB = i;
			break;
		}
	}
	for(int i=0;i<B.size();i++){
		if(i == iB){
			cout<<A<<endl;
		}
		else{
			for(int j= 0;j<A.size();j++){
				if(j == iA) cout<<B[i];
				else cout<<'.';
			}
			cout<<endl;
		}
	}
	return 0;
}