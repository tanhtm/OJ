#include <bits/stdc++.h>
using namespace std;
typedef struct
{
	int x;
	int r;
	int q;
} Robot;
bool compare(const Robot &a, const Robot &b) {
	if(a.q != b.q)	return a.q < b.q;
	if(a.x != b.x) 	return a.x < b.x;
	return a.r < b.r;
}
int n,k;
Robot robots[100005];
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>robots[i].x>>robots[i].r>>robots[i].q;
	}
	sort(robots,robots+n, compare);
	for(int i=0;i<n;i++){
		//cout<<robots[i].q<<endl;
		if(abs(robots[i].q - robots[i+1].q) > k) continue;
	}

	return 0;
}