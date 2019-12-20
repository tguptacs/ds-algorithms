#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int findMaxSmallest (int n){
	int t = n;
	int i = 1;
	int b = n % 10;
	int last_bit = b;
	int last = b;
	do{
	   // int p = (pow(10,i));
		b = n % 10;
		if (b > last_bit){
			t = n/10 * (pow(10,i-1)) + last;
// 			t = (t * 10) + last;
			t = (t * 10) + b;
			break;
		}
		else if (last != b){
			last = last_bit*10 + b;
		    last_bit = b;
		}
		i++;
		n = n / 10;
	}while (n != 0);
	
	return t;
}


int main (){
	cout << "Max: " << findMaxSmallest (2936);
	return 0;
}
