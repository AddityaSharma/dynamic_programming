// recursive code:
int f(int index, int product, vector<int> &arr, int k){
    if(index == 0) return 0;
    
    int take = 0;
    int not_take = f(index-1, product, arr, k);
    if(product * arr[index-1] <= k) take = 1 + f(index-1, product*arr[index-1], arr, k);
    
    return take + not_take;
}

int countSubsequences(vector<int> &arr, int n, int k){
    return f(n, 1, arr, k);
}


// memoization code:
int f(int index, int product, vector<int> &arr, int k, vector<vector<int>> &dp){
    if(index == 0) return 0;
    if(dp[index][product] != -1) return dp[index][product];
    
    int take = 0;
    int not_take = f(index-1, product, arr, k, dp);
    if(product * arr[index-1] <= k) take = 1 + f(index-1, product*arr[index-1], arr, k, dp);
    
    return dp[index][product] = take + not_take;
}

int countSubsequences(vector<int> &arr, int n, int k){
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    return f(n, 1, arr, k, dp);
}


// tabulation code:
int countSubsequences(vector<int> &arr, int n, int k){
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    
    for(int index = 1; index <= n; index++){
        for(int product = 1; product <= k; product++){
            int take = 0;
            int not_take = dp[index-1][product];
            if(product * arr[index-1] <= k) take = 1 + dp[index-1][product*arr[index-1]];
            dp[index][product] = take + not_take;
        }
    }
      
    return dp[n][1];
}


// space-optimised code:
int countSubsequences(vector<int> &arr, int n, int k){
    vector<int> prev(k+1, 0), curr(k+1, 0);
    
    for(int index = 1; index <= n; index++){
        for(int product = 1; product <= k; product++){
            int take = 0;
            int not_take = prev[product];
            if(product * arr[index-1] <= k) take = 1 + prev[product*arr[index-1]];
            curr[product] = take + not_take;
        }
        prev = curr;
    }
      
    return prev[1];
}
