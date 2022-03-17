in the question we have '0' as our array element, now always remember one thing, if we have '0' in our array and we find something like subset with given sum -> then
we can have 2 ways in which the question can demand answer -> one is in bool format i.e yes/no, here '0' in our array will not create much problem as we need to find 
just one occurance of that sum, -> the second format is if count is asked in the question i.e number of subsets of gievn sum, in this scenario '0' can create problems
as if at index 0 we have '0' and we reach index 0 with target sum as 0, then we have 2 ways -> and we usually miss out on this -> so we have to modify the base case 
in the following format:
    if(index == 0){
        if(target == 0 && arr[0] == 0) return 2; // case to remember.
        if(target == 0 || target == arr[0]) return 1;
        else return 0;
    }


// this question demands us the answer in the form of yes/no, rather than in terms of count. -> code for the count version is after this code part.
/*
// recursive code :
bool subsetSumUtil(int index, int target, vector<int>& arr){
    if(target == 0) return true;
    if(index == 0) return (arr[0] == target);
        
    bool notTaken = subsetSumUtil(index-1,target,arr);
    bool taken = false;
    if(arr[index]<=target) taken = subsetSumUtil(index-1,target-arr[index],arr);
        
    return (notTaken||taken);
}

bool subsetSumToK(int n, int k, vector<int> &arr){
    return subsetSumUtil(n-1, k, arr);
}
*/

/*
// memoization code:
bool subsetSumUtil(int index, int target, vector<int>& arr, vector<vector<int>> &dp){
    if(target == 0) return true;
    if(index == 0) return (arr[0] == target);
    if(dp[index][target]!=-1) return dp[index][target];
        
    bool notTaken = subsetSumUtil(index-1,target,arr,dp);
    bool taken = false;
    if(arr[index]<=target) taken = subsetSumUtil(index-1,target-arr[index],arr,dp);
        
    return dp[index][target] = (notTaken||taken);
}

bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<vector<int>> dp(n,vector<int>(k+1,-1));   
    return subsetSumUtil(n-1 , k, arr,dp);
}
*/

/*
// tabulation code: 
bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    // base cases:
    for(int i=0; i<n; i++) dp[i][0] = true;
    if(arr[0]<=k) dp[0][arr[0]] = true;
    
    for(int index = 1; index<n; index++){
        for(int target= 1; target<=k; target++){
            bool notTaken = dp[index-1][target];
            bool taken = false;
            if(arr[index]<=target) taken = dp[index-1][target-arr[index]];
            dp[index][target] = (notTaken||taken);
        }
    }
    
    return dp[n-1][k];
}
*/

/*
// space optimization: 
bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<bool> dp(k+1 ,false);
    // base cases:
    dp[0] = 1;
    if(arr[0]<=k) dp[arr[0]] = true;
    
    for(int index = 1; index<n; index++){
        vector<bool> temp(k+1, false);
        temp[0] = 1; // need to to explicitly, understand properly.
        for(int target= 1; target<=k; target++){
            bool notTaken = dp[target];
            bool taken = false;
            if(arr[index]<=target) taken = dp[target-arr[index]];
            temp[target] = (notTaken||taken);
        }
        dp = temp;
    }
    
    return dp[k];
}
*/


//the following code returns the count of subsets wtih sum equal to target.

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
*/
