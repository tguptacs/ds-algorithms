#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector <int**> v;
// #print combinations/subsets of given set(numbers)
// #for every input, divide (include element from source and exclude element)
// #{} {123} --> {1}{23},               {}{23}
// #         {12}{3}, {1}{3}        {2}{3}, {}{3}
// # .......


void includeExclude (int d[], int j, int s[], int i, int n){
	if (i == n){
        if (j == 0)
            cout << 0 << " ";
	    
		for (int i = 0; i< j; ++i)
	        cout << d [i] << " ";
	    cout << endl;     
		return;
	}
	includeExclude (d, j, s, i+1, n); //exclude element from source set
	d [j] = s [i];
	includeExclude (d, j+1, s, i+1, n); //inlcude element from source set
}

void printAllSets (int arr[], int n){
	int d [n] = {0};
	includeExclude (d, 0, arr, 0, n);
}

int main (){
	int n = 8;
	int arr [n];
	for (int i = 0; i < n; ++i)
		arr [i] = i+1;
	printAllSets (arr, n);
	
	return 0;
}

