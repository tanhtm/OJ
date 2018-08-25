#include <bits/stdc++.h>
using namespace std;
struct point
{	
	double x,y;
	point(){}
	point(double a, double b){
		x = a;
		y = b;
	}
};
int n;
point Points[101];
point getMid(point a, point b){
	return point((a.x+b.x)/2,(a.y+b.y)/2);
}
bool cmp(double a, double b){
	if(int(a*1000000) == int(b*1000000)) return true;
	return false;
}
typedef pair < point , point > pp;
double getKc(point p1, point p2){
	return (p2.x- p1.x)*(p2.x- p1.x) + (p2.y-p1.y)*(p2.y-p1.y);
}
pp getTam(point p1, point p2, double bk){
	pp res;
	double n = p1.x - p2.x, m= p1.y- p2.y;
	point mid = getMid(p1,p2); // lay trung diem
	double vp = bk*bk - getKc(mid,p1);
	vp /= (m/n + 1);
	vp = sqrt(vp);
	double b1 = mid.y - vp, b2 = mid.y + vp;
	double a1 = (m/n)*(mid.y-b1) + mid.x;
	double a2 = (m/n)*(mid.y-b2) + mid.x;
	res.first = point(a1,b1);
	res.second = point(a2,b2);
	return res;
}
bool checkAns(double x){
	for(int i=0;i<n;i++){
		for(int j= 0;j<n;j++){
			if(i==j) continue;
			pp r = getTam(Points[i],Points[j],x);
			point r1 = r.first, r2= r.second;
			bool c = true;
			for(int k = 0;k<n;k++){
				if(k == i || k == j) continue;
				double bk = getKc(r1,Points[k]);
				bk = sqrt(bk);
				if(bk > x){
					c = false;
					break;
				}
			}
			if(c == true) return true;
			c = true;
			for(int k = 0;k<n;k++){
				if(k == i || k == j) continue;
				double bk = getKc(r2,Points[k]);
				bk = sqrt(bk);
				if(bk > x){
					c = false;
					break;
				}
			}
			if(c == true) return true;
		}
	}
	return false;
}
double BS(double Min, double Max){
	if(cmp(Min,Max)) return Min;
	double mid = (Min + Max) /2;
	if(checkAns(mid)) return BS(Min,mid);
	return BS(mid,Max);
}
int main(){
	cin>>n;
	double x,y;
	for(int i= 0;i< n;i++){
		cin>>x>>y;
		Points[i] = point(x,y);
	}
	if(n == 1){ 
		printf("%.3lf\n",0.0);
		return 0;
	}
	cout<<BS(0,1e9)<<endl;
	return 0;
}