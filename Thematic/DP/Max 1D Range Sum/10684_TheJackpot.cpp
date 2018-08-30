#include <bits/stdc++.h>
using namespace std;
int n,res,sum,x;
int main(){
	while(cin>>n && n!=0){
		res= -2000;
		sum = 0;
		for(int i=0;i<n;i++){
			cin>>x;
			sum+= x;
			res = max(res, sum);
			if(sum < 0) sum = 0;
		}
		if(res > 0)
			printf("The maximum winning streak is %d.\n",res);
		else printf("Losing streak.\n");
	}
	return 0;
}