#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//find maximum increasing sequence
//dynamic programming

void findMaxSeq (int a [], int n){
	int t[n] = {0}; //contains the maximum value
	int x[n] = {0}; //contains the index from the value in above array comes from

    //assign the max value so far on every index
	for (int i = 0; i < n; ++i){
		t [i] = a [i];
		x [i] = i;
	}
	
	//finds the max value possible
	for (int i = 1; i < n; ++i){
		for (int j = 0; j < i; ++j){
			if (a [j] < a [i]){
			    int m  = max (t[i], t[j] + a[i]);
				if (m != t[i]){
    				t [i] = m;
    				x [i] = j;
				}
			}
		}
	}
	int max = 0, index = 0;
	for (int i =0; i < n; ++i)
		if (a [i] > max){
			max = a [i];
			index = i;
	}
	cout << "Max: " << t [index] << endl;
    cout << "T[]: " << endl;
    for (int i =0; i < n; ++i)
	    cout << t [i] << " ";
	    
    cout << endl << "X[]: " << endl;
    for (int i =0; i < n; ++i)
	    cout << x [i] << " ";
	
	
	//prints the sequence
	cout << endl << "Elements: " << endl;    
	int i = 0;
	do {
	    cout << a [index] << " ";
	    int temp = index;
		index = x [index];
		if (temp == index && index == 0)
		    break;
	}while (index < n);
	
}

int main (){
    int n = 7;
	int arr [n] = {4, 6, 1, 3, 8, 4, 6};
	
	cout << "Max# " << endl;
	findMaxSeq (arr, n);
	return 0;
}

