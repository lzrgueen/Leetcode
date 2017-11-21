#include <iostream>
#include <vector>
using namespace std;


int maxSum(vector<int> & array, int start, int end){
        if(start>end || start<0 || end>=array.size())
            return 0;
        if(start==end)
            return max(0,array[start]);
        int mid= (start+end)/2;
        int left = maxSum(array,start,mid-1);
        int right = maxSum(array,mid+1,end);
        int temp=0;
        int res=array[mid];
        for(int i=mid-1;i>=start;i--){
            temp += array[i];
            res += temp>=0? temp:0;
            temp = temp>=0? 0:temp;
        }
        temp=0;
        for(int i=mid+1;i<=end;i++){
            temp += array[i];
            res += temp>=0? temp:0;
            temp = temp>=0? 0:temp;
        }
        res = max(res,left);
        res = max(res,right);
        res = max(res,0);
        return res;
        

}


/*
	This solution is traditional solution, and is O(nlogn)
*/



int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        int n= prices.size();
        vector<int> dif(n-1,0);
        for(int i=1;i<n;i++){
            dif[i-1]=prices[i]-prices[i-1];
        }
        int maxProfit = maxSum(dif,0,n-2);
        return maxProfit;
}



/*
	This solution is O(n) and is better!
	*/

int maxProfit2(vector<int>& prices){
	int maxCur=0;
	int result =0;
	for(int i=1;i<prices.size();i++){
		maxCur = max(0,maxCur+= prices[i]-prices[i-1]);
		result = max(result,maxCur);
	}
	return result;
}

   

int main(){
	vector<int> p1 = {7,1,5,3,6,4};
	vector<int> p2 = {7,6,5,4,2,1};

	cout << "MAX PROFIT OF p1 with method 1 is "<< maxProfit(p1) << endl;
	cout << "MAX PROFIT OF p2 with method 1 is "<< maxProfit(p2) << endl;
	cout << "MAX PROFIT OF p1 with method 2 is "<< maxProfit2(p1) << endl;
	cout << "MAX PROFIT OF p2 with method 2 is "<< maxProfit2(p2) << endl;


	return 0;
}
