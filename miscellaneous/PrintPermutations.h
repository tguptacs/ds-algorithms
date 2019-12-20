#include <iostream>
using namespace std;


void swap (char *a, char* b){
	char temp = *a;
	*a = *b;
	*b = temp;
}

void printPermuations (char a[], int i, int n){
	if (i == n){
		cout << a[0] << a[1] << a [2] << endl;
		return;
	}
	
	for (int in = i; in < n; ++in){
		swap (a[in], a[i]);
		printPermuations (a, i+1, n);
		swap (a[in], a[i]);
	}
}


int main (){
	char a [3] = {'a','b','c'};
	printPermuations (a, 0, 3);
	return 0;
}
