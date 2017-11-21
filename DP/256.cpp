#include<vector>
#include<iostream>
using namespace std;

    int minCost(vector<vector<int>>& costs) {
        if(costs.size()==0)
            return 0;
        if(costs[0].size()==0)
            return 0;
        int red = costs[0][0];
        int blue = costs[0][1];
        int green = costs[0][2];
        int tmp1 = red;
        int tmp2 = blue;
        int tmp3 = green;
        for(int i=1;i<costs.size();i++){
            tmp1 = costs[i][0] +min(blue,green);
            tmp2 = costs[i][1] +min(green,red);
            tmp3 = costs[i][2] +min(red,blue);
            red=tmp1;
            blue=tmp2;
            green=tmp3;
            
        }
        int res = min(red,blue);
        return min(res,green);
    }

    
 int main(){

 	vector<vector<int>> c1 = {{5,3,1},{2,4,3},{2,3,1},{6,2,4},{5,5,8}};
 	vector<vector<int>> c2 = {{2,3,4},{4,1,5},{6,7,1},{3,2,1},{2,4,2},{4,3,3},{1,4,2}};
 	cout<< "Ways for c1 are " << minCost(c1) << endl;
 	cout<< "Ways for c2 are " << minCost(c2) << endl;
 	return 0;

 }
