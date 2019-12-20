#include <iostream>
using namespace std;

// #Find power of 2^n
// #Get the power(2,sizeof(array)) and check the array against the bit representation
// #for finding all the possible subsets.


int pow (int a, int b){
	if (b == 1)
		return a;
	int x = pow (a, b/2);
	return x * x * (b%2 ? a : 1);
}


int main (){
	int x = 3;
	int y = 5;
	cout << "power: " << pow (x, y) << endl;
	
	return 0;
}

