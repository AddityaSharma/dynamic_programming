/* here in this question, we have our array elements greater than 0 i.e 0 is not included so we ca solve 
it using the belwo mentioned algorithm , if we include 0 as our array element the we c=have to slightly modify 
this and use the algorithm used in the question "Partitions with given difference", we use this question(number 
of subsets) as a subroutine in the "partitions with given difference" question, and simultaneously handle the 
case of zeros. like test-case : {0, 0 ,0 ,1}*/

/*
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
*/

/*
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
*/

/*
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
*/

/*
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
*/
