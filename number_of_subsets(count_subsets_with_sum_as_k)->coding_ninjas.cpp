in the question we have to count subsets in the given array such that the sum of elements is equal to k, here we have have two scenario:
-> one is when the array elements are greater than 0 i.e '0' is not included, so we can just simply solve this question using the following base case:
    if(target == 0) return 1;
    if(index == 0){
        if(target == arr[0]) return 1;
        else return 0;
    }
as we are not having 0's so this task is relatively easier.
    
-> second case is when the array elements can have '0', now having the question is slightly difficult and we use the following base case:
    if(index == 0){
        if(target == 0 && arr[0] == 0) return 2; // case to remember.
        if(target == 0 || target == arr[0]) return 1;
        else return 0;
    }
reason for different base case : if at index 0 we have '0' and we reach index 0 with target sum as 0, then we have 2 ways -> and we usually miss out on this.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
// case 1 -> we have all array elements greater than 0:
// recursive code:
int subset(vector<int> &arr, int index, int target){
    if(target == 0) return 1;
    if(index == 0){
        if(target == arr[0]) return 1;
        else return 0;
    }
    
    int pick = 0;
    if(arr[index] <= target) pick = subset(arr, index-1, target - arr[index]);
    int not_pick = subset(arr, index-1, target);
    
    return pick + not_pick;
}

int findWays(vector<int> &num, int tar){
    return subset(num, num.size()-1, tar);
}


// memoization code:
int subset(vector<int> &arr, int index, int target, vector<vector<int>> &dp){
    if(target == 0) return 1;
    if(index == 0){
        if(target == arr[0]) return 1;
        else return 0;
    }
    if(dp[index][target] != -1) return dp[index][target];
    
    int pick = 0;
    if(arr[index] <= target) pick = subset(arr, index-1, target - arr[index], dp);
    int not_pick = subset(arr, index-1, target, dp);
    
    return dp[index][target] = (pick + not_pick);
}

int findWays(vector<int> &nums, int k){
    vector<vector<int>> dp(nums.size(), vector<int>(k+1, -1));
    return subset(nums, nums.size()-1, k, dp);
}


// tabulation code:
int findWays(vector<int> &nums, int k){
    vector<vector<int>> dp(nums.size(), vector<int>(k+1, 0));
    // base cases:
    for(int i=0; i<nums.size(); i++) dp[i][0] = 1;
    if(nums[0] <= k) dp[0][nums[0]] = 1;
    
    for(int index = 1; index < nums.size(); index++){
        for(int target = 1; target <= k; target++){
            int pick = 0;
            if(nums[index] <= target) pick = dp[index-1][target - nums[index]];
            int not_pick = dp[index-1][target];
            dp[index][target] = (pick + not_pick);
        }
    }
    return dp[nums.size()-1][k];
}


// space optimised code:
int findWays(vector<int> &nums, int k){
    vector<int> dp(k+1, 0);
    // base cases:
    dp[0] = 1;
    if(nums[0] <= k) dp[nums[0]] = 1;
    
    for(int index = 1; index < nums.size(); index++){
        vector<int> temp(k+1, 0);
        temp[0] = 1;
        for(int target = 1; target <= k; target++){
            int pick = 0;
            if(nums[index] <= target) pick = dp[target - nums[index]];
            int not_pick = dp[target];
            temp[target] = (pick + not_pick);
        }
        dp = temp;
    }
    return dp[k];
}
    
-------------------------------------------------------------------------------------------------------------------------------------------------------------------

// case 2 -> we can have '0' as one of our array elements.
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

