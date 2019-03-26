#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//数组中最大的元素大于其它所有元素的 2倍 
int dominantIndex(vector<int>& nums) {
        int len = nums.size();
        if(len <= 0){
            return -1;
        }
        int maxNum = 0;
        int index = 0;
        for(int i = 0; i < len; ++i){
            if(nums[i] > maxNum){
                maxNum = nums[i];
                index = i;
            }
        }
        //cout << maxNum << index <<endl; 
        for(int j = 0; j < len; ++j){
            if(maxNum < nums[j]*2 && nums[j] != maxNum){
            	cout << nums[j];
                return -1;
            }
        }
        return index;
    }
 //最长子序和
  int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len <= 0){
            return 0;
        }
        int dp[len];
        dp[0] = nums[0];
        int result = nums[0];
        for(int i = 1; i < len; ++i){
            if(dp[i-1] < 0){
                dp[i] = nums[i];
            }
            else{
                dp[i] = dp[i-1] + nums[i];
            }
            result = max(dp[i], result);
        }
        return result;
    }
  
 int main(){
 	vector<int> s;
 	int n , temp;
 	while(cin >> n){
	 	for(int i = 0; i< n; ++i){
	 		cin >> temp;
	 		s.push_back(temp);
	 	}
 		//cout << dominantIndex(s) << endl;
 		cout << maxSubArray(s) << endl;
	 }
 	
 	return 0;
 }