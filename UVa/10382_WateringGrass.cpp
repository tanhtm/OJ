#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
struct Interval
{
	double Begin,End;
	Interval(double x, double y){
		Begin = x;
		End = y;
	}
};
bool operator < (Interval a, Interval b){
	if(a.Begin != b.Begin) return a.Begin< b.Begin;
	return a.End > b.End;
}
int  n;
double l, w;
vector < Interval > vecI;
int main(){
	freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);*/
	while(cin>>n>>l>>w){
		vecI.clear();
		for(int i=0;i<n;i++){
			double p,r;
			cin>>p>>r;
			double dx = sqrt(r*r - w*w/4); // AC lan 3 do kieu bien cua r la int
			double x,y;
			x = double(p) - dx;
			y = double(p) + dx;
			if(x< 0) x = 0; 
			if(y > l) y = l;
			vecI.push_back(Interval(x,y));
		}
		sort(vecI.begin(),vecI.end());
		/*for(int i =0 ;i< n;i++){
			cout<<vecI[i].Begin<<"-"<<vecI[i].End<<endl;
		}
		cout<<endl;*/
		double pos = 0;
		int d= 0;
		bool b = true;
		while(pos != l){
			double posMax = pos;
			for(int i = 0; i< n;i++){
				if(vecI[i].Begin <= pos && vecI[i].End >= pos) posMax = max(posMax, vecI[i].End);
			}
			if(posMax == pos){ // ko tim dc khoang lien ket 
				b = false;
				break;
			}
			pos = posMax;
			d++;
		}
		if(b) cout<<d<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}