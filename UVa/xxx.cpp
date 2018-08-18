#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <cstdio>
#include <time.h> 
using namespace std;
int main(){
	clock_t t;
	t = clock();
	for(int i = 1; i<=100000000;i++){

	}
	t = clock() - t;
	printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
	return 0;
}