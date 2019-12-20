#include <iostream>
using namespace std;

int IsPower (int x, int y){
    if (x == 1)
        return (y == 1);
    int pow = 1;
    while (pow < y){
        pow *= x;
    }
    
    if (pow == y)
        return 1;
    return 0;    
}

int main() {
	int t = 0;
	cin >> t;
	while (t-- > 0){
	    int x, y;
	    cin >> x >> y;
	    
	    cout << IsPower (x, y) << endl;
	}
	return 0;
}