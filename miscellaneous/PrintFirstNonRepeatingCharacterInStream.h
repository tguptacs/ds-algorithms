////First non-repeating character in a stream
// Input:
// 2
// 4
// a a b c
// 3
// a a c
// 
// Output:
// a -1 b b
// a -1 c


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printFirstNonRepeatingCharacter (char a[], int n){
    list <char> l;
    map <char, pair<bool, list <char>::iterator> > m;
    list<char>::iterator it;
    m.clear ();
    for (int i = 0; i < n; ++i){
        char x = a[i];

        if (m.find (x) != m.end ()){
            if (m [a [i]].first == false){
                list <char>::iterator it = m [a[i]].second;
                l.erase (it);
                m [a [i]].first = true;
            }
        }
    	else{
    		l.push_back (x);
    		list <char>::iterator it = l.end ();
    		--it;
    		pair <bool, list<char>::iterator> p (false, it);
    		m.insert (make_pair (x, p));
    	}
    	if (l.empty ())
    		cout << -1 << " ";
    	else	
    	    cout << l.front () << " ";
    }
}

int main() {
	int test = 0;
	cin >> test;
	
	while (test -- > 0){
	    int n = 0;
	    cin >> n;
	    char a [n] = {'\0'};
	    for (int i = 0; i<n ; ++i) cin >> a [i];
	    printFirstNonRepeatingCharacter (a, n);
	    cout << endl;
	}
	return 0;
}