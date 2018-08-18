#include <iostream>
#include <string>
using namespace std;
char C;
int rows,columns;
string s;
char bitMap[200][200];
string res;
string run(int rowI, int rowJ, int colI, int colJ ){
	string r;
	if(rowI == rowJ && colI == colJ){
		r+= bitMap[rowI][colI];
		return r;
	}
	int midRow = (rowI + rowJ)/2;
	int midCol = (colI + colJ)/2;
	char a,b,c,d;
	if(rowI == rowJ){ // 1 dong
		a = run(rowI,rowJ,colI,midCol);
		b = run(rowI,rowJ, midCol+1,colJ);
		if( a.size() == 1 ){
			res+= a[0];
			if(b.size() == 1)
				if(b[0] != a[0]) {
					res+=b[0];
					res = string('D') + res;
				}
				else res = res;
			else{} res += b;

			return a;
		}
		re+= 'D';
		return 'D'; 
	}
	if( colI == colJ ){
		a = run(rowI, midRow, colI, colJ);
		b = run(midRow+1, rowJ, colI, colJ);
		if( a == b){
			res+= a;
			return a;
		}
		re+= 'D';
		return 'D';  
	} // 1 cot
	a = run(rowI,midRow,colI,midCol);
	b = run(midRow+1,rowJ,colI,midCol);
	c = run(rowI,midRow, midCol+1,colJ);
	d = run(midRow+1,rowJ,midCol+1,colJ);
	if(a == b && b == c && c == d){
		if(a == 'D'){
			res+= 'D';
			res+= 
		}
	}
	return 'D';													
}
void BtoD(){
	int d = 0;
	for(int i = 0;i< rows;i++){
		for(int j= 0; j <columns;j++){
			bitMap[i][j] = s[d];
			d++;
		}
	}
	for(int i = 0;i< rows;i++){
		for(int j= 0; j <columns;j++){
			cout<<bitMap[i][j];
		}
		cout<<endl;
	}
	run(0,rows-1,0,columns-1);
}
void DtoB(){

}
int main(){
	freopen("data.txt","r",stdin);
	//freopen("dataOut.txt","w",stdout);
	while(cin>>C && C!= '#'){
		cin>>rows>>columns>>s;
		if(C == 'B') BtoD();
		else DtoB();
	}
	return 0;
}