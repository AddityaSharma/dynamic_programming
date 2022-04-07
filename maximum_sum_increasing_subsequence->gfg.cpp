// recursive code:
int f(int ind, int prev_ind, int arr[], int n){
    if(ind == n) return 0;
    
    int sum = f(ind+1, prev_ind, arr, n); // not_take
    if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
        sum = max(sum, (arr[ind] + f(ind+1, ind, arr, n)));
    }
    
    return sum;
}

int maxSumIS(int arr[], int n){
    return f(0, -1, arr, n);
} 


// memoization code:
int f(int ind, int prev_ind, int arr[], int n, vector<vector<int>> &dp){
    if(ind == n) return 0;
    if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];
    
    int sum = f(ind+1, prev_ind, arr, n, dp); // not_take
    if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
        sum = max(sum, (arr[ind] + f(ind+1, ind, arr, n, dp))); // take
    }
    
    return dp[ind][prev_ind+1] = sum;
}

int maxSumIS(int arr[], int n){
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return f(0, -1, arr, n, dp);
}  


// tabulation code:
int maxSumIS(int arr[], int n){
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for(int ind = n-1; ind >= 0; ind--){
        for(int prev_ind = ind-1; prev_ind >= -1; prev_ind--){
            int sum = dp[ind+1][prev_ind+1]; // not_take
       	    if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
       	        sum = max(sum, (arr[ind] + dp[ind+1][ind+1])); // take
       	    }
       	    dp[ind][prev_ind+1] = sum;
        }
    }
    
    return dp[0][-1+1];
}


// space-optimised code:
int maxSumIS(int arr[], int n){
    vector<int> next(n+1, 0), curr(n+1, 0);
    
    for(int ind = n-1; ind >= 0; ind--){
        for(int prev_ind = ind-1; prev_ind >= -1; prev_ind--){
            int sum = next[prev_ind+1]; // not_take
       	    if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
       	        sum = max(sum, (arr[ind] + next[ind+1])); // take
       	    }
       	    curr[prev_ind+1] = sum;
        }
        next = curr;
    }
    
    return next[-1+1];
}


// a but unique way of doing the LIS problems -> takeUforward
// if you know this, you can do this; else not so much intutuive.
int maxSumIS(int arr[], int n){
    int dp[n];
    for(int i = 0; i<n; i++) dp[i] = arr[i];
    
    int max_sum = arr[0];
    for(int i = 1; i<n; i++){
        for(int prev = 0; prev < i; prev++){
            if(arr[prev] < arr[i]){
                dp[i] = max(dp[i], arr[i] + dp[prev]); 
            }
        }
        max_sum = max(max_sum, dp[i]);
    }
    return max_sum;
}
