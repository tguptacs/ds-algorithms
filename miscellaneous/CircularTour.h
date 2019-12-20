// Input:
// 1
// 4
// 4 6 6 5 7 3 4 5
// Output:
// 1
{
#include<bits/stdc++.h>
using namespace std;
struct petrolPump
{
    int petrol;
    int distance;
};
int tour(petrolPump [],int );
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}

}
/*This is a function problem.You only need to complete the function given below*/
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/
/*You are required to complete this method*/
int tour(petrolPump a[],int n)
{
    int start = 0;
    int end = 1;

	int c = a [start].petrol - a[start].distance;
	while (c < 0 || start != end){
		while (c < 0 && start != end ){
			c -= a [start].petrol - a[start].distance;
			start = (start + 1)%n;
			
			if (start == 0)
				return -1;
		}
		c += a [end].petrol - a[end].distance;
		end = (end + 1)%n;
	}
    return start;
}
