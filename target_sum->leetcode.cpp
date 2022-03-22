class Solution {
public:

    // we have build this question on the question 'partitions with given difference - coding ninjas' and
    // 'subset sum - coding ninjas'. -> takeUforward
    
    int mod = 1e9+7;

    /*
    // memoization code:
    int subset(vector<int> &arr, int index, int target, vector<vector<int>> &dp){
        if(index == 0){
            if(target == 0 && arr[0] == 0) return 2;
            if(target == 0 || target == arr[0]) return 1;
            else return 0;
        }
        if(dp[index][target] != -1) return dp[index][target];

        int pick = 0;
        if(arr[index] <= target) pick = subset(arr, index-1, target - arr[index], dp);
        int not_pick = subset(arr, index-1, target, dp);

        return dp[index][target] = (pick + not_pick) % mod;
    }

    int findWays(vector<int> &nums, int k){
        vector<vector<int>> dp(nums.size(), vector<int>(k+1, -1));
        return subset(nums, nums.size()-1, k, dp);
    }

    int countPartitions(int n, int d, vector<int> &arr) {
        int sum = 0;
        for(int i=0; i<arr.size(); i++) sum += arr[i];
        if(sum-d < 0 || (sum-d)%2) return 0;
        return findWays(arr, (sum-d)/2);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(), target, nums);
    }
    */

    /*
    // tabulation code:
    int findWays(vector<int> &nums, int k){
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k+1, 0));
        if(nums[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        if(nums[0] != 0 && nums[0] <= k) dp[0][nums[0]] = 1;

        for(int index = 1; index < n; index++){
            for(int target = 0; target <= k; target++){
                int pick = 0;
                if(nums[index] <= target) pick = dp[index-1][target - nums[index]];
                int not_pick = dp[index-1][target];
                dp[index][target] = (pick + not_pick) % mod;
            }
        }

        return dp[n-1][k];
    }

    int countPartitions(int n, int d, vector<int> &arr) {
        int sum = 0;
        for(int i = 0; i<arr.size(); i++) sum += arr[i];
        if((sum-d) < 0 || (sum-d)%2 ) return 0;
        return findWays(arr, (sum-d)/2);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(), target, nums);
    }
    */

    /*
    // space-optimised code:
    int findWays(vector<int> &nums, int k){
        int n = nums.size();
        vector<int> dp(k+1, 0);
        if(nums[0] == 0) dp[0] = 2;
        else dp[0] = 1;
        if(nums[0] != 0 && nums[0] <= k) dp[nums[0]] = 1;

        for(int index = 1; index < n; index++){
            vector<int> temp(k+1, 0);
            for(int target = 0; target <= k; target++){
                int pick = 0;
                if(nums[index] <= target) pick = dp[target - nums[index]];
                int not_pick = dp[target];
                temp[target] = (pick + not_pick) % mod;
            }
            dp = temp;
        }

        return dp[k];
    }

    int countPartitions(int n, int d, vector<int> &arr) {
        int sum = 0;
        for(int i = 0; i<arr.size(); i++) sum += arr[i];
        if((sum-d) < 0 || (sum-d)%2 ) return 0;
        return findWays(arr, (sum-d)/2);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(), target, nums);
    }
    */    
    
    
    // --------------------------------------------------------------------------------------------- //
    
    
    // my personal solution: -> using map
    /*
    // recursive code:
    int f(int index, int target, vector<int> &nums){
        if(index == 0){
            if(nums[index] == 0 && target == 0) return 2;
            if((target + nums[index] == 0) || (target - nums[index] == 0)) return 1;
            return 0;
        }
        
        int addition = f(index-1, target+nums[index], nums);
        int subtraction = f(index-1, target-nums[index], nums);
        
        return addition + subtraction;        
    }
    
    
    int findTargetSumWays(vector<int>& nums, int T){
        return f(nums.size()-1, T, nums);
    }
    */

    /*
    // memoization code:
    int f(int index, int target, vector<int> &nums, map<pair<int, int>, int> &mp){
        if(index == 0){
            if(nums[index] == 0 && target == 0) return 2;
            if((target + nums[index] == 0) || (target - nums[index] == 0)) return 1;
            return 0;
        }
        if(mp.find({index, target}) != mp.end()) return mp[{index, target}];
        
        int addition = f(index-1, target+nums[index], nums, mp);
        int subtraction = f(index-1, target-nums[index], nums, mp);
        
        return mp[{index, target}] = addition + subtraction;        
    }
    
    
    int findTargetSumWays(vector<int>& nums, int T){
        map<pair<int, int>, int> mp;
        return f(nums.size()-1, T, nums, mp);
    }
    */
    
    // tabulation -> we cannot further tabulation the above written code because the values for
    // target will range from -1e6 to +1e6 and that will a total size of 1e12 and will cause TLE.
};
