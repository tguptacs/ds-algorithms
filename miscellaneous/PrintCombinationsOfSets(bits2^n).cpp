#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#print combinations/subsets of given set(numbers)
#Get the power(2,sizeof(array)) and check the array against the bit representation
#for finding all the possible subsets.

void printSet (int arr [], int n){
    if (n == 0)
        cout << 0;
	for (int i=0; i < n; ++i)
		cout << arr [i] << " ";
	cout << endl;
}

void printAllSets (int arr[], int n){
	int p = pow (2, n);
	
	int i = 0;
	while (i < p){
		int k = 0;
		int l = 0;
		int j = 0;
		int temp [n] = {0};
		while (k < n){
			j = (1 << k);
			if (i & j)
				temp [l++] = arr [k];
			k++;
		}
		printSet (temp, l);
		i++;
	}
}

int main (){
	int n = 4;
	int arr [n];
	for (int i = 0; i < n; ++i)
		arr [i] = i+1;
// 	printSet (arr, n);
	printAllSets (arr, n);
	
	return 0;
}

