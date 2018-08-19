#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int main(){
	int t;
	int mark[10001];
	cin>>t;
	for(int j =0;j<t;j++)
	{
		int n;
		cin>>n;
		int a=0,b=0;
		vector < int > B,A;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			A.push_back(x);
			mark[x]++;
			if(mark[x] == 2){
				B.push_back(x);
				mark[x] = 0;
			}
		}
		sort(B.begin(),B.end());
		for(int i= 0;i< n;i++) 
			mark[A[i]] = 0; // reset mang mark
		double m = double(B[0])/ B[1];
		m+= double(B[1])/B[0];
		int imin =0;
		for(int i =1;i< B.size()-1;i++){
			//cout<<m<<endl;
			double x = double(B[i])/B[i+1] + double(B[i+1])/B[i];
			if(x < m){
				m = x;
				imin = i;
			}
		}
		cout<<B[imin]<<" "<<B[imin]<<" "<<B[imin+1]<<" "<<B[imin+1]<<endl;
	}
	return 0;
}