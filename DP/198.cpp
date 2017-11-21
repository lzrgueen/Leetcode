#include <iostream>
#include <vector>
using namespace std;

   int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        int dp[nums.size()];
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[nums.size()-1];
    }



int main(){
	vector<int> p1 = {2,5,13,6,4,21,5,14};


	cout << "MAX ROB OF p1 is "<< rob(p1) << endl;


	return 0;
}