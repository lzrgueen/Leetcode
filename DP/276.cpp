#include<vector>
#include<iostream>
using namespace std;

    int numWays(int n, int k) {
        if(n==0 || k==0)
            return 0;
        int dp1[n];//not same
        int dp2[n];// same
        dp1[0]=k;
        dp2[0]=0;
        for(int i=1;i<n;i++){
            dp1[i] = (dp1[i-1]+dp2[i-1]) *(k-1);
            dp2[i]=dp1[i-1];
        }
        return dp1[n-1]+dp2[n-1];
    }
    
 int main(){

 	cout<< "Ways for 13 fences and 5 colors are " << numWays(13,5) << endl;
 	cout<< "Ways for 4 fences and 4 colors are " << numWays(4,4) << endl;
 	return 0;

 }