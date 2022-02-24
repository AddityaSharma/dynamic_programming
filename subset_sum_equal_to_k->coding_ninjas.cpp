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
