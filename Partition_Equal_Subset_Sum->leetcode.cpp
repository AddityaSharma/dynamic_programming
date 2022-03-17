class Solution {
public:
    /*
    // recursive code:
    bool subsetSumUtil(int index, int target, vector<int>& arr){
        if(target == 0) return true;
        if(index == 0) return (arr[0] == target);

        bool notTaken = subsetSumUtil(index-1,target,arr);
        bool taken = false;
        if(arr[index]<=target) taken = subsetSumUtil(index-1,target-arr[index],arr);

        return (notTaken||taken);
    }
    
    bool canPartition(vector<int>& nums){
        int target = 0;
        for(int i=0; i<nums.size(); i++) target += nums[i];
        if(target%2 != 0) return 0;
        return subsetSumUtil(nums.size()-1, (target/2), nums);
    }
    */
    
    /*
    // memoization code:
    bool subsetSumUtil(int index, int target, vector<int>& arr, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(index == 0) return (arr[0] == target);
        if(dp[index][target] != -1) return dp[index][target];

        bool notTaken = subsetSumUtil(index-1,target,arr, dp);
        bool taken = false;
        if(arr[index]<=target) taken = subsetSumUtil(index-1,target-arr[index],arr, dp);

        return dp[index][target] = (notTaken||taken);
    }
    
    bool canPartition(vector<int>& nums){
        int target = 0;
        for(int i=0; i<nums.size(); i++) target += nums[i];
        if(target%2 != 0) return 0;
        int k = target/2;
        vector<vector<int>> dp(nums.size(), vector<int>(k+1, -1));
        return subsetSumUtil(nums.size()-1, k, nums, dp);
    }
    */
    
    /*
    // tabulation code:
    bool canPartition(vector<int>& nums){
        int target = 0;
        for(int i=0; i<nums.size(); i++) target += nums[i];
        if(target%2 != 0) return 0;
        int n = nums.size();
        int k = target/2;
        
        // subset sum equal to k.
        vector<vector<bool>> dp(n,vector<bool>(k+1,false));
        // base cases:
        for(int i=0; i<n; i++) dp[i][0] = true;
        if(nums[0]<=k) dp[0][nums[0]] = true;

        for(int index = 1; index<n; index++){
            for(int target= 1; target<=k; target++){
                bool notTaken = dp[index-1][target];
                bool taken = false;
                if(nums[index]<=target) taken = dp[index-1][target-nums[index]];
                dp[index][target] = (notTaken||taken);
            }
        }

        return dp[n-1][k];
    }
    */

    /*
    // space optimization:
    bool canPartition(vector<int>& nums){
        int target = 0;
        for(int i=0; i<nums.size(); i++) target += nums[i];
        if(target%2 != 0) return 0;
        int n = nums.size();
        int k = target/2;
        
        // subset sum equal to k.
        vector<bool> dp(k+1 ,false);
        // base cases:
        dp[0] = 1;
        if(nums[0]<=k) dp[nums[0]] = true;

        for(int index = 1; index<n; index++){
            vector<bool> temp(k+1, false);
            temp[0] = 1; // need to to explicitly, understand properly.
            for(int target= 1; target<=k; target++){
                bool notTaken = dp[target];
                bool taken = false;
                if(nums[index]<=target) taken = dp[target-nums[index]];
                temp[target] = (notTaken||taken);
            }
            dp = temp;
        }

        return dp[k];
    }
    */  
};
