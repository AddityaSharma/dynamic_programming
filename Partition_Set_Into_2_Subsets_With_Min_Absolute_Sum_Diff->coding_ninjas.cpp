// this solution is a important to remember -> based upon the question 'subset sum equal to K' -> striver:
int minSubsetSumDifference(vector<int>& arr, int n){
    int k = 0; // 'k' implies total_sum
    for(int i=0; i<n; i++) k += arr[i];
    
    // code from 'subset sum equal to K' (space-optimsed)
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
    
    // in the last row of matrix, i.e the row dp will tell us the valid subset sum we can
    // have in the entire array, i.e by picking some permutations of elements wat all value
    // of sum we can achieve.
    int min_diff = INT_MAX;
    for(int sum = 0; sum <= k; sum++){
        if(dp[sum] == 1){  // dp[sum] = 1 implies by picking some elements from array we can achive that value of sum
            min_diff = min(min_diff, abs(2*sum - k));
        }
    }
    
    return min_diff;
}

----------------------------------------------------------------------------------------------------------------------------------------------------------------
// this is my personal solution and is not based upon any other question.
// simple idea : if s1+s2 = s -> s2 = s- s1, and abs(s1-s2) is to be minimised, then minimise abs(2*s1-s) as there is a single unknown s1 here rather 
// than 2 unknowns(s1 and s2) -> 's' is the total sum of array.

// memoization code:
int f(int index, int s1, int s, vector<int> &arr, vector<vector<int>> &dp){
    if(index == 0){
        return min(abs(2*s1-s), abs(2*(s1-arr[0])-s));
    }
    if(dp[index][s1] != -1) return dp[index][s1];
    
    int pick = 0;
    if(arr[index] <= s1) pick = f(index-1, s1-arr[index], s, arr, dp);
    int not_pick = f(index-1, s1, s, arr, dp);
    
    return dp[index][s1] = min(pick, not_pick);
}

int minSubsetSumDifference(vector<int>& arr, int n){
   	int s = 0;
    for(int i=0; i<n; i++) s += arr[i];
    vector<vector<int>> dp(n, vector<int>(s+1, -1));
    return f(n-1, s, s, arr, dp);
}

// tabulation code:
int minSubsetSumDifference(vector<int>& arr, int n){
   	int s = 0;
    for(int i=0; i<n; i++) s += arr[i];
    vector<vector<int>> dp(n, vector<int>(s+1, 0));
    // base case:
    for(int s1 = 0; s1 <= s; s1++) {
        dp[0][s1] = min(abs(2*s1-s), abs(2*(s1-arr[0])-s));
    }
    
    for(int index = 1; index < n; index++){
        for(int s1 = 0; s1 <= s; s1++){
            int pick = 0;
            if(arr[index] <= s1) pick = dp[index-1][s1-arr[index]];
            int not_pick = dp[index-1][s1];
			dp[index][s1] = min(pick, not_pick);
        }
    }
    
    return dp[n-1][s];
}

// space-optimised code:
int minSubsetSumDifference(vector<int>& arr, int n){
	  int s = 0;
    for(int i=0; i<n; i++) s += arr[i];
    vector<int> prev(s+1, 0), curr(s+1, 0);
    // base case:
    for(int s1 = 0; s1 <= s; s1++) {
        prev[s1] = min(abs(2*s1-s), abs(2*(s1-arr[0])-s));
    }
    
    for(int index = 1; index < n; index++){
        for(int s1 = 0; s1 <= s; s1++){
            int pick = 0;
            if(arr[index] <= s1) pick = prev[s1-arr[index]];
            int not_pick = prev[s1];
			curr[s1] = min(pick, not_pick);
        }
        prev = curr;
    }
    
    return prev[s];
}

