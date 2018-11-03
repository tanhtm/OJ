#include <bits/stdc++.h>
using namespace std;
typedef pair < int , int > dots;
#define x first
#define y second

int n;
dots A[100005];
set < dots > S;
double getDis(int i, int j){
	int a = A[i].x - A[j].x;
	a = a*a;
	int b = A[i].y - A[j].y;
	b = b*b;
	return sqrt(a + b);
}
int main(){
	freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	cin>>n;
	int r;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		A[i]= dots(x,y);
		if(A[i].x >= 2018)  r+=S.count(dots(A[i].x - 2018,A[i].y));
		r+=S.count(dots(A[i].x + 2018,A[i].y));
		if(A[i].y >= 2018)  r+=S.count(dots(A[i].x,A[i].y - 2018));
		r+=S.count(dots(A[i].x,A[i].y + 2018));
		if(S.count(dots(A[i].x + 1680,A[i].y + 1118))) r++;

		S.insert(A[i]);

	}
	sort(A,A+n);
	int r = 0;
	for(int i=0;i<n;i++){
		dots d = A[i]; // <-i
		/*// (2018,0) => abs(x-x1) = 2018
		//if(S.count(dots(abs(A[i].x - 2018),A[i].y))) r++;
		if(S.count(dots(abs(A[i].x + 2018),A[i].y))) r++;
		//if(S.count(dots(A[i].x,abs(A[i].y - 2018)))) r++;
		if(S.count(dots(A[i].x,abs(A[i].y + 2018)))) r++;
		// (1680 1118)
		//if(S.count(dots(abs(A[i].x - 1680),abs(A[i].y - 1118)))) r++;
		if(S.count(dots(abs(A[i].x + 1680),abs(A[i].y + 1118)))) r++;
		//if(S.count(dots(abs(A[i].x - 1118),abs(A[i].y - 1680)))) r++;
		if(S.count(dots(abs(A[i].x + 1118),abs(A[i].y + 1680)))) r++;
		//if(S.count(dots(abs(A[i].x - 1118),abs(A[i].y + 1680)))) r++;
		//if(S.count(dots(abs(A[i].x + 1118),abs(A[i].y - 1680)))) r++;
		//if(S.count(dots(abs(A[i].x - 1680),abs(A[i].y + 1118)))) r++;
		//(S.count(dots(abs(A[i].x + 1680),abs(A[i].y - 1118)))) r++;*/

	}
	cout<<r<<endl;
	//cout<<r/2<<endl;
	return 0;
}