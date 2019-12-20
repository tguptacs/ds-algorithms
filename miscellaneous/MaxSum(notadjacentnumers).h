#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMax (int arr[], int n){
	int in = arr [0];
	int ex = 0;
	int m = 0;
	
	for (int i = 1; i < n; ++i){
		m = in > ex ? in : ex;
		in = ex + arr [i];
		ex = m;
	}
	return in > ex ? in : ex;
}

int main (){
	int n = 6;
	int arr [n] = {5,  5, 10, 40, 50, 35};
	
	cout << "Max# " << findMax (arr, n) << endl;
	
	return 0;
}

