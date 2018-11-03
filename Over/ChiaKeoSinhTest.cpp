#include <bits/stdc++.h>
using namespace std;
int n,sum,s = 0;
int a[202];
int f[20002][202];

void Rand(){
	srand (time(NULL));
	n = rand()%200 + 1;
	for(int i = 1;i<= n;i++){
		a[i] = rand()%200 + 1;
		s+= a[i];
	}
}
int dp(int w, int i){ 
	if(f[w][i] != -1) return f[w][i];
	if(i == 0) return 0;
	if(w == 0) return 0;
	if(w < a[i]) return f[w][i] = dp(w,i-1);
	int x1 = a[i]+ dp(w-a[i],i-1);
	int x2 = dp(w,i-1);
	return f[w][i] = max(x1,x2);
}
int main(){
	//freopen("data.txt","r",stdin);
	
	
	memset(f,-1,sizeof f);
	/*cin>>n;
	for(int i=1;i<=n;i++){
	 	cin>>a[i];
	 	s+=a[i];
	}*/
	string x = "08";
	cin>>x;
	string in = "input.";
	string out = "output.";
	Rand();
	in+= x;
	out+= x;
	freopen(in.c_str(),"w",stdout);
	cout<<n<<endl;
	for(int i=1;i<=n;i++){
	 	cout<<a[i]<<" ";
	}
	cout<<endl;
	freopen(out.c_str(),"w",stdout);
	sum = s;
	s/=2;
	s = dp(s,n);
	//cout<<s<<" "<<sum - s<<endl;	
	cout<< abs(s- sum + s)<<endl;
	return 0;
}