#include <iostream>
#include <queue>
using namespace std;
struct Register{
	int Qnum;
	int Period;
	int realTime;
	Register(){};
	Register(int Q, int P){
		Qnum = Q;
		Period = P;
		realTime = Period;
	}
};
bool operator < (Register a, Register b){
	if(a.realTime != b.realTime) return a.realTime > b.realTime;
	return a.Qnum > b.Qnum;
}
priority_queue < Register > Q;
int main(){
	//freopen("data.txt","r",stdin);
	string s;
	int Qnum, Period;
	while(cin>>s && s!= "#"){
		cin>>Qnum>>Period;
		Q.push(Register(Qnum,Period));
	}
	int k;
	cin>>k;
	while(k != 0){
		Register r = Q.top();
		Q.pop();
		cout<<r.Qnum<<endl;
		r.realTime += r.Period;
		Q.push(r);
		k--;
	}
	return 0;
}