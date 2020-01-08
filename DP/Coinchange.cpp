#include<iostream>

using namespace std;

int coinChange(vector A, int M){
	int *f;
	f = new int[M+1];
	int n = A.length; //number of kinds of coins
	
	//initialization
	f[0] = 0;
	
	int i,j;
	//f[1],f[2],...f[27]
	for(i = 1; i <= M; i++){
		f[i] = 1000; //INFINITY
		//last coin A[j]
		//f[i] = min{f[i-A[0]]+1,...,f[i-A[n-1]+1]}
		for(j = 0; j < n; ++j){
			if(i >= A[j] && f[i - A[j]] != 1000){
				f[i] = min(f[i - A[j]] + 1, f[i]);
			}
		}
	}
	if(f[M] == 1000){
		f[M] = -1;
	}
	return f[M];
}

