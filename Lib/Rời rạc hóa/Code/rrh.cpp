#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair < int , int > ii;
bool operator > (ii a , ii b){
	return a.first > b.first;
}
int main(){
	int n = 5;
	int a[]={100, 100, 2000, 1500, 900000};
	int b[5];
	vector < ii > v(n);
	for(int i=0; i<n;i++){
		v[i].first = a[i];
		v[i].second = i;
	}
	sort(v.begin(),v.end());
	for(int i=0; i<n;i++){
		cout<<v[i].first<<":"<<v[i].second << endl;
	}
	int d = 1;
	for(int i=0; i<n;i++){
		b[v[i].second] = d;
		if(v[i+1].first > v[i].first ) d++;
	}
	for(int i=0; i<n;i++){
		a[i]= b[i];
		cout<<a[i]<<" ";
	}

	return 0;
}
