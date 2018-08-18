// greedy : load balancing
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair < int , int > ii;
struct Set
{
	ii a,b;
	double C;
	Set(ii x, ii y){
		a = x;
		b = y;
		C = a.first + b.first;
		if(a.second > b.second) swap(a,b);
	}
};
bool operator < (Set x, Set y){
	return x.a.second < y.a.second;
}
int c,s;
double A,C,IMBALANCE;
vector < ii > m;
vector < Set > S;
int main(){
	//freopen("data.txt","r",stdin);
	int d = 0;
	while(cin>>c>>s){
		d++;
		A = 0;
		printf("Set #%d\n",d);
		m.resize(2*c);
		for(int i=0;i<c*2;i++)
			m[i] = ii(0,i);
		for(int i=0;i<s;i++){
			int x;
			cin>>x;
			m[i] = ii(x,i);
			A+=x;
		}
		IMBALANCE = 0;
		A = A/c;
		sort(m.begin(),m.end());
		S.clear();
		for(int i = 0 ; i< c;i++){
			S.push_back(Set(m[i],m[c*2-1-i]));
		}
		sort(S.begin(),S.end());
		for(int i = 0 ; i< c;i++){
			printf(" %d:",i);
			ii a = S[i].a, b = S[i].b;
			if(a.first != 0) printf(" %d",a.first);
			if(b.first != 0) printf(" %d",b.first);
			IMBALANCE+= abs(S[i].C - A);
			cout<<endl;
		}
		printf("IMBALANCE = %.5lf\n\n",IMBALANCE);
	}
	return 0;
}