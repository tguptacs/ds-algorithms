#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//find max coloured region

// 1,1,0,0,0
// 0,1,1,0,1
// 0,0,0,1,1
// 1,0,0,1,1
// 0,1,0,1,1

int getVal (int (*a)[5], int i, int j, int r, int c){
	if (i > r || i < 0 || j > c || j < 0)
		return 0;
// 	cout << "checking visited, i: " << i << " " << "j: " << j << endl;
// 	cout << "checking visited, a[i][j]: " << a[i][j]  << endl;
	
	return a[i][j];
}

void traverse (int (*a)[5], int i, int j, int r, int c, int& s, int (*visited)[5]){
	if (i >= r || i < 0 || j >= c || j < 0)
		return;
	visited [i][j] = 1;
	s++;
// 	cout << "i: " << i << " " << "j: " << j << "visited: " << visited [i][j] << "size: " << s <<endl;
	int direction [][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
	for (int k = 0; k < 8; ++k){
		int ni = i + direction [k][0];
		int nj = j + direction [k][1];
        
        // cout << "ni: " << ni << " " << "nj: " << nj << "visitedcheck: " << visited [ni][nj] << endl;
		if (visited [ni][nj] == 0 && getVal (a, ni, nj, r, c) == 1){
	   // 	cout << "ni: " << ni << " " << "nj: " << nj << endl;

			traverse (a, ni, nj, r, c, s, visited);
		}

	}
// 			cout << "done " << endl;
}

int findMax (int (*a)[5], int r, int c){
	int max = 0;
	int visited[5][5] = {};
	for (int i = 0; i < r; ++i){
	   // cout << "changed row!" << endl;
	    
		for (int j = 0; j < c; ++j){
		  //  cout << "changed column!" << visited [i][j] << endl;
			int size = 0;
			if (getVal (a, i,j, r, c) == 1)
			    traverse (a, i, j, r, c, size, visited);
			cout << endl << "size: " << size << endl;
			max = size > max ? size : max;
			for (int i = 0; i < r; ++i)
	    		for (int j = 0; j < c; ++j)
	    		    visited [i][j] = 0;
// 			break;
		}
// 		break;
	}
	return max;
}

int main (){
    // int a[][5] = {{1,1,0,0,0},{0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
	int a[][5] = {{1,1,0,0,0},{0,1,1,0,1},{0,0,0,1,1},{1,0,0,1,1},{0,1,0,1,1}};
	cout << "Max: " << findMax (a, 5, 5);
	return 0;
}

