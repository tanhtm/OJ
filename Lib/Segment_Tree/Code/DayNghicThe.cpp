#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair < int , int > ii;
int n;
vector< int > a;
bool operator > (ii a, ii b){
	return a.first > b.first;
}
void input(){
	freopen("dataDNT.txt","r",stdin);
	cin>>n;
	for(int i=0; i<n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
}
void RoiRacHoa(){
	vector < ii > v;
	for(int i=0; i<n;i++) v.push_back(ii(a[i],i));
	sort(v.begin(),v.end());
	vector < int > b(n);
	int d = 1;
	for(int i = 0 ;i < n; i++){
		b[v[i].second] = d;
		if(v[i].first < v[i+1].first) d++;
	}
	for(int i = 0 ;i < n; i++) a[i] = b[i];
	for(int i = 0 ;i < n; i++) cout<<a[i]<<" ";
	cout<<endl;
}
// BIT
vector < int > bit;
void update(int id, int v){
	for(; id<= n; id+= id & -id)
		bit[id] += v;
}
int get(int id){
	int r = 0;
	for(; id > 0; id-= id & -id)
		r += bit[id];
	return r;
}
// IT

int solve (){
	int r =0;
	for (int i = n-1; i >=0 ; --i)
	{
		update(a[i],1);
		r+=get(a[i]-1);
		//cout<<r<<endl;
	}
	return r;
}
int main(){
	input();
	RoiRacHoa();
	bit.resize(n+1);
	cout<<solve();
	return 0;
}