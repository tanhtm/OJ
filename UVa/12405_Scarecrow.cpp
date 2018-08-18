#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <cstdio>
using namespace std;
int t, n;
string s;
int main(){
	/*freopen("data.txt","r",stdin);
	freopen("dataOut.txt","w",stdout);*/
	cin>>t;
	int c = 0;
	while(c != t){
		c++;
		cin>>n>>s;
		int r =0;
		for(int i=1;i< n;i++){

			if(s[i-1] == '#') continue; 
			s[i] = 'T';
			r++;
			i+=2;
		}
		if(n >= 2 && s[n-1] == '.' && s[n-2] != 'T') {
			s[n-1] = 'T';
			r++;
		}
		//cout<<s<<endl;
		printf("Case %d: %d\n",c,r);
	}
	return 0;
}