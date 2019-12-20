#include <iostream>
using namespace std;

int FindWays (int m, int n, int x){
    if (m*n <= x) 
        return (m*n == x);
    if (n >= x) 
        return (n == x); 
    if (x == 0)
        return 1;
    if (n == 0 || x < 0)
        return 0;
    int c = 0;
    for (int i = 1; i <= m; ++i){
        c += FindWays (m, n-1, x-i);
    }    
    return c;
}

int main() {
	int t = 0;
	cin >> t;
	while (t-- > 0){
	    int m, n, x = 0;
	    cin >> m >> n >> x;
	    
	    cout << FindWays (m, n, x) << endl;
	}
	return 0;
}