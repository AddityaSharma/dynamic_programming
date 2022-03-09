class Solution {
public: 
    /*
    // recursion code:
    int find_max(int index, vector<int> &nums){
        if(index == 0) return nums[index];
        if(index<0) return 0;
        
        int pick = nums[index] + find_max(index-2, nums);
        int notPick = 0 + find_max(index-1, nums);
        
        return max(pick, notPick);
    }
    
    int rob(vector<int>& nums) {
        return find_max(nums.size()-1, nums);
    }
    */

    /*
    // memoization code:
    int find_max(int index, vector<int> &nums, vector<int> &dp){
        if(index == 0) return nums[index];
        if(index<0) return 0;
        if(dp[index] != -1) return dp[index];
        
        int pick = nums[index] + find_max(index-2, nums, dp);
        int notPick = 0 + find_max(index-1, nums, dp);
        
        return dp[index] = max(pick, notPick);
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return find_max(nums.size()-1, nums, dp);
    }
    */
    
    /*
    // tabulation - Tuf :
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        dp[0] = nums[0];
        for(int i = 1; i<nums.size(); i++){
            int pick = nums[i];
            if(i>1) pick += dp[i-2];
            int notPick = 0 + dp[i-1];
            dp[i] = max(pick, notPick);
        }
        return dp[nums.size()-1];
    }
    */
    
    /*
    // space optimisation - Tuf : 
    int rob(vector<int>& nums) {
        int prev1 = nums[0];
        int prev2 = 0;
        for(int i = 1; i<nums.size(); i++){
            int pick = nums[i] + prev2;
            int notPick = 0 + prev1;
            int curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    */
};
