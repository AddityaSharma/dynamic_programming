/*
// recursive code:
int f(int n, vector<int> &heights){
    if(n == 0) return 0; 
    if(n == 1) return abs(heights[1] - heights[0]);
    
    int j1 = abs(heights[n-1] - heights[n]) + f(n-1, heights);
    int j2 = abs(heights[n-2] - heights[n]) + f(n-2, heights);
    
    return min(j1, j2);
}

int frogJump(int n, vector<int> &heights){
	return f(n-1, heights);    
}
*/

/*
// memoization code:
int f(int n, vector<int> &heights, vector<int> &dp){
    if(n == 0) return 0; 
    if(n == 1) return abs(heights[1] - heights[0]);
    if(dp[n] != -1) return dp[n];
    
    int j1 = abs(heights[n-1] - heights[n]) + f(n-1, heights, dp);
    int j2 = abs(heights[n-2] - heights[n]) + f(n-2, heights, dp);
    
    return dp[n] = min(j1, j2);
}

int frogJump(int n, vector<int> &heights){
    vector<int> dp(n, -1);
	return f(n-1, heights, dp);    
}
*/

/*
// tabulation code:
int frogJump(int n, vector<int> &heights){
    vector<int> dp(n, 0);
    // base cases : 
    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);
    
    for(int i = 2; i<n; i++){
        int j1 = abs(heights[i-1] - heights[i]) + dp[i-1];
   	 	int j2 = abs(heights[i-2] - heights[i]) + dp[i-2];
        dp[i] = min(j1, j2);
    }
    
	return dp[n-1];    
}
*/

/*
// space-optimised code:
int frogJump(int n, vector<int> &heights){
    // base cases : 
    int prev2 = 0;
    int prev1 = abs(heights[1] - heights[0]);
    
    for(int i = 2; i<n; i++){
        int j1 = abs(heights[i-1] - heights[i]) + prev1;
   	 	int j2 = abs(heights[i-2] - heights[i]) + prev2;
        int curr = min(j1, j2);
        prev2 = prev1;
        prev1 = curr;
    }
    
	return prev1;    
}
*/
