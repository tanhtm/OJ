#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair < int , int > ii;
int m,n;
vector < int > votes; // votes[i] so phieu cua ben i
priority_queue < ii > QVote;
vector < int > MinVote;
vector < ii > listVote;
int getTop(){ // khac 1
	int v = 0,id;
	for(int i =2;i<=m;i++){
		if(v < votes[i]){
			v = votes[i];
			id = i;
		}
	}
	return id;
}
int  getMin(int id, int Min){
	int r = 1e9;
	for(int i=0;i<n;i++){
		if(listVote[i].second == id && listVote[i].first > Min) r = min(r,listVote[i].first);
	}
	return r;
}
int main(){
	//freopen("data.txt","r",stdin);
	cin>>n>>m;
	votes.resize(m+1);
	MinVote.resize(m+1);
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		if(x != 1) 
			QVote.push(ii(y,x));
		votes[1]++; // gia su ben 1 mua tat so phieu
		listVote.push_back(ii(y,x));
	}
	/*for(int i = 1;i<=m;i++){
		cout<<votes[i]<<" ";
	}
	cout<<endl;
	while(!QVote.empty()){
		cout<<QVote.top().first<<" "<<QVote.top().second<<endl;
		QVote.pop();
	}*/
	if(QVote.empty()){
		cout<<0<<endl;
		return 0;
	}
	while(true){
		if(QVote.empty()) break;
		ii t = QVote.top();	
		// gia su ko mua phieu t
		votes[1]--;
		votes[t.second]++;
		int x =  getTop();
		//cout<<x<<endl;
		if(votes[1] <= votes[x]){
			votes[1]++;
			votes[t.second]--;
			break;
		}
		if(MinVote[t.second] == 0) MinVote[t.second] = t.first;
		else MinVote[t.second] = min(MinVote[t.second],t.first);
		QVote.pop();
	}
	/*while(!QVote.empty()){
		cout<<QVote.top().first<<" "<<QVote.top().second<<endl;
		QVote.pop();
	}*/
	/*for(int i = 2;i<=m;i++) cout<<MinVote[i]<<" ";
	cout<<endl;*/
	while(QVote.size() > 1){
		int x = getTop();
		if(votes[1] - votes[x] >= 2) break;
		ii t1 = QVote.top();QVote.pop();
		ii t2 = QVote.top();QVote.pop();
		if(t1.first + t2.first <= MinVote[x]){
			QVote.push(t1);
			QVote.push(t2);
			votes[x]--;
			break;
		}
		// kiem tra xem co doi dc ko
		votes[1]--;
		votes[t1.second]++;
		votes[t2.second]++;
		votes[x]--;
		int y = getTop();
		if(votes[1] <= votes[y]){
			votes[1]++;
			votes[t1.second]--;
			votes[t2.second]--;
			votes[x]++;
			QVote.push(t1);
			QVote.push(t2);
			break;
		}
		QVote.push(ii(MinVote[x],x));
		MinVote[x] = getMin(x,MinVote[x]);
		if(MinVote[t1.second] == 0) MinVote[t1.second] = t1.first;
		else MinVote[t1.second] = min(MinVote[t1.second],t1.first);
		if(MinVote[t2.second] == 0) MinVote[t2.second] = t2.first;
		else MinVote[t2.second] = min(MinVote[t2.second],t2.first);
	}
	long long int res = 0;
	while(!QVote.empty()){
		//cout<<QVote.top().first<<" "<<QVote.top().second<<endl;
		res+=QVote.top().first;
		QVote.pop();
	}
	cout<<res<<endl;
	return 0;
}