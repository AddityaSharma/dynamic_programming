// recursive code:
int f(int i,int j, int arr[]){
    if(i == j) return 0;
    
    int min_cost = INT_MAX;
    for(int k = i; k < j; k++){
        int cost = arr[i-1]*arr[k]*arr[j] + f(i, k, arr) + f(k+1, j, arr);
        min_cost = min(cost, min_cost);
    }
    
    return min_cost;

int matrixMultiplication(int N, int arr[]){
    return f(1, N-1, arr);
}

// memoization code:
int f(int i,int j, int arr[], vector<vector<int>> &dp){
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    int min_cost = INT_MAX;
    for(int k = i; k < j; k++){
        int cost = arr[i-1]*arr[k]*arr[j] + f(i, k, arr, dp) + f(k+1, j, arr, dp);
        min_cost = min(cost, min_cost);
    }
    
    return dp[i][j] = min_cost;

int matrixMultiplication(int N, int arr[]){
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return f(1, N-1, arr, dp);
}

// tabulation code:
int matrixMultiplication(int N, int arr[]){
    // base cases are not required to be dealt explicitly.
    vector<vector<int>> dp(N, vector<int>(N, 0));
    
    for(int i = N-1; i > 0; i--){
        for(int j = i+1; j < N; j++){
            int min_cost = INT_MAX;
            for(int k = i; k < j; k++){
                int cost = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                min_cost = min(cost, min_cost);
            }
            dp[i][j] = min_cost;
        }
    }
    
    return dp[1][N-1];
}
