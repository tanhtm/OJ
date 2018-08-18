#include <iostream>
#include <queue>
using namespace std;
struct Int
{
	int value;
};
bool operator > (Int a, Int b){
	return a.value < b.value;
}
int main(){
	Int a,b;
	a.value = 5; b.value=8;
	if(a > b) cout<<a.value<<">"<<b.value<<endl;
	else cout<<a.value<<"<="<<b.value<<endl;
	return 0;

}